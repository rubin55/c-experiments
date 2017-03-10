#include "map.h"

extern void drawImage(SDL_Surface *, int, int);

void loadMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");

	/* If we can't open the map then exit */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}

	/* Read the data from the file into the map */

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fscanf(fp, "%d", &map.tile[y][x]);
		}
	}
	
	/* Set the start coordinates */
	
	map.startX = map.startY = 0;
	
	/* Set the maximum scroll position of the map */
	
	map.maxX = MAX_MAP_X * TILE_SIZE;
	map.maxY = MAX_MAP_Y * TILE_SIZE;

	/* Close the file afterwards */

	fclose(fp);
}

void doMap()
{
	if (input.left == 1)
	{
		map.startX -= SCROLL_SPEED;
		
		if (map.startX < 0)
		{
			map.startX = 0;
		}
	}
	
	else if (input.right == 1)
	{
		map.startX += SCROLL_SPEED;
		
		if (map.startX + SCREEN_WIDTH >= map.maxX)
		{
			map.startX = map.maxX - SCREEN_WIDTH;
		}
	}
	
	if (input.up == 1)
	{
		map.startY -= SCROLL_SPEED;
		
		if (map.startY < 0)
		{
			map.startY = 0;
		}
	}
	
	else if (input.down == 1)
	{
		map.startY += SCROLL_SPEED;
		
		if (map.startY + SCREEN_HEIGHT >= map.maxY)
		{
			map.startY = map.maxY - SCREEN_HEIGHT;
		}
	}
}

void drawMap()
{
	int x, y, mapX, x1, x2, mapY, y1, y2;

	mapX = map.startX / TILE_SIZE;
	x1 = (map.startX % TILE_SIZE) * -1;
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
	
	mapY = map.startY / TILE_SIZE;
	y1 = (map.startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
	
	/* Draw the background */
	
	drawImage(backgroundImage, 0, 0);

	/* Draw the map starting at the startX and startY */
	
	for (y=y1;y<y2;y+=TILE_SIZE)
	{
		mapX = map.startX / TILE_SIZE;
		
		for (x=x1;x<x2;x+=TILE_SIZE)
		{
			if (map.tile[mapY][mapX] != 0)
			{
				drawImage(brickImage, x, y);
			}
			
			mapX++;
		}
		
		mapY++;
	}
}
