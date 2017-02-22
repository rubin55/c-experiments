/* This tutorial demonstrates tile based collision
** detection. Pressing the arrow keys
** will sprite around the screen. Pressing escape
** or closing the window will exit the program
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void doPlayer(void);
extern void loadPlayer(void);
extern void delay(unsigned int);
extern void initPlayer(void);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;
	
	/* Start up SDL */
	
	init("Parallel Realities Tutorial 15");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Load the player */
	
	loadPlayer();
	
	initPlayer();
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		getInput();
		
		/* Do the player */
		
		doPlayer();
		
		/* Draw the map */
		
		draw();
		
		/* Sleep briefly to stop sucking up all the CPU time */
		
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
}
