/*
** EPITECH PROJECT, 2018
** make_map_better.c
** File description:
** file to stock all functions about making map better
*/

#include "my.h"
#include "procedural.h"

void parse_wall_map(char **map, int y, int x)
{
	if (map[y][x] == '#' && is_ground(map[y + 1][x]) &&
	!is_ground(map[y][x - 1]) && !is_ground(map[y][x + 1]))
		map[y][x] = 'T';
	if (map[y][x] == '#' && is_ground(map[y - 1][x]) &&
	!is_ground(map[y][x - 1]) && !is_ground(map[y][x + 1]))
		map[y][x] = 'V';
	if (map[y][x] == '#' && is_ground(map[y][x - 1]) &&
	!is_ground(map[y - 1][x]) && !is_ground(map[y + 1][x]))
		map[y][x] = 'R';
	if (map[y][x] == '#' && is_ground(map[y][x + 1]) &&
	!is_ground(map[y - 1][x]) && !is_ground(map[y + 1][x]))
		map[y][x] = 'L';
}

void parse_corner_map(char **map, int y, int x)
{
	if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
	is_ground(map[y - 1][x - 1]))
		map[y][x] = 'N';
	if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
	is_ground(map[y - 1][x + 1]))
		map[y][x] = 'W';
	if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
	is_ground(map[y + 1][x - 1]))
		map[y][x] = 'P';
	if (map[y][x] == '#' && many_around(map, x, y) == 1 &&
	is_ground(map[y + 1][x + 1]))
		map[y][x] = 'A';
}

void parse_deadlock_map(char **map, int y, int x)
{
	if (map[y][x] == '#' && is_ground(map[y][x - 1]) &&
	is_ground(map[y][x + 1]) && is_ground(map[y + 1][x]))
		map[y][x] = 'Y';
	if (map[y][x] == '#' && is_ground(map[y][x - 1]) &&
	is_ground(map[y][x + 1]) && is_ground(map[y - 1][x]))
		map[y][x] = 'H';
	if (map[y][x] == '#' && is_ground(map[y - 1][x]) &&
	is_ground(map[y + 1][x]) && is_ground(map[y][x + 1]))
		map[y][x] = 'G';
	if (map[y][x] == '#' && is_ground(map[y - 1][x]) &&
	is_ground(map[y + 1][x]) && is_ground(map[y][x - 1]))
		map[y][x] = 'J';
}

void parse_icorner_map(char **map, int y, int x)
{
	if (map[y][x] == '#' && is_ground(map[y][x + 1]) &&
	is_ground(map[y + 1][x]) && !is_ground(map[y - 1][x]) &&
	!is_ground(map[y][x - 1]))
		map[y][x] = 'Z';
	if (map[y][x] == '#' && is_ground(map[y][x - 1]) &&
	is_ground(map[y + 1][x]) && !is_ground(map[y - 1][x]) &&
	!is_ground(map[y][x + 1]))
		map[y][x] = 'O';
	if (map[y][x] == '#' && is_ground(map[y - 1][x]) &&
	is_ground(map[y][x + 1]) && !is_ground(map[y + 1][x]) &&
	!is_ground(map[y][x - 1]))
		map[y][x] = 'U';
	if (map[y][x] == '#' && is_ground(map[y - 1][x]) &&
	is_ground(map[y][x - 1]) && !is_ground(map[y + 1][x]) &&
	!is_ground(map[y][x + 1]))
		map[y][x] = 'I';
}

void make_map_better(char **map)
{
	for (int y = 2; map[y + 2] != NULL; y++) {
		for (int x = 2; map[y][x + 2] != '\0'; x++) {
			parse_wall_map(map, y, x);
			parse_corner_map(map, y, x);
			parse_deadlock_map(map, y, x);
			parse_icorner_map(map, y, x);
		}
	}
}
