/*
** EPITECH PROJECT, 2018
** restart_game.c
** File description:
** file to stock all functions about restarting a game
*/

#include "my.h"
#include "procedural.h"

void create_char_map_restart(gage_t *gage)
{
	increment_proc_struct(gage->pvar, gage->proc);
	make_positions_proom(gage, gage->proc);
	for (int i = 0; gage->proc->proom[i] != NULL; i++) {
		make_holes(gage->proc->proom[i], gage->proc->map, i);
	}
	create_entry(gage->proc);
	create_leave(gage->proc);
	make_map_better(gage->proc->map);
}

void print_map(char **map)
{
	for (int y = 0; map[y] != NULL; y++) {
		for (int x = 0; map[y][x] != '\0'; x++) {
			my_putchar(map[y][x]);
			my_putchar(' ');
		}
		my_putchar('\n');
	}
}

void init_next_level(gage_t *gage)
{
	create_char_map_restart(gage);
	gage->proc->smap = create_sprite_map(gage, gage->proc->map);
	gage->proc->gman->player.pos = get_entry_pos(gage->proc);
	gage->proc->gman->player.velocity.y = 0;
	gage->proc->gman->player.velocity.x = 0;
	gage->proc->gman->player.speed.y = 0;
	gage->proc->gman->player.speed.x = 0;
}

void draw_floor_restart(gage_t *gage)
{
	sfVector2f screen_center = gage->proc->gman->camera_pos;
	char *cur_level = int_to_str(gage->pvar->current_floor);
	char *level_string = my_strcat("Floor ", cur_level);
	sfFont *font = sfFont_createFromFile("ressources/OpenSans.ttf");
	sfText *next_level = sfText_create();

	screen_center.y -= 9;
	screen_center.x -= (my_strlen(level_string) * 9) / 2;
	sfText_setString(next_level, level_string);
	sfText_setFont(next_level, font);
	sfText_setCharacterSize(next_level, 18);
	sfText_setPosition(next_level, screen_center);
	sfText_setColor(next_level, sfWhite);
	sfRenderWindow_drawText(gage->proc->gman->window, next_level, NULL);
	sfRenderWindow_display(gage->proc->gman->window);
	sfText_destroy(next_level);
	sfFont_destroy(font);
	free(cur_level);
	free(level_string);
}

void next_level_screen(gage_t *gage)
{
	free_dungeon(gage->proc);
	if (gage->pvar->current_floor < gage->pvar->max_floor) {
		gage->pvar->current_floor += 1;
	} else if (gage->pvar->current_floor < gage->pvar->max_floor) {
		gage->pvar->current_floor -= 1;
	} else {
		sfRenderWindow_close(gage->proc->gman->window);
		return;
	}
	sfRenderWindow_clear(gage->proc->gman->window, sfBlack);
	draw_floor_restart(gage);
	init_next_level(gage);
	sleep(4);
}
