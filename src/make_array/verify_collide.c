/*
** EPITECH PROJECT, 2018
** verify_collide.c
** File description:
** verify if a rect is not too close from another
*/

#include "my.h"
#include "../../include/procedural.h"

int intersect(proom_t *r1, proom_t *r2)
{
	if (r1->pos1[0] <= r2->pos2[0] && r1->pos2[0] >= r2->pos1[0]
	&& r1->pos1[1] <= r2->pos2[1] && r1->pos2[1] >= r2->pos1[1]) {
		return (1);
	} else {
		return (0);
	}
}

void verify_intersect(proom_t *temp_proom, proc_t *proc, int iter, int *fail)
{
	for (int i = 0; i < iter; i++) {
		if (intersect(temp_proom, proc->proom[i])) {
			*fail = 1;
			break;
		}
	}
}

proom_t *new_room(proc_var_t *pvar)
{
	proom_t *proom = malloc(sizeof(proom_t));

	proom->width = pvar->min_room_s + (rand() %
	(pvar->max_room_s - pvar->min_room_s + 1));
	proom->height = pvar->min_room_s + (rand() %
	(pvar->max_room_s - pvar->min_room_s + 1));
	proom->pos1[0] = rand() % (pvar->map_width - proom->width - 1) + 1;
	proom->pos1[1] = rand() % (pvar->map_height - proom->height - 1) + 1;
	proom->pos2[0] = proom->pos1[0] + proom->width;
	proom->pos2[1] = proom->pos1[1] + proom->height;
	proom->center[0] = floor((proom->pos1[0] + proom->pos2[0]) / 2);
	proom->center[1] = floor((proom->pos1[1] + proom->pos2[1]) / 2);
	return (proom);
}

void make_positions_proom(gage_t *gage, proc_t *proc)
{
	proom_t *temp_proom;
	int iter = 0;
	int fail;

	for (int i = 0; i < gage->pvar->nbr_rooms; i++) {
		fail = 0;
		temp_proom = new_room(gage->pvar);
		verify_intersect(temp_proom, proc, iter, &fail);
		if (!fail) {
			proc->proom[iter] = temp_proom;
			iter += 1;
			make_corridors(proc, iter);
		} else {
			free(temp_proom);
		}
	}
}

void make_holes(proom_t *proom, char **map, int i)
{
	for (int y = proom->pos1[1]; y < proom->pos2[1]; y++) {
		for (int x = proom->pos1[0]; x < proom->pos2[0]; x++) {
			map[y][x] = ' ';
		}
	}
}
