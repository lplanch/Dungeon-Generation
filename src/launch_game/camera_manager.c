/*
** EPITECH PROJECT, 2018
** camera_manager.c
** File description:
** camera main file to move camera
*/

#include "my.h"
#include "../../include/procedural.h"

void update_camera_position(proc_t *proc)
{
	sfVector2f movement;

	proc->gman->camera_pos.x = proc->gman->player.pos.x;
	proc->gman->camera_pos.y = proc->gman->player.pos.y;
	sfView_setCenter(proc->gman->camera, proc->gman->camera_pos);
	sfRenderWindow_setView(proc->gman->window, proc->gman->camera);
}
