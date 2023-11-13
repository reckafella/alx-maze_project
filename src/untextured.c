#include "./headers/maze.h"

/**
 * render_untextured_walls - draw untextured walls
 * @instance: SDL Instance
 * @side: side
 * @draw_start: starting point
 * @draw_end: final point
 * @x: x value
 *
 * Return: Nothing
*/
void render_untextured_walls(SDL_Instance *instance, int side, int draw_start, int draw_end, int x)
{
	Uint8 wall_colorR, wall_colorG, wall_colorB;
	if (side == 1)
		wall_colorR = 60, wall_colorG = 242, wall_colorB = 25;
	else
		wall_colorR = 56, wall_colorG = 222, wall_colorB = 201;

	for (int y = draw_start; y <= draw_end; y++)
	{
		if (y < 0) continue;
		if (y >= SCREEN_HEIGHT) break;

		SDL_SetRenderDrawColor(instance->renderer, wall_colorR, wall_colorG, wall_colorB, 255);
		SDL_RenderDrawPoint(instance->renderer, x, y);
	}
}

/**
 * untextured_floor_ceiling - draw an untextured floor and ceiling
 * @instance: pointer to an SDL instance
 * @x: x value
 *
 * Return: Nothing
*/
void untextured_floor_ceiling(SDL_Instance *instance, int x)
{
	/* render the untextured floor and ceiling */
	for (int y = 0; y < SCREEN_HEIGHT - 1; y++)
	{
		/* draw floor */
		RENDER_COLOR(instance->renderer, 73, 156, 222, 255);
		SDL_RenderDrawPoint(instance->renderer, x, y);

		/* draw ceiling */
		RENDER_COLOR(instance->renderer, 192, 33, 236, 255);
		SDL_RenderDrawPoint(instance->renderer, x, SCREEN_HEIGHT - y - 1);
	}
	
}
