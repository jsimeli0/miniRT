#include <limits.h>
#include <stdint.h>
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