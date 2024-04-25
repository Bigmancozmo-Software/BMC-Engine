#include "ImageLoader.h"

unsigned char* ImageLoader::loadImage(const char* path, int* img_width, int* img_height, int* img_channels)
{
	unsigned char* image = stbi_load("path_to_your_icon.png", img_width, img_height, img_channels, 4); // 4 = rgba
	return image;
}