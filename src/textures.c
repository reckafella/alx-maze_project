#include "headers/maze.h"

/**
 * draw_walls_slice - draw walls
 * @instance: SDL instance
 * @player: pointer to player
 * @perpWallDist: float value for perpendicular wall distance
 * @side: integer value indicating whether wall is on either side
 * @x: x coordinate value
 *
 * Return: Nothing
*/
void draw_wall_slice(SDL_Instance *instance, player *player,
		float perpWallDist, int side, int x)
{
	int line_height, draw_start, draw_end;

	line_height = (int)(SCREEN_HEIGHT / perpWallDist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;

	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;

	if (instance->textured)
	{
		int texX;

		SDL_Surface *wallTexture = instance->textures[side];

		texX = (int)(TEXTURE_WIDTH * (x * 0.5)) % TEXTURE_WIDTH;
		if ((side == 0 && player->dirX > 0) || (side == 1 && player->dirY < 0))
			texX = TEXTURE_WIDTH - texX - 1;
		
		SDL_Rect dest_rect = {x, draw_start, 1, line_height};
		SDL_Rect src_rect = {texX, 0, 1, TEXTURE_HEIGHT};
		SDL_Texture *texture = SDL_CreateTextureFromSurface(instance->renderer, wallTexture);
		SDL_RenderCopy(instance->renderer, texture, &src_rect, &dest_rect);
		SDL_DestroyTexture(texture);
	}
	else
	{
		SDL_Color wall_color;

		if (side == 0)
			wall_color = (SDL_Color){255, 0, 0, 255}; /* RED */
		else
			wall_color = (SDL_Color){0, 255, 0, 255}; /* GREEN */

		SDL_SetRenderDrawColor(instance->renderer, wall_color.r, wall_color.g, wall_color.b, wall_color.a);
		SDL_RenderDrawLine(instance->renderer, x, draw_start, x, draw_end);
	}
}

/**
 * renderFloorCeiling - draw floor and ceiling
 * @instance: SDL instance
 * @player: pointer to player struct
 * @x: x coordinate value
*/
void renderFloorCeiling(SDL_Instance *instance, player *player, int x)
{
	int y, floorTexX, floorTexY, ceilingTexX, ceilingTexY;
	int floorStart = SCREEN_HEIGHT / 2 + 1,
	    ceilingEnd = SCREEN_HEIGHT / 2;
	double currDist, weight, currFloorX, currFloorY, currCeilX, currCeilY;

	if (instance->textured)
	{
		/* render textured floor */
		for (y = floorStart; y < SCREEN_HEIGHT; y++)
		{
			currDist = SCREEN_HEIGHT / (2.0 * (SCREEN_HEIGHT / 2 - y));
			weight = currDist / player->posZ;
			currFloorX = weight * player->posX + (1.0 - weight) * player->dirX;
			currFloorY = weight * player->posY + (1.0 - weight) * player->dirY;

			floorTexX = (int)(currFloorX * TEXTURE_WIDTH) % TEXTURE_WIDTH;
			floorTexY = (int)(currFloorY * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;

			SDL_Rect dst_rect = {x, y, 1, 1};
			SDL_Rect src_rect = {floorTexX, floorTexY, 1, 1};
			SDL_Texture *texture = SDL_CreateTextureFromSurface(
					instance->renderer,
					instance->textures[2]);
			SDL_RenderCopy(instance->renderer, texture,
					&src_rect, &dst_rect);
			SDL_DestroyTexture(texture);
		}
		/* render textured ceiling */
		for (y = 0; y < ceilingEnd; y++)
		{
			currDist = (SCREEN_HEIGHT /
					(2.0 * (y - SCREEN_HEIGHT / 2)));
			weight = currDist / player->posZ;
			currCeilX = weight * player->posX +
				(1.0 - weight) * player->dirX;
			currCeilY = weight * player->posY +
				(1.0 - weight) * player->dirY;

			ceilingTexX = (int)(currFloorX * TEXTURE_WIDTH) %
				TEXTURE_WIDTH;
			ceilingTexY = (int)(currFloorY * TEXTURE_HEIGHT) %
				TEXTURE_HEIGHT;

			SDL_Rect dst_rect = {x, y, 1, 1};
			SDL_Rect src_rect = {ceilingTexX, ceilingTexY, 1, 1};
			SDL_Texture *texture = SDL_CreateTextureFromSurface(
					instance->renderer,
					instance->textures[3]);
			SDL_RenderCopy(instance->renderer, texture,
					&src_rect, &dst_rect);
			SDL_DestroyTexture(texture);
		}
	}
	else
	{
		/* render untextured floor */
		SDL_SetRenderDrawColor(instance->renderer,
				100, 100, 100, 255);  // Gray
		for (int y = floorStart; y < SCREEN_HEIGHT; y++) {
			SDL_RenderDrawPoint(instance->renderer, x, y);
		}

    	/* Render untextured ceiling */
    	SDL_SetRenderDrawColor(instance->renderer,
			50, 50, 50, 255);  // Dark gray
		for (int y = 0; y < ceilingEnd; y++) {
			SDL_RenderDrawPoint(instance->renderer, x, y);
		}
	}
}
