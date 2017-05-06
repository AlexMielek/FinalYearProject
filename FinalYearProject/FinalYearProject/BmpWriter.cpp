/*
* Copyright (c) 2012 Tom Alexander
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*    1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
*
*    2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
*    3. This notice may not be removed or altered from any source
*    distribution.
*/
#include "stdafx.h"
#include "BmpWriter.h"


BmpWriter::BmpWriter()
{
}


BmpWriter::~BmpWriter()
{
}

std::vector<uint8_t> BmpWriter::get_4_bytes(const uint32_t & data)
{
	std::vector<uint8_t> ret;
	uint8_t* tmp = (uint8_t*)&data;
	ret.push_back(tmp[0]);
	ret.push_back(tmp[1]);
	ret.push_back(tmp[2]);
	ret.push_back(tmp[3]);
	return ret;
}
void BmpWriter::insert_4_bytes(std::vector<uint8_t> & dest, const uint32_t & data)
{
	std::vector<uint8_t> separated_data = get_4_bytes(data);
	std::copy(separated_data.begin(), separated_data.end(), back_inserter(dest));
}
std::vector<uint8_t> BmpWriter::get_2_bytes(const uint16_t & data)
{
	std::vector<uint8_t> ret;
	uint8_t* tmp = (uint8_t*)&data;
	ret.push_back(tmp[0]);
	ret.push_back(tmp[1]);
	return ret;
}
void BmpWriter::insert_2_bytes(std::vector<uint8_t> & dest, const uint16_t & data)
{
	std::vector<uint8_t> separated_data = get_2_bytes(data);
	copy(separated_data.begin(), separated_data.end(), back_inserter(dest));
}

size_t BmpWriter::bitmap_encode_rgb(const uint8_t* rgb, int width, int height, uint8_t** output)
{
	std::vector<uint8_t> data;
	data.push_back(0x42); //B
	data.push_back(0x4D); //M
	size_t file_size_offset = data.size();
	insert_4_bytes(data, 0xFFFFFFFF); //File Size, fill later
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	data.push_back(0x00);
	size_t pixel_info_offset_offset = data.size();
	insert_4_bytes(data, 0); //pixel info offset, fill later
	insert_4_bytes(data, 40); //Size of BITMAPINFOHEADER
	insert_4_bytes(data, width);
	insert_4_bytes(data, height);
	insert_2_bytes(data, 1); //Number of color planes
	insert_2_bytes(data, 24); //Bits per pixel
	insert_4_bytes(data, 0); //No compression
	size_t raw_pixel_array_size_offset = data.size();
	insert_4_bytes(data, 0); //size of raw data in pixel array, fill later
	insert_4_bytes(data, 2835); //Horizontal Resolution
	insert_4_bytes(data, 2835); //Vertical Resolution
	insert_4_bytes(data, 0); //Number of colors
	insert_4_bytes(data, 0); //Important colors
	{
		uint32_t data_size = data.size();
		memcpy(&data[pixel_info_offset_offset], &data_size, 4);
	}
	uint32_t size_of_header = data.size();
	for (uint_fast32_t y = 0; y < height; ++y)
	{
		for (uint_fast32_t x = 0; x < width; ++x)
		{
			//Write bottom pixels first since image is flipped
			//Also write pixels in BGR
			data.push_back(rgb[(height - 1 - y)*(width * 3) + x * 3 + 2]);
			data.push_back(rgb[(height - 1 - y)*(width * 3) + x * 3 + 1]);
			data.push_back(rgb[(height - 1 - y)*(width * 3) + x * 3 + 0]);
		}
		while ((data.size() - size_of_header) % 4)
		{
			data.push_back(0);
		}
	}
	{
		uint32_t file_size = data.size();
		memcpy(&data[file_size_offset], &file_size, 4);
	}
	{
		uint32_t pixel_data_size = data.size() - size_of_header;
		memcpy(&data[raw_pixel_array_size_offset], &pixel_data_size, 4);
	}
	*output = new uint8_t[data.size()];
	memcpy(*output, &data[0], data.size());
	return data.size();
}

int BmpWriter::createBmp(int width, int height)
{
	//                      Red              Green
	//                |---------------| |--------------|
	uint8_t data[] = { 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00,
		0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF };
	//                |--------------|  |--------------|
	//                     Blue              Purple
	uint8_t* output;
	size_t output_size = bitmap_encode_rgb(data, width, height, &output);

	std::ofstream file_output;
	file_output.open("output.bmp");
	file_output.write((const char*)output, output_size);
	file_output.close();

	delete[] output;
	return 0;
}
