#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define GRAVITY_SPEED 0.4

#define MAX_FALL_SPEED 16

#define JUMP_HEIGHT 7

#define PLAYER_SPEED 2

#define TRANS_R 127
#define TRANS_G 0
#define TRANS_B 127

#define MAX_ANIMATIONS 255

enum
{
	LEFT,
	RIGHT
};

enum
{
	STAND_LEFT,
	STAND_RIGHT,
	WALK_LEFT,
	WALK_RIGHT,
	CROUCH_LEFT,
	CROUCH_RIGHT
};
