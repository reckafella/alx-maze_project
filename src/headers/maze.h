#ifndef MAZE_H
#define MAZE_H

#include "structs.h"

/* function prototypes */
/* init.c */

int init_sdl(SDL_Instance *instance);
void destroy_maze(SDL_Instance *instance);

/* untextured.c */

void render_untextured_walls(SDL_Instance *instance, int side,
		int draw_start, int draw_end, int x);
void untextured_floor_ceiling(SDL_Instance *instance, int x);


/* maze.c */

void game_loop(SDL_Instance *instance, int **map, int *running,
		player *player, int *textured);

/* player.c */
void draw_player(SDL_Instance *instance, player *player);
int detect_collision(int **map, int x, int y);
void update_player_position(int **map, player *player);
/* map.c */

int **read_map_from_file(const char* filename);
void free_map(int **map);

/* raycast.c */

void cast_ray(SDL_Instance *instance, int **map, int x,
		player *player, int *textured);
void render_scene(SDL_Instance *instance, int **map,
		player *player, int *textured);
void calcRayDir(int x, float *rayDirX, float *rayDirY, player *player);

/* raycast_2.c */

void stepSideDist(float *rayDirX, float *rayDirY, int *stepX, int *stepY,
		int *mapX, int *mapY, player *player, float *sideDistX,
		float *sideDistY, float *deltaDistX, float *deltaDistY);

void handle_hits(int **map, int *hit, float *sideDistX, float *sideDistY,
		int *mapX, int *mapY, int *side, int *stepX, int *stepY,
		float *deltaDistX, float *deltaDistY);

/* textured.c */

void draw_textured_walls(SDL_Instance *instance);

#endif /* MAZE_H */
