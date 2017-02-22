/* This tutorial will open a 640 x 480 screen,
** load up several images and display them as
** an animation. Pressing escape
** or closing the window will exit the program
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern SDL_Surface *loadImage(char *);
extern void updateScreen(void);
extern void loadAnimation(char *, Animation *);
extern void doAnimation(Animation *);

void delay(unsigned int);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;
	
	/* Start up SDL */
	
	init("Parallel Realities Tutorial 8");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Load up the star animation */
	
	loadAnimation("data/anim/star.dat", &starAnim);
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		getInput();
		
		/* Update the animation frame */
		
		doAnimation(&starAnim);
		
		/* Draw the animation to the screen */
		
		updateScreen();
		
		/* Sleep briefly to stop sucking up all the CPU time */
		
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
