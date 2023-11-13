#include "./headers/maze.h"


/**
 * game_loop - handle game loop
 * @instance: pointer to an instance of sdl
 * @map: 2D map
 * @running: pointer to a variable holding run status of the game
 * @player: player
 * @textured: boolean for whether to draw textures, 0 - false, 1 - true
 *
 * Return: Nothing
*/
void game_loop(SDL_Instance *instance, int **map, int *running, player *player)
{
	SDL_Event event;

	while(running)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				running = 0;
		update_player_position(map, player);
		render_scene(instance, map, player);
	}
}

/**
 * main - entry point
 * @argc: number of arguments passed in the command line
 * @argv: argument vector
 *
 * Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv)
{
	/* instance of SDL */
	SDL_Instance instance;
	instance.textured = 1;
	/* variables to handle player position and direction when maze starts */

	player player;
	player.posX = 2.0, player.posY = 2.0, player.posZ = 0.0;
	player.dirX = 1.0, player.dirY = 0.0;
	player.planeX = 0.0, player.planeY = 0.66;

	int running = 1, length;
	int **maze_map;
	char *map_path, *mp = "maps/";
	
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: %s map_name\n", argv[0]);
		return (1);
	}
	length = strlen(mp) + 1 + strlen(argv[1]);
	map_path = malloc(length);
	if (!map_path)
		return (1);

	strcpy(map_path, mp);
	map_path = strcat(map_path, argv[1]);

	maze_map = read_map_from_file(map_path);

	init_sdl(&instance);
	game_loop(&instance, maze_map, &running, &player);
	free_map(maze_map);
	free(map_path);
	destroy_maze(&instance);
	

	return (0);
}
