#ifndef STRUCTS_H
#define STRUCTS_H

#include "macros.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>
#include <math.h>


typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *wall_texture;
	SDL_Surface *wall_surface;
	SDL_Texture *floor_texture;
	SDL_Surface *floor_surface;
	SDL_Texture *ceiling_texture;
	SDL_Surface *ceiling_surface;
} SDL_Instance;


typedef struct player
{
	float playerX;
	float playerY;
	float playerDirX;
	float playerDirY;
	float playerPlaneX;
	float playerPlaneY;
} player;

/* typedef struct map
{
	int **array;
	int rows;
} map; */

#endif /* STRUCTS_H */
