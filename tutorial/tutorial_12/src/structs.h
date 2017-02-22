#include "defs.h"

typedef struct Map
{
	int startX, startY;
	int maxX, maxY;
	int tile[MAX_MAP_Y][MAX_MAP_X];
} Map;

typedef struct Input
{
	int left, right, up, down;
} Input;
