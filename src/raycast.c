#include "./headers/maze.h"

/**
 * cast_ray - cast a ray
 * @instance: SDL Instance
 * @map: double pointer to map
 * @x: current x value
 * @player: pointer to the player
 * @textured: boolean value
*/
void cast_ray(SDL_Instance *instance, int **map, int x,	player *player)
{
	float sideDistX, sideDistY, perpWallDist;
	float deltaDistX, deltaDistY, rayDirX, rayDirY;
	int stepX, stepY, mapX, mapY, hit = 0, side = 0, line_height;
	int draw_start, draw_end;

	calcRayDir(x, &rayDirX, &rayDirY, player);

	mapX = (int)player->posX, mapY = (int)player->posY;
	deltaDistX = fabs(1 / rayDirX), deltaDistY = fabs(1 / rayDirY);

	stepSideDist(&rayDirX, &rayDirY, &stepX, &stepY, &mapX, &mapY, player,
			&sideDistX, &sideDistY, &deltaDistX, &deltaDistY);

	handle_hits(map, &hit, &sideDistX, &sideDistY, &mapX, &mapY, &side,
			&stepX, &stepY, &deltaDistX, &deltaDistY);

	if (side == 0)
		perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
	else
		perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;
	
	player->posZ = perpWallDist;

	renderFloorCeiling(instance, player, x);
	draw_wall_slice(instance, player, perpWallDist, side, x);
}
/**
 * calcRayDir - calculate ray direction
 * @x: x value
 * @rayDirX: ray direction on x coordinate
 * @rayDirY: ray direction on y coordinate
 * @player: player
*/
void calcRayDir(int x, float *rayDirX, float *rayDirY, player *player)
{
	/* calculate raylength and direction */
	float cameraX = (2 * x / (float)SCREEN_HEIGHT - 1);
	*rayDirX = player->dirX + player->planeX * cameraX;
	*rayDirY = player->dirY + player->planeY * cameraX;
}


/**
 * render_scene - render scene
 * @instance: pointer to the SDL instance
 * @map: pointer to the 2D map
 * @player: player's current x,y coordinates
 * @textured: pointer to integer value indicating whether to create textures
 * or not
*/
void render_scene(SDL_Instance *instance, int **map,
		player *player)
{
	int x;

	SDL_SetRenderDrawColor(instance->renderer, 53, 145, 69, 255);
	SDL_RenderClear(instance->renderer);

	/* untextured */
	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		/* renderFloorCeiling(instance, player, x); */
		cast_ray(instance, map, x, player);
	}
	draw_player(instance, player);

	SDL_RenderPresent(instance->renderer);
}

/**
 * stepSideDist - set distance to draw ray based on ray direction
 * @rayDirX: ray direction x
 * @rayDirY: ray direction y
 * @stepX: number of steps to take on x axis
 * @stepY: number of steps to take on y axis
 * @mapX: x axis value on the map
 * @mapY: y axis value on the map
 * @player: pointer to player struct
 * @sideDistX: ray distance on x
 * @sideDistY: ray distance on y
 * @deltaDistX: delta on x
 * @deltaDistY: delta on y
*/
void stepSideDist(float *rayDirX, float *rayDirY, int *stepX, int *stepY,
		int *mapX, int *mapY, player *player, float *sideDistX,
		float *sideDistY, float *deltaDistX, float *deltaDistY)
{
	if (*rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (player->posX - *mapX) * (*deltaDistX);
	}
	else
	{
		*stepX = 1;
		*sideDistX = (*mapX + 1.0 - player->posX) * (*deltaDistX);
	}
	if (*rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (player->posY - *mapY) * (*deltaDistY);
	} else
	{
		*stepY = 1;
		*sideDistY = (*mapY + 1.0 - player->posY) * (*deltaDistY);
	}
}

/**
 * handle_hits - determine whether player has hit the wall
 * @map: 2D map
 * @hit: pointer to hit variable
 * @sideDistX: ray distance on x
 * @sideDistY: ray distance on y
 * @mapX: x axis value on the map
 * @mapY: y axis value on the map
 * @side: whether there is a wall on the side
 * @stepX: number of steps to take on x axis
 * @stepY: number of steps to take on y axis
 * @deltaDistX: delta on x
 * @deltaDistY: delta on y
*/
void handle_hits(int **map, int *hit, float *sideDistX, float *sideDistY,
		int *mapX, int *mapY, int *side, int *stepX, int *stepY,
		float *deltaDistX, float *deltaDistY)
{
	while (*hit == 0)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += *deltaDistX;
			*mapX += *stepX;
			*side = 0;
		}
		else
		{
			*sideDistY += *deltaDistY;
			*mapY += *stepY;
			*side = 1;
		}
		if (map[*mapX][*mapY] > 0)
			*hit = 1;
	}
}
