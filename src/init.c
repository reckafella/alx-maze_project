#include "./headers/maze.h"

/**
 * init_sdl - initialize SDL
 * @instance: pointer to an instance of SDL
 *
 * Return: 0 on success, 1 otherwise
*/
int init_sdl(SDL_Instance *instance)
{
	int i;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Error Initializing SDL2: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	instance->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!instance->window)
	{
		fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	instance->renderer = SDL_CreateRenderer(instance->window, -1, render_flags);

	if (!instance->renderer)
	{
		fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}

	/*  */
	/* for (i = 0; i < NUMBER_OF_TEXTURES; i++)
	{
		instance->textures[i] = SDL_LoadBMP("./images/brick.bmp");
		if (!instance->textures[i])
		{
			fprintf(stderr, "Error loading Textures: %s\n", SDL_GetError());
			SDL_DestroyRenderer(instance->renderer);
			SDL_DestroyWindow(instance->window);
			SDL_Quit();
			return (1);
		}
	} */
	instance->textures[0] = SDL_LoadBMP("./images/wall.bmp");
	instance->textures[1] = SDL_LoadBMP("./images/wall_2.bmp");
	instance->textures[2] = SDL_LoadBMP("./images/sky.bmp"); /* ceiling */
	instance->textures[3] = SDL_LoadBMP("./images/wall_2.bmp"); /* floor */
	
	for (i = 0; i < NUMBER_OF_TEXTURES; i++)
	{
		if (!instance->textures[i])
		{
			fprintf(stderr, "Error loading Textures: %s\n", SDL_GetError());
			SDL_DestroyRenderer(instance->renderer);
                        SDL_DestroyWindow(instance->window);
                        SDL_Quit();
                        return (1);
		}
	}

	return (0);
}

/**
 * destroy_maze - release resources closing the maze
 * @instance: pointer to an instance of the maze
 *
 * Return: Nothing
 */
void destroy_maze(SDL_Instance *instance)
{
	SDL_DestroyRenderer(instance->renderer);
	SDL_DestroyWindow(instance->window);
	SDL_Quit();
}
