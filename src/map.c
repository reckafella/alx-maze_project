#include "./headers/maze.h"

/**
* read_map_from_file - open a text file and parse a 2D map
* @filename: the name of the file to open
*
* Return: pointer to the 2D array
*/
int **read_map_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    int **array;
    int i, row = 0;

    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    array = malloc(MAP_HEIGHT * sizeof(int*));
    for (i = 0; i < MAP_HEIGHT; i++)
        array[i] = malloc(MAP_WIDTH * sizeof(int));

    while (row < MAP_HEIGHT) {
        for (int i = 0; i < MAP_WIDTH; i++) {
            if (fscanf(fp, "%d", &array[row][i]) == EOF) {
                break;
            }
        }
        row++;

        if (row == MAP_HEIGHT) {
            break;
        }
    }

    fclose(fp);
    return array;
}

/**
 * free_map - clear resources allocated for the 2D map
 * @map: map data structure;
*/
void free_map(int **map)
{
    int i;

    for (i = 0; i < MAP_HEIGHT; i++)
        free(map[i]);
    free(map);
}
