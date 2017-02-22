/* This tutorial will open a 640 x 480 screen,
** and display a simple moving starfield.
** Pressing escape
** or closing the window will exit the program
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void doStars(void);
extern void drawStars(void);
extern void resetStars(void);

void delay(unsigned int);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;
	
	/* Start up SDL */
	
	init("Parallel Realities Tutorial 9");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Initialise the stars */
	
	resetStars();
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		getInput();
		
		/* Update the stars */
		
		doStars();
		
		/* Blank the screen */
		
		SDL_FillRect(screen, NULL, 0);
		
		/* Draw the stars */
		
		drawStars();
		
		/* Swap the buffers */
		
		SDL_Flip(screen);
		
		/* Sleep briefly to stop sucking up all the CPU time */
		
		SDL_Delay(1);
		
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
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
