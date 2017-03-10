#include "player.h"

extern void drawAnimation(Animation *, int, int, int);
extern void loadAnimationData(char *);
extern void setAnimation(char *, Entity *);

void loadPlayer()
{
	loadAnimationData("data/anim/player.dat");
}

void initPlayer()
{
	player.x = player.y = 0;
	player.dirX = player.dirY = 0;
	
	player.thinkTime = 0;
	
	player.face = RIGHT;
	
	setAnimation("PLAYER_STAND_RIGHT", &player);
}

void doPlayer()
{
	player.dirX = 0;

	/* Gravity always pulls the player down */

	player.dirY += GRAVITY_SPEED;
	
	if (player.dirY >= MAX_FALL_SPEED)
	{
		player.dirY = MAX_FALL_SPEED;
	}
	
	if (input.left == 1)
	{
		player.face = LEFT;
	}
	
	else if (input.right == 1)
	{
		player.face = RIGHT;
	}
	
	if (input.down == 1 && player.onGround == 1)
	{
		if (player.face == RIGHT && player.state != CROUCH_RIGHT)
		{
			player.state = CROUCH_RIGHT;
			
			setAnimation("PLAYER_CROUCH_RIGHT", &player);
		}
		
		else if (player.face == LEFT && player.state != CROUCH_LEFT)
		{
			player.state = CROUCH_LEFT;
			
			setAnimation("PLAYER_CROUCH_LEFT", &player);
		}
	}
	
	if (input.left == 1 && input.down == 0)
	{
		player.dirX -= PLAYER_SPEED;
		
		if (player.state != WALK_LEFT)
		{
			player.state = WALK_LEFT;
			
			setAnimation("PLAYER_WALK_LEFT", &player);
		}
	}
	
	else if (input.right == 1 && input.down == 0)
	{
		player.dirX += PLAYER_SPEED;
		
		if (player.state != WALK_RIGHT)
		{
			player.state = WALK_RIGHT;
			
			setAnimation("PLAYER_WALK_RIGHT", &player);
		}
	}
	
	else if (input.left == 0 && input.right == 0 && input.down == 0)
	{
		if (player.face == RIGHT && player.state != STAND_RIGHT)
		{
			player.state = STAND_RIGHT;
			
			setAnimation("PLAYER_STAND_RIGHT", &player);
		}
		
		else if (player.face == LEFT && player.state != STAND_LEFT)
		{
			player.state = STAND_LEFT;
			
			setAnimation("PLAYER_STAND_LEFT", &player);
		}
	}
	
	if (input.jump == 1 && player.onGround == 1)
	{
		if (player.face == RIGHT && player.state != STAND_RIGHT)
		{
			player.state = STAND_RIGHT;
			
			setAnimation("PLAYER_STAND_RIGHT", &player);
		}
		
		else if (player.face == LEFT && player.state != STAND_LEFT)
		{
			player.state = STAND_LEFT;
			
			setAnimation("PLAYER_STAND_LEFT", &player);
		}
		
		player.dirY = -JUMP_HEIGHT;
		
		input.jump = 0;
	}
	
	player.onGround = 0;
	
	player.x += player.dirX;
	player.y += player.dirY;
	
	if (player.x < 0)
	{
		player.x = 0;
	}
	
	else if (player.x + player.w >= SCREEN_WIDTH)
	{
		player.x = SCREEN_WIDTH - player.w - 1;
	}
	
	if (player.y + player.h >= (SCREEN_HEIGHT / 2))
	{
		player.onGround = 1;
		
		player.y = (SCREEN_HEIGHT / 2) - player.h;
	}
}

void drawPlayer()
{
	player.frameTimer--;
	
	if (player.frameTimer <= 0)
	{
		player.currentFrame++;
		
		if (player.currentFrame >= player.currentAnim->frameCount)
		{
			player.currentFrame = 0;
		}
		
		player.frameTimer = player.currentAnim->frameTimer[player.currentFrame];
		
		player.w = player.currentAnim->frame[player.currentFrame]->w;
		player.h = player.currentAnim->frame[player.currentFrame]->h;
	}
	
	drawAnimation(player.currentAnim, player.currentFrame, player.x, player.y);
}
