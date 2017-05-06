#pragma once
#include <vector>
#include <cstring>
#include <cinttypes>
#include <iostream>
#include <iterator>
#include <fstream>

class BmpWriter
{
public:
	BmpWriter();
	~BmpWriter();

	int createBmp(int width, int height);

private:
	std::vector<uint8_t> get_4_bytes(const uint32_t & data);

	void insert_4_bytes(std::vector<uint8_t> & dest, const uint32_t & data);

	std::vector<uint8_t> get_2_bytes(const uint16_t & data);

	void insert_2_bytes(std::vector<uint8_t> & dest, const uint16_t & data);

	size_t bitmap_encode_rgb(const std::vector<uint8_t> rgb, int width, int height, uint8_t** output);
};

