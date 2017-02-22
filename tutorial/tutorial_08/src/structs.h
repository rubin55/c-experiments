#include "defs.h"

typedef struct Animation
{
	int frameCount, frameIndex, counter;
	SDL_Surface **frame;
} Animation;
