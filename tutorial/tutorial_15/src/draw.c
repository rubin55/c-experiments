#include "draw.h"

extern void drawPlayer(void);

void draw()
{
	SDL_Rect rect;
	
	/* Clear the screen */
	
	SDL_FillRect(screen, NULL, 0);
	
	/* Draw a fake floor */
	
	rect.x = 0;
	rect.y = SCREEN_HEIGHT / 2;
	rect.w = SCREEN_WIDTH;
	rect.h = 5;
	
	SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, TRANS_R, TRANS_G, TRANS_B));

	/* Draw the player */
	
	drawPlayer();

	/* Swap the buffers */

	SDL_Flip(screen);
	
	/* Sleep briefly */
	
	SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}
	
	if (frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}
	
	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}
