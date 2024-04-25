#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

class ImageLoader {
public:
	static unsigned char* loadImage(const char* path, int* img_width, int* img_height, int* img_channels);
};