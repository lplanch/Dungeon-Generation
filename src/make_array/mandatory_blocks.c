/*
** EPITECH PROJECT, 2018
** mandatory_blocks.c
** File description:
** spawn mandatory blocks like entry and leave
*/

#include "my.h"
#include "procedural.h"

int count_rooms(proom_t **proom)
{
	int res = 0;

	while (proom[res] != NULL)
		res += 1;
	return (res);
}

sfVector2f get_entry_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			if (proc->map[y][x] == 'E' || proc->map[y][x] == 'B') {
				result.y = y * 48;
				result.x = x * 48;
				return (result);
			}
		}
	}
	return (result);
}

sfVector2f get_exit_pos(proc_t *proc)
{
	sfVector2f result = {0, 0};

	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			if (proc->map[y][x] == 'S' || proc->map[y][x] == 'B') {
				result.y = y * 48;
				result.x = x * 48;
				return (result);
			}
		}
	}
	return (result);
}

void create_entry(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room]->pos1[0] + 1 +
	(rand() % (proc->proom[room]->width - 2));
	int posy = proc->proom[room]->pos1[1] + 1 +
	(rand() % (proc->proom[room]->height - 2));

	proc->map[posy][posx] = 'E';
}

void create_leave(proc_t *proc)
{
	int room = rand() % count_rooms(proc->proom);
	int posx = proc->proom[room]->pos1[0] +
	(rand() % (proc->proom[room]->width));
	int posy = proc->proom[room]->pos1[1] +
	(rand() % (proc->proom[room]->height));

	if (proc->map[posy][posx] == 'E')
		proc->map[posy][posx] = 'B';
	else
		proc->map[posy][posx] = 'S';
}
