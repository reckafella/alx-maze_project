#include "../headers/maze.h"

/**
* open_file - read map from a file
* @filename: the name of the file to open
*
* Return: pointer to the file handle
*/
FILE *open_file(const char *filename)
{
	FILE *fd;

	fd = fopen(filename, O_RDONLY);

	if (!fd)
	{
		fprintf(stderr, "Error opening file %s\n", filename);
		return (NULL);
	}
	return (fd);
}


/**
 * close_file - closes file given its descriptor
 * @fd: file descriptor
 *
 * Return: Nothing
*/
void close_file(FILE *fd)
{
	if (fd)
	{
		fclose(fd);
	}
}
