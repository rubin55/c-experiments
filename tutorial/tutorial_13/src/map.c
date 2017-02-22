#include "map.h"

extern SDL_Surface *loadImage(char *);
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
	
	map.maxX = map.maxY = 0;

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fscanf(fp, "%d", &map.tile[y][x]);
			
			if (map.tile[y][x] != BLANK_TILE)
			{
				if (x > map.maxX)
				{
					map.maxX = x;
				}
				
				if (y > map.maxY)
				{
					map.maxY = y;
				}
			}
		}
	}
	
	map.maxX++;
	map.maxY++;
	
	/* Set the start coordinates */
	
	map.startX = map.startY = 0;
	
	/* Set the maximum scroll position of the map */
	
	map.maxX = MAX_MAP_X * TILE_SIZE;
	map.maxY = MAX_MAP_Y * TILE_SIZE;
	
	/* Set the filename */
	
	map.filename = name;

	/* Close the file afterwards */

	fclose(fp);
}

void saveMap()
{
	int x, y;
	FILE *fp;

	fp = fopen(map.filename, "wb");

	/* If we can't open the map then exit */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", map.filename);

		exit(1);
	}

	/* Write the data from the file into the map */

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fprintf(fp, "%d ", map.tile[y][x]);
		}
		
		fprintf(fp, "\n");
	}

	/* Close the file afterwards */

	fclose(fp);
}

void loadMapTiles()
{
	int i;
	char filename[40];
	FILE *fp;
	
	for (i=0;i<MAX_TILES;i++)
	{
		sprintf(filename, "gfx/map/%d.png", i);
		
		fp = fopen(filename, "rb");
		
		if (fp == NULL)
		{
			continue;
		}
		
		fclose(fp);
		
		mapImages[i] = loadImage(filename);
		
		if (mapImages[i] == NULL)
		{
			exit(1);
		}
	}
}

void freeMapTiles()
{
	int i;
	
	for (i=0;i<MAX_TILES;i++)
	{
		if (mapImages[i] != NULL)
		{
			SDL_FreeSurface(mapImages[i]);
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
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE) - TILE_SIZE;
	
	/* Draw the background */
	
	drawImage(map.background, 0, 0);

	/* Draw the map starting at the startX and startY */
	
	for (y=y1;y<y2;y+=TILE_SIZE)
	{
		mapX = map.startX / TILE_SIZE;
		
		for (x=x1;x<x2;x+=TILE_SIZE)
		{
			if (map.tile[mapY][mapX] != BLANK_TILE)
			{
				drawImage(mapImages[map.tile[mapY][mapX]], x, y);
			}
			
			mapX++;
		}
		
		mapY++;
	}
}

