<<<<<<< HEAD
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
void game_loop(SDL_Instance *instance, int **map, int *running, player *player, int *textured)
{
	SDL_Event event;

	while(running)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				running = 0;
		update_player_position(map, player);
		render_scene(instance, map, player, textured);
	}
}
=======
#include "../headers/maze.h"
>>>>>>> 7a93dd43be4eee4c3025f0dd4ef6fff405929afb

/**
 * main - entry point
 * @argc: number of arguments passed in the command line
<<<<<<< HEAD
 * @argv: argument vector
=======
 * @argv: vector of arguments passed in the command line
>>>>>>> 7a93dd43be4eee4c3025f0dd4ef6fff405929afb
 *
 * Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv)
{
<<<<<<< HEAD
	/* instance of SDL */
	SDL_Instance instance;
	/* variables to handle player position and direction when maze starts */

	player player;
	player.playerX = 2.0, player.playerY = 2.0;
	player.playerDirX = 1.0, player.playerDirY = 0.0;
	player.playerPlaneX = 0.0, player.playerPlaneY = 0.66;

	int running = 1, textured = 0, length;
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
	game_loop(&instance, maze_map, &running, &player, &textured);
	free_map(maze_map);
	free(map_path);
	destroy_maze(&instance);
	

=======
	int game_active;
	SDL_Instance instance;

	game_active	= initialize_instance(&instance);

	/* SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 0);
	SDL_RenderClear(instance->renderer);

	SDL_RenderPresent(instance->renderer);
	SDL_Delay(10000); */

	while(game_active == 0)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);

		SDL_RenderPresent(instance.renderer);

		/* SDL_Delay(100000); */
		game_active = 1;
		
	}
	/*destroy_instance(&instance);*/
>>>>>>> 7a93dd43be4eee4c3025f0dd4ef6fff405929afb
	return (0);
}
