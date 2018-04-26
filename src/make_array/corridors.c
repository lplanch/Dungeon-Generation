/*
** EPITECH PROJECT, 2018
** corridors.c
** File description:
** make corridors to connect rooms
*/

#include "my.h"
#include "../../include/procedural.h"

void h_corridor(char **map, int x1, int x2, int y)
{
	for (int x = MIN(x1, x2); x < MAX(x1, x2) + 1; x++) {
		map[y][x] = ' ';
	}
}

void v_corridor(char **map, int y1, int y2, int x)
{
	for (int y = MIN(y1, y2); y < MAX(y1, y2) + 1; y++) {
		map[y][x] = ' ';
	}
}

int many_around(char **map, int x, int y)
{
	int result = 0;

	if (is_ground(map[y][x + 1]))
		result += 1;
	if (is_ground(map[y][x - 1]))
		result += 1;
	if (is_ground(map[y + 1][x]))
		result += 1;
	if (is_ground(map[y - 1][x]))
		result += 1;
	if (is_ground(map[y + 1][x + 1]))
		result += 1;
	if (is_ground(map[y - 1][x - 1]))
		result += 1;
	if (is_ground(map[y - 1][x + 1]))
		result += 1;
	if (is_ground(map[y + 1][x - 1]))
		result += 1;
	return (result);
}

void make_corridors(proc_t *proc, int length)
{
	int pcenter[2];
	int ncenter[2];

	if (length > 1) {
		pcenter[0] = proc->proom[length - 2]->center[0];
		pcenter[1] = proc->proom[length - 2]->center[1];
		ncenter[0] = proc->proom[length - 1]->center[0];
		ncenter[1] = proc->proom[length - 1]->center[1];
		if (rand() % 2 == 1) {
			h_corridor(proc->map, pcenter[0], ncenter[0], pcenter[1]);
			v_corridor(proc->map, pcenter[1], ncenter[1], ncenter[0]);
		} else {
			v_corridor(proc->map, pcenter[1], ncenter[1], pcenter[0]);
			h_corridor(proc->map, pcenter[0], ncenter[0], ncenter[1]);
		}
	}
}
