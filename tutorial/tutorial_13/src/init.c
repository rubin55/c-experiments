#include "init.h"

extern void freeMapTiles(void);
extern void closeFont(TTF_Font *);

void init(char *title)
{
	/* Initialise SDL Video and Audio */
	
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		
		exit(1);
	}
	
	/* Initialise SDL_TTF */
	
	if (TTF_Init() < 0)
	{
		printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

		exit(1);
	}
	
	/* Open a screen */
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	
	if (screen == NULL)
	{
		printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

		exit(1);
	}
	
	/* Set the screen title */
	
	SDL_WM_SetCaption(title, NULL);
}

void cleanup()
{
	/* Free the map tiles */
	
	freeMapTiles();
	
	/* Free the background image */
	
	if (map.background != NULL)
	{
		SDL_FreeSurface(map.background);
	}
	
	/* Close the font */
	
	closeFont(font);
	
	/* Close SDL_TTF */
	
	TTF_Quit();
	
	/* Shut down SDL */
	
	SDL_Quit();
}
