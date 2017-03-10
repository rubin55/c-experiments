#include "defs.h"

typedef struct Animation
{
	char name[50];
	int frameCount, active;
	int *frameTimer;
	SDL_Surface **frame;
} Animation;

typedef struct Input
{
	int left, right, up, down, jump;
} Input;

typedef struct Entity
{
	int active, w, h, onGround;
	int thinkTime, face, state;
	int currentFrame, frameTimer;
	float x, y, dirX, dirY;
	Animation *currentAnim;
	void (*action)(void);
	void (*draw)(void);
} Entity;
