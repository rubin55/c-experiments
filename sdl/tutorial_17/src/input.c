#include "input.h"

void getInput()
{
	SDL_Event event;
	
	/* Loop through waiting messages and process them */
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			/*
			** Closing the Window or pressing Escape will exit the program
			** Pressing the arrow keys will move the player
			** Pressing space will fire a bullet
			*/
			
			case SDL_QUIT:
				exit(0);
				break;
			
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
						break;
					
					default:
					break;
				}
				break;
				
			case SDL_JOYBUTTONDOWN:
				switch (event.jbutton.button)
				{
					case 0:
						input.fire = 1;
					break;
				}
				break;
				
			case SDL_JOYBUTTONUP:
				switch (event.jbutton.button)
				{
					case 0:
						input.fire = 0;
					break;
				}
				break;
				
			case SDL_JOYAXISMOTION:
				/* Horizontal movement */
				
				if (event.jaxis.axis == 0)
				{
					if (event.jaxis.value < -DEAD_ZONE)
					{
						input.left = 1;
					}

					else if (event.jaxis.value > DEAD_ZONE)
					{
						input.right = 1;
					}

					else
					{
						input.left = 0;
						input.right = 0;
					}
				}
				
				/* Vertical movement */
				
				if (event.jaxis.axis == 1)
				{
					if (event.jaxis.value < -DEAD_ZONE)
					{
						input.up = 1;
					}

					else if (event.jaxis.value > DEAD_ZONE)
					{
						input.down = 1;
					}

					else
					{
						input.up = 0;
						input.down = 0;
					}
				}
				break;
		}
	}
}
