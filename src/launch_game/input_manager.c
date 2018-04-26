/*
** EPITECH PROJECT, 2018
** input_manager.c
** File description:
** main input file
*/

#include "my.h"
#include "../../include/procedural.h"

void verify_other_input(sfEvent event, gage_t *gage)
{
	 if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
		sfView_zoom(gage->proc->gman->camera, 0.9);
		sfRenderWindow_setView(gage->proc->gman->window,
		gage->proc->gman->camera);
	} if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
		sfView_zoom(gage->proc->gman->camera, 1.1);
		sfRenderWindow_setView(gage->proc->gman->window,
		gage->proc->gman->camera);
	}
}

void verif_movement_input(proc_t *proc)
{
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		proc->gman->player.velocity.y = -speed * 5;
	} else if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		proc->gman->player.velocity.y = speed * 5;
	} else {
		proc->gman->player.velocity.y = 0;
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		proc->gman->player.velocity.x = -speed * 5;
	} else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		proc->gman->player.velocity.x = speed * 5;
	} else {
		proc->gman->player.velocity.x = 0;
	}
}

int verif_input_map(gage_t *gage)
{
	sfEvent event;

	verif_movement_input(gage->proc);
	while (sfRenderWindow_pollEvent(gage->proc->gman->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(gage->proc->gman->window);
		verify_other_input(event, gage);
	}
}

void verify_exit_player(gage_t *gage)
{
	int px = gage->proc->gman->player.pos.x / 48;
	int py = gage->proc->gman->player.pos.y / 48;
	int ex = get_exit_pos(gage->proc).x / 48;
	int ey = get_exit_pos(gage->proc).y / 48;

	if (px == ex && py == ey) {
		next_level_screen(gage);
	}
}
