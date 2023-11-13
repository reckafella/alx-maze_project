#include "./headers/maze.h"


/**
 * draw_player - draw player
 * @player: pointer to player struct
 *
 * Return: nothing
*/
void draw_player(SDL_Instance *instance, player *player)
{
	float x1 = player->playerX, x2 = player->playerX + player->playerDirX * 5;
	float y1 = player->playerY, y2 = player->playerY + player->playerDirY * 5;

	SDL_Rect rect = {player->playerX - 3, player->playerY - 3, 4, 4};
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
	float oldPlayerX = player->playerX, oldPlayerY = player->playerY;
	float oldPlayerDirX, oldPlayerDirY, oldPlayerPlaneX, oldPlayerPlaneY;


	if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_F])
	{
		/* move forward [press up arrow or key F ] */
		player->playerX += player->playerDirX * MOVE_SPEED;
		player->playerY += player->playerDirY * MOVE_SPEED;
	}
	else if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_B])
	{
		/* move back [press down arrow or key B] */
		player->playerX -= player->playerDirX * MOVE_SPEED;
		player->playerY -= player->playerDirY * MOVE_SPEED;
	}
	else if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_L])
	{
		/* rotate left */

		oldPlayerDirX = player->playerDirX;
		player->playerDirX = (player->playerDirX * cos(-ROTATION_SPEED) - player->playerDirY * sin(-ROTATION_SPEED));
		player->playerDirY  = (oldPlayerDirX * sin(-ROTATION_SPEED) + player->playerDirY * cos(-ROTATION_SPEED));

		oldPlayerPlaneX = player->playerPlaneX;
		player->playerPlaneX = (player->playerPlaneX * cos(-ROTATION_SPEED) - player->playerPlaneY * sin(-ROTATION_SPEED));
		player->playerPlaneY  = (oldPlayerPlaneX * sin(-ROTATION_SPEED) + player->playerPlaneY * cos(-ROTATION_SPEED));
	}
	else if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_R])
	{
		/* rotate right */
		oldPlayerDirX = player->playerDirX;
		player->playerDirX = (player->playerDirX * cos(ROTATION_SPEED) - player->playerDirY * sin(ROTATION_SPEED));
		player->playerDirY  = (oldPlayerDirX * sin(ROTATION_SPEED) + player->playerDirY * cos(ROTATION_SPEED));

		oldPlayerPlaneX = player->playerPlaneX;
		player->playerPlaneX = (player->playerPlaneX * cos(ROTATION_SPEED) - player->playerPlaneY * sin(ROTATION_SPEED));
		player->playerPlaneY  = (oldPlayerPlaneX * sin(ROTATION_SPEED) + player->playerPlaneY * cos(ROTATION_SPEED));
	}

	nextX = (int)(player->playerX + player->playerDirX * MOVE_SPEED);
	nextY = (int)(player->playerY + player->playerDirY * MOVE_SPEED);

	if (detect_collision(map, nextX, nextY))
	{
		player->playerX = oldPlayerX;
		player->playerY = oldPlayerY;
	}
}
