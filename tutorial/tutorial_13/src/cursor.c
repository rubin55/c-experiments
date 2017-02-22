#include "cursor.h"

extern void drawImage(SDL_Surface *, int, int);
extern void loadMap(char *);
extern void saveMap(void);
extern void setStatusMessage(char *);

void doCursor()
{
	cursor.x = input.mouseX;
	cursor.y = input.mouseY;
	
	if (cursor.y >= SCREEN_HEIGHT - TILE_SIZE)
	{
		cursor.y = SCREEN_HEIGHT - TILE_SIZE * 2;
	}

	if (input.left == 1)
	{
		map.startX -= TILE_SIZE;

		if (map.startX < 0)
		{
			map.startX = 0;
		}
	}
	
	else if (input.right == 1)
	{
		map.startX += TILE_SIZE;

		if (map.startX + SCREEN_WIDTH >= map.maxX)
		{
			map.startX = map.maxX - SCREEN_WIDTH;
		}
	}
	
	if (input.up == 1)
	{
		map.startY -= TILE_SIZE;

		if (map.startY < 0)
		{
			map.startY = 0;
		}
	}
	
	else if (input.down == 1)
	{
		map.startY += TILE_SIZE;
		
		if (map.startY + SCREEN_HEIGHT >= map.maxY)
		{
			map.startY = map.maxY - SCREEN_HEIGHT;
		}
	}
	
	if (input.add == 1)
	{
		map.tile[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = cursor.tileID;
	}
	
	else if (input.remove == 1)
	{
		map.tile[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = BLANK_TILE;
	}
	
	if (input.previous == 1)
	{
		do
		{
			cursor.tileID--;
			
			if (cursor.tileID < 0)
			{
				cursor.tileID = MAX_TILES - 1;
			}
		}
		
		while (mapImages[cursor.tileID] == NULL);
		
		input.previous = 0;
	}
	
	if (input.next == 1)
	{
		do
		{
			cursor.tileID++;
			
			if (cursor.tileID >= MAX_TILES)
			{
				cursor.tileID = 0;
			}
		}
		
		while (mapImages[cursor.tileID] == NULL);
		
		input.next = 0;
	}
	
	if (input.save == 1)
	{
		saveMap();
		
		setStatusMessage("Saved OK");
		
		input.save = 0;
	}
	
	if (input.load == 1)
	{
		loadMap(map.filename);
		
		setStatusMessage("Loaded OK");
		
		input.load = 0;
	}
	
	if (input.left == 1 || input.right == 1 || input.up == 1 || input.down == 1)
	{
		SDL_Delay(30);
	}
}

void drawCursor()
{
	drawImage(mapImages[cursor.tileID], cursor.x, cursor.y);
}
