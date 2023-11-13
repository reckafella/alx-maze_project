#ifndef STRUCTS_H
#define STRUCTS_H

#include "macros.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <math.h>


typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *textures[NUMBER_OF_TEXTURES];
	SDL_Texture *texture;
	int textured;
} SDL_Instance;


typedef struct player
{
	float posX;
	float posY;
	float posZ;
	float dirX;
	float dirY;
	float planeX;
	float planeY;
} player;

/* typedef struct map
{
	int **array;
	int rows;
} map; */

#endif /* STRUCTS_H */
