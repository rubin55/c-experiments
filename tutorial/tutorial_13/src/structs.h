#include "defs.h"

typedef struct Map
{
	char *filename;
	int startX, startY;
	int maxX, maxY;
	int tile[MAX_MAP_Y][MAX_MAP_X];
	SDL_Surface *background;
} Map;

typedef struct Input
{
	int left, right, up, down, add, remove;
	int previous, next, load, save;
	int mouseX, mouseY;
} Input;

typedef struct Cursor
{
	int x, y, tileID;
} Cursor;

typedef struct Message
{
	char text[MAX_MESSAGE_LENGTH];
	int counter;
} Message;
