/*
** EPITECH PROJECT, 2018
** map_creation.c
** File description:
** map creation
*/

#include "my.h"
#include "../../include/procedural.h"

void increment_proc_struct(proc_var_t *pvar, proc_t *proc)
{
	proc->map = my_calloc(sizeof(char *) * (pvar->map_height + 1));
	proc->proom = my_calloc(sizeof(proom_t *) * (pvar->nbr_rooms + 1));
	for (int y = 0; y < pvar->map_height; y++) {
		proc->map[y] = my_calloc(sizeof(char) * (pvar->map_width + 1));
		for (int x = 0; x < pvar->map_width; x++)
			proc->map[y][x] = '#';
	}
}

proc_t *map_creation(gage_t *gage)
{
	proc_t *proc = malloc(sizeof(proc_t));

	srand((long)&proc);
	increment_proc_struct(gage->pvar, proc);
	make_positions_proom(gage, proc);
	for (int i = 0; proc->proom[i] != NULL; i++) {
		make_holes(proc->proom[i], proc->map, i);
	}
	proc->map = border_map(gage->pvar, proc->map);
	create_entry(proc);
	create_leave(proc);
	make_map_better(proc->map);
	return (proc);
}
