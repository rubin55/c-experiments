#include "init.h"

extern void freeSprites(void);
extern void freeSounds(void);

void init(char *title)
{
	int joystickCount, buttonCount;
	
	/* Initialise SDL Video and Audio */
	
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());
		
		exit(1);
	}
	
	/* Open a screen */
	
	game.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);
	
	if (game.screen == NULL)
	{
		printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

		exit(1);
	}
	
	/* Set the audio rate to 22050, 16 bit stereo, 2 channels and a 4096 byte buffer */
	
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
	{
		printf("Could not open audio: %s\n", Mix_GetError());
		
		exit(1);
	}
	
	/* Set the screen title */
	
	SDL_WM_SetCaption(title, NULL);
	
	/* Open the joystick */
	
	joystickCount = SDL_NumJoysticks();
	
	if (joystickCount == 0)
	{
		/* Exit if you couldn't find one, because this is point of the tutorial */
		
		printf("Could not find any joysticks!\n");
		
		exit(1);
	}
	
	printf("Found %d joystick(s). Opening Joystick #0: %s\n", joystickCount, SDL_JoystickName(0));

	game.joystick = SDL_JoystickOpen(0);

	buttonCount = SDL_JoystickNumButtons(game.joystick);

	printf("Joystick has %d buttons\n", buttonCount);

	printf("Joystick has %d axes\n", SDL_JoystickNumAxes(game.joystick));
}

void cleanup()
{
	/* Free the sprites */
	
	freeSprites();
	
	/* Free the sounds */
	
	freeSounds();
	
	/* Close the mixer */
	
	Mix_CloseAudio();
	
	/* Close the joystick */

	if (game.joystick != NULL)
	{
		SDL_JoystickClose(game.joystick);
	}
	
	/* Shut down SDL */
	
	SDL_Quit();
}
