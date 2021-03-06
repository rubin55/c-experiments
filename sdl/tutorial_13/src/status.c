#include "status.h"

void drawString(char *, int, int, TTF_Font *, int, int);

void doStatusPanel()
{
	message.counter--;
	
	if (message.counter <= 0)
	{
		message.counter = 0;
	}
}

void drawStatusPanel()
{
	SDL_Rect dest;

	dest.x = 0;
	dest.y = SCREEN_HEIGHT - TILE_SIZE;
	dest.w = SCREEN_WIDTH;
	dest.h = TILE_SIZE;
	
	SDL_FillRect(screen, &dest, 0);
	
	if (message.counter > 0)
	{
		drawString(message.text, 0, SCREEN_HEIGHT - TILE_SIZE, font, 1, 0);
	}
}

void setStatusMessage(char *text)
{
	strncpy(message.text, text, MAX_MESSAGE_LENGTH);
	
	message.counter = 120;
}
