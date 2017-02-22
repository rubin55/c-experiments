#include "animation.h"

extern SDL_Surface *loadImage(char *);
extern void drawImage(SDL_Surface *, int, int);

void loadAnimationData(char *filename)
{
	char frameName[255];
	int id, i;
	FILE *fp;
	
	fp = fopen(filename, "rb");
	
	if (fp == NULL)
	{
		printf("Failed to open animation file: %s\n", filename);
		
		exit(1);
	}
	
	while (!feof(fp))
	{
		for (id=0;id<MAX_ANIMATIONS;id++)
		{
			if (animation[id].active == 0)
			{
				animation[id].active = 1;
				
				break;
			}
		}
		
		if (id == MAX_ANIMATIONS)
		{
			printf("More free slots for animation: %s\n", filename);
			
			exit(1);
		}
		
		fscanf(fp, "%s", animation[id].name);
		fscanf(fp, "%d", &animation[id].frameCount);
		
		/* Allocate space for the animation */
		
		animation[id].frame = (SDL_Surface **)malloc(animation[id].frameCount * sizeof(SDL_Surface *));
		
		if (animation[id].frame == NULL)
		{
			printf("Ran out of memory when creating the animation for %s\n", animation[id].name);
			
			exit(1);
		}
		
		/* Allocate space for the frame timer */
		
		animation[id].frameTimer = (int *)malloc(animation[id].frameCount * sizeof(int));
		
		if (animation[id].frameTimer == NULL)
		{
			printf("Ran out of memory when creating the animation for %s\n", animation[id].name);
			
			exit(1);
		}
		
		/* Now load up each frame */
		
		for (i=0;i<animation[id].frameCount;i++)
		{
			fscanf(fp, "%s", frameName);
			
			animation[id].frame[i] = loadImage(frameName);
			
			if (animation[id].frame[i] == NULL)
			{
				printf("Failed to load animation frame %s\n", frameName);
				
				exit(1);
			}
			
			fscanf(fp, "%d", &animation[id].frameTimer[i]);
		}
	}
}

void freeAnimation(Animation *anim)
{
	int i;
	
	/* Loop through each of the frames and free it */

	if (anim->frame != NULL)
	{
		for (i=0;i<anim->frameCount;i++)
		{
			if (anim->frame[i] != NULL)
			{
				SDL_FreeSurface(anim->frame[i]);
			}
		}
		
		free(anim->frame);
	}
	
	if (anim->frameTimer != NULL)
	{
		free(anim->frameTimer);
	}
	
	anim->active = 0;
}

void freeAnimations()
{
	int i;
	
	for (i=0;i<MAX_ANIMATIONS;i++)
	{
		freeAnimation(&animation[i]);
	}
}

void drawAnimation(Animation *anim, int index, int x, int y)
{
	drawImage(anim->frame[index], x, y);
}

void setAnimation(char *name, Entity *entity)
{
	int i;
	
	for (i=0;i<MAX_ANIMATIONS;i++)
	{
		/* Loop through all the animations and find the one that matches the name */
		
		if (strcmp(name, animation[i].name) == 0)
		{
			/* Set the animation and the frameTimer to 0 */
			
			entity->currentAnim = &animation[i];
			entity->currentFrame = 0;
			entity->frameTimer = entity->currentAnim->frameTimer[entity->currentFrame];
			
			return;
		}
	}
	
	/* If the animation couldn't be found, then exit */
	
	printf("Could not find animation %s\n", name);
	
	exit(1);
}
