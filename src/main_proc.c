/*
** EPITECH PROJECT, 2018
** main_proc.c
** File description:
** main_proc file for procedural gen
*/

#include "my.h"
#include "procedural.h"

void print_help(void)
{
	my_putstr("USAGE\n");
	my_putstr("         ./proc\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("         Generate random custom map for a future RPG\n");
}

proc_var_t *make_proc_variables(void)
{
	proc_var_t *pvar = malloc(sizeof(proc_var_t));

	pvar->texture_path = "ressources/dungeon_lvl1_tiles.png";
	pvar->map_width = 80;
	pvar->map_height = 45;
	pvar->max_room_s = 15;
	pvar->min_room_s = 9;
	pvar->nbr_rooms = 18;
	pvar->current_floor = 0;
	pvar->max_floor = 3;
	pvar->background.r = 20;
	pvar->background.g = 11;
	pvar->background.b = 40;
	pvar->background.a = 255;
	return (pvar);
}

int main(int ac, char **av)
{
	gage_t *gage = malloc(sizeof(gage_t));

	gage->pvar = make_proc_variables();
	if (ac == 2 && !my_strcmp(av[1], "-h")) {
		print_help();
	} else if (ac == 1) {
		gage->proc = map_creation(gage);
		draw_map(gage);
		free(gage->pvar);
	}
	free(gage);
}
