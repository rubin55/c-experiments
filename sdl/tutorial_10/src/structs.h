#include "defs.h"

typedef struct Animation
{
	int frameCount;
	SDL_Surface **frame;
} Animation;

typedef struct Game
{
	int score;
	SDL_Surface *screen;
	TTF_Font *font;
} Game;

typedef struct Sprite
{
	SDL_Surface *image;
} Sprite;

typedef struct Sound
{
	Mix_Chunk *effect;
} Sound;

typedef struct Entity
{
	int active, speed;
	int x, y, w, h;
	int currentFrame, animID, frameTimer;
	SDL_Surface *sprite;
	void (*action)(void);
	void (*draw)(void);
} Entity;

typedef struct Control
{
	int up, down, left, right;
} Control;

typedef struct Star
{
	int x, y, speed;
} Star;
