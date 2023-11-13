#include "./headers/maze.h"


/**
 * draw_player - draw player
 * @player: pointer to player struct
 *
 * Return: nothing
*/
void draw_player(SDL_Instance *instance, player *player)
{
	float x1 = player->posX, x2 = player->posX + player->dirX * 5;
	float y1 = player->posY, y2 = player->posY + player->dirY * 5;

	SDL_Rect rect = {player->posX - 3, player->posY - 3, 8, 8};
	SDL_SetRenderDrawColor(instance->renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(instance->renderer, &rect);

	SDL_RenderDrawLineF(instance->renderer, x1, y1, x2, y2);
}


/**
 * detect_collision - detect if player has hit a wall
 * @map: pointer to the 2D map
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 0 if no collision, 1 otherwise
*/
int detect_collision(int **map, int x, int y)
{
	if (map[x][y] > 0)
		return (1);
	return (0);
}

/**
 * update_player_position - listen to key presses and update player location
 * @map: map
 * @player: player
 *
 * Return: Nothing
*/
void update_player_position(int **map, player *player)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	int nextX, nextY;
	float oldposX = player->posX, oldposY = player->posY;
	float olddirX, olddirY, oldplaneX, oldplaneY;


	if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_F])
	{
		/* move forward [press up arrow or key F ] */
		player->posX += player->dirX * MOVE_SPEED;
		player->posY += player->dirY * MOVE_SPEED;
	}
	else if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_B])
	{
		/* move back [press down arrow or key B] */
		player->posX -= player->dirX * MOVE_SPEED;
		player->posY -= player->dirY * MOVE_SPEED;
	}
	else if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_L])
	{
		/* rotate left */

		olddirX = player->dirX;
		player->dirX = (player->dirX * cos(-ROTATION_SPEED) - player->dirY * sin(-ROTATION_SPEED));
		player->dirY  = (olddirX * sin(-ROTATION_SPEED) + player->dirY * cos(-ROTATION_SPEED));

		oldplaneX = player->planeX;
		player->planeX = (player->planeX * cos(-ROTATION_SPEED) - player->planeY * sin(-ROTATION_SPEED));
		player->planeY  = (oldplaneX * sin(-ROTATION_SPEED) + player->planeY * cos(-ROTATION_SPEED));
	}
	else if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_R])
	{
		/* rotate right */
		olddirX = player->dirX;
		player->dirX = (player->dirX * cos(ROTATION_SPEED) - player->dirY * sin(ROTATION_SPEED));
		player->dirY  = (olddirX * sin(ROTATION_SPEED) + player->dirY * cos(ROTATION_SPEED));

		oldplaneX = player->planeX;
		player->planeX = (player->planeX * cos(ROTATION_SPEED) - player->planeY * sin(ROTATION_SPEED));
		player->planeY  = (oldplaneX * sin(ROTATION_SPEED) + player->planeY * cos(ROTATION_SPEED));
	}

	nextX = (int)(player->posX + player->dirX * MOVE_SPEED);
	nextY = (int)(player->posY + player->dirY * MOVE_SPEED);

	if (detect_collision(map, nextX, nextY))
	{
		player->posX = oldposX;
		player->posY = oldposY;
	}
}
