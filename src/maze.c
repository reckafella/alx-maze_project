#include "./headers/maze.h"

/* global variables */
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
point pos, dir, plane;
double time;

/**
 * main - program entry point
 * @argc: argument count
 * @argv: pointer to an array of arguments
*/
int main(int argc, char **argv)
{
	int *maze_map;
	int length;
	char *map_name = "maps/", *map_path;
	SDL_Instance instance;

	/* initialize key variables */
	instance.textured = 1;
	pos.x = 1, pos.y = 12, dir.x = 1;
	dir.y = -0.66, plane.x = 0, plane.y = 0.66;
	time = 0;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: %s map_name\n", argv[0]);
		return (1);
	}
	length = strlen(map_name) + strlen(argv[1]) + 1;
	map_path = malloc(length);

	if (!map_path)
	{
		fprintf(stderr, "Malloc failed. \n\nExiting ...\n");
		return (1);
	}
	strcpy(map_path, map_name);
	map_path = strcat(map_path, argv[1]);

	maze_map = read_map(map_path);
	if (!maze_map)
		return (1);

	initialize_maze(&instance);

	if (instance.textured)
		load_textures();

	while (maze_loop(&instance) == 0)
	{
		if (!instance.textured)
			untextured_floor_ceiling(&instance);
		ray_cast(&instance, maze_map);

		/* handle events */
		update_position(maze_map);
	}

	destroy_maze(&instance);
	free(maze_map);
	return (0);
}
