#include <limits.h>
#include <stdint.h>

#include "geometry.h"

#define INFINITY INT_MAX

int	i;
int	j;
int	k;

i = 0;
j = 0;
k = 0;

void castPrimary(uint32_t height, uint32_t width, uint32_t numObjects)
{
	while (j < height) 
	{ 
		while (i < width)
		{
			// generate primary ray (this is what this lesson is about)
			// ... 
			float tnear = INFINITY; // closest intersection, set to INFINITY to start with 
			for (int k = 0; k < numObjects; ++k) 
			{ 
				float t = INFINITY; // intersection to the current object if any 
				if objects[k]->intersect(primaryRay, tnear) && t < tnear) 
				{
					tnear = t;
					framebuffer= objects[k].color;
				}
			}
			++i;
		}
		++j;
	}
}

void render( 
	const Options &options, 
	const std::vector> &objects, 
	const std::vector> &lights) 
{
	float	cameraToWorld[4][4];
	Vec3f *framebuffer = new Vec3f[options.width * options.height]; 
	Vec3f *pix = framebuffer; 
	float scale = tan(deg2rad(options.fov * 0.5)); 
	float imageAspectRatio = options.width / (float)options.height; 
	Vec3f orig; 
	cameraToWorld.multVecMatrix(Vec3f(0), orig); 
	for (uint32_t j = 0; j < options.height; ++j) { 
		for (uint32_t i = 0; i < options.width; ++i) { 
			float x = (2 * (i + 0.5) / (float)options.width - 1) * imageAspectRatio * scale; 
			float y = (1 - 2 * (j + 0.5) / (float)options.height) * scale; 
			Vec3f dir; 
			cameraToWorld.multDirMatrix(Vec3f(x, y, -1), dir); 
			dir.normalize(); 
			*(pix++) = castRay(orig, dir, objects, lights, options, 0); 
		} 
	} 
 
	// Save result to a PPM image (keep these flags if you compile under Windows)
	std::ofstream ofs("./out.ppm", std::ios::out | std::ios::binary); 
	ofs << "P6\n" << options.width << " " << options.height << "\n255\n"; 
	for (uint32_t i = 0; i < options.height * options.width; ++i) { 
		char r = (char)(255 * clamp(0, 1, framebuffer[i].x)); 
		char g = (char)(255 * clamp(0, 1, framebuffer[i].y)); 
		char b = (char)(255 * clamp(0, 1, framebuffer[i].z)); 
		ofs << r << g << b; 
	} 
 
	ofs.close(); 
 
	delete [] framebuffer; 
}

// void render( 
// 	const Options &options, 
// 	const std::vector> &objects, 
// 	const std::vector> &lights) 
// {
// 	Matrix44f cameraToWorld; 
// 	Vec3f *framebuffer = new Vec3f[options.width * options.height]; 
// 	Vec3f *pix = framebuffer; 
// 	float scale = tan(deg2rad(options.fov * 0.5)); 
// 	float imageAspectRatio = options.width / (float)options.height; 
// 	Vec3f orig; 
// 	cameraToWorld.multVecMatrix(Vec3f(0), orig); 
// 	for (uint32_t j = 0; j < options.height; ++j) { 
// 		for (uint32_t i = 0; i < options.width; ++i) { 
// 			float x = (2 * (i + 0.5) / (float)options.width - 1) * imageAspectRatio * scale; 
// 			float y = (1 - 2 * (j + 0.5) / (float)options.height) * scale; 
// 			Vec3f dir; 
// 			cameraToWorld.multDirMatrix(Vec3f(x, y, -1), dir); 
// 			dir.normalize(); 
// 			*(pix++) = castRay(orig, dir, objects, lights, options, 0); 
// 		} 
// 	} 
 
// 	// Save result to a PPM image (keep these flags if you compile under Windows)
// 	std::ofstream ofs("./out.ppm", std::ios::out | std::ios::binary); 
// 	ofs << "P6\n" << options.width << " " << options.height << "\n255\n"; 
// 	for (uint32_t i = 0; i < options.height * options.width; ++i) { 
// 		char r = (char)(255 * clamp(0, 1, framebuffer[i].x)); 
// 		char g = (char)(255 * clamp(0, 1, framebuffer[i].y)); 
// 		char b = (char)(255 * clamp(0, 1, framebuffer[i].z)); 
// 		ofs << r << g << b; 
// 	} 
 
// 	ofs.close(); 
 
// 	delete [] framebuffer; 
// }