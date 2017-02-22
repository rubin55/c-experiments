#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define MAX_ENTITIES 20
#define MAX_RELOAD_TIME 20

#define PLAYER_SPEED 3
#define BULLET_SPEED 10

#define DEAD_ZONE 3200

enum
{
	PLAYER_SPRITE,
 	BULLET_SPRITE,
	MAX_SPRITES
};

enum
{
	BULLET_SOUND,
 	MAX_SOUNDS
};
