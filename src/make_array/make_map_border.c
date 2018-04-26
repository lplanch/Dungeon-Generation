/*
** EPITECH PROJECT, 2018
** make_map_border.c
** File description:
** make map border for generating and not destroying
*/

#include "my.h"
#include "procedural.h"

char *map_width_dup(char *line)
{
	char *result = my_calloc(sizeof(char) * (my_strlen(line) + 5));
	int i = 0;

	result[0] = '%';
	result[1] = '%';
	while (line[i] != '\0') {
		result[i + 2] = line[i];
		i += 1;
	}
	result[i + 2] = '%';
	result[i + 3] = '%';
	free(line);
	return (result);
}

char **border_map(proc_var_t *pvar, char **map)
{
	char **result = malloc(sizeof(char *) * (pvar->map_height + 6));

	result[0] = my_calloc(sizeof(char) * (pvar->map_width + 5));
	result[1] = my_calloc(sizeof(char) * (pvar->map_width + 5));
	result[pvar->map_height + 2] = my_calloc(sizeof(char) *
	(pvar->map_width + 5));
	result[pvar->map_height + 3] = my_calloc(sizeof(char) *
	(pvar->map_width + 5));
	result[pvar->map_height + 4] = NULL;
	for (int x = 0; x < pvar->map_width + 4; x++)
		result[0][x] = '%';
	for (int x = 0; x < pvar->map_width + 4; x++)
		result[1][x] = '%';
	for (int y = 0; map[y] != NULL; y++)
		result[y + 2] = map_width_dup(map[y]);
	for (int x = 0; x < pvar->map_width + 4; x++)
		result[pvar->map_height + 2][x] = '%';
	for (int x = 0; x < pvar->map_width + 4; x++)
		result[pvar->map_height + 3][x] = '%';
	free(map);
	return (result);
}
