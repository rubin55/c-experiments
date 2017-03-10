/* This tutorial demonstrates tile based collision
** detection. Pressing the arrow keys
** will sprite around the screen. Pressing escape
** or closing the window will exit the program
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void loadMap(char *);
extern SDL_Surface *loadImage(char *);
extern void draw(void);
extern void loadMapTiles(void);
extern void doCursor(void);
extern void delay(unsigned int);
extern TTF_Font *loadFont(char *, int);
extern void doStatusPanel(void);

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;
	
	/* Start up SDL */
	
	init("Parallel Realities Tutorial 13");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	/* Load the map tiles */
	
	loadMapTiles();
	
	/* Load the font */
	
	font = loadFont("font/blackWolf.ttf", 16);
	
	/* Load the background image */
	
	map.background = loadImage("gfx/background.png");
	
	/* If we get back a NULL image, just exit */
	
	if (map.background == NULL)
	{
		exit(1);
	}
	
	/* Load the map */
	
	loadMap("data/maps/map01.dat");
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		/* Get the input */
	
		getInput();
		
		/* Do the cursor */
		
		doCursor();
		
		/* Do the status panel */
		
		doStatusPanel();
		
		/* Draw the map */
		
		draw();
		
		/* Sleep briefly to stop sucking up all the CPU time */
		
		delay(frameLimit);
		
		frameLimit = SDL_GetTicks() + 16;
	}
	
	/* Exit the program */
	
	exit(0);
}
