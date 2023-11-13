#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>
#include <SDL2/SDL.h>
#include "macros.h"


typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/* src/maps.c */
int initialize_instance(SDL_Instance *);

/* src/file_io.c */
FILE *open_file(const char *filename);
void close_file(FILE *fd);

/* src/sdl.c */
int create_map (FILE *fd);
void destroy_instance(SDL_Instance *);

#endif /* MAZE_H */
