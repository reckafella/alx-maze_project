#include "../headers/maze.h"

/**
 * initialize_instance - function to initialize the game's instance
 * @instance: pointer to an instance of the game
 * 
 * Return: 0 on success, 1 on fail
*/
int initialize_instance(SDL_Instance *instance)
{
	/* Initialize SDL library */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		fprintf(stderr, "Unable to Initialize SDL: %s\n", SDL_GetError());
		return (1);

	/* Create a new window */
	instance->window = SDL_CreateWindow(WINDOW_TITLE,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1268, 720, 0);

	if (!instance->window)
	{
		fprintf(stderr, "Error Creating Window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create a new Renderer instance linked to the window above */
	/* The renderer sets up the graphics hardware */
	Uint32 ren_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	instance->renderer = SDL_CreateRenderer(instance->window, -1, ren_flags);

	if (!instance->renderer)
	{
		fprintf(stderr, "Error Creating SDL Renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}

	return (0);
}

/**
 * destroy_instance - destroy the game instance
 * @instance: an instance of the SDL
 *
 * Return: Nothing
*/
void destroy_instance(SDL_Instance *instance)
{
	SDL_DestroyRenderer(instance->renderer);
	SDL_DestroyWindow(instance->window);
	SDL_Quit();
}
