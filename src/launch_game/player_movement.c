/*
** EPITECH PROJECT, 2018
** player_movement.c
** File description:
** make player move
*/

#include "my.h"
#include "../../include/procedural.h"

int interval(float value, float less, float max)
{
	if (value > less && value < max)
		return (1);
	return (0);
}

void set_speed_zero(proc_t *proc)
{
	if (interval(proc->gman->player.speed.x, 0, speed * 2.5) == 1) {
		proc->gman->player.speed.x = 0;
	} if (interval(proc->gman->player.speed.x, -speed * 2.5, 0) == 1) {
		proc->gman->player.speed.x = 0;
	} if (interval(proc->gman->player.speed.y, 0, speed * 2.5) == 1) {
		proc->gman->player.speed.y = 0;
	} if (interval(proc->gman->player.speed.y, -speed * 2.5, 0) == 1) {
		proc->gman->player.speed.y = 0;
	}
}

void decrement_speed(proc_t *proc)
{
	if (proc->gman->player.speed.x > 0) {
		proc->gman->player.speed.x -= speed;
	} else if (proc->gman->player.speed.x < 0) {
		proc->gman->player.speed.x += speed;
	} if (proc->gman->player.speed.y < 0) {
		proc->gman->player.speed.y += speed;
	} else if (proc->gman->player.speed.y > 0) {
		proc->gman->player.speed.y -= speed;
	}
	set_speed_zero(proc);
}

void make_player_position(proc_t *proc)
{
	int tempy[2];
	int tempx[2];

	tempy[0] = (proc->gman->player.pos.y + proc->gman->player.speed.y) / 48;
	tempy[1] = (proc->gman->player.pos.x) / 48;
	tempx[0] = (proc->gman->player.pos.y) / 48;
	tempx[1] = (proc->gman->player.pos.x + proc->gman->player.speed.x) / 48;
	if (verify_collide(proc->map[tempy[0]][tempy[1]])) {
		proc->gman->player.pos.y += proc->gman->player.speed.y;
	} if (verify_collide(proc->map[tempx[0]][tempx[1]])) {
		proc->gman->player.pos.x += proc->gman->player.speed.x;
	}
}

void update_player_position(proc_t *proc)
{
	proc->gman->player.speed.y += proc->gman->player.velocity.y;
	proc->gman->player.speed.x += proc->gman->player.velocity.x;

	if (proc->gman->player.speed.x > proc->gman->player.m_speed.x)
		proc->gman->player.speed.x = proc->gman->player.m_speed.x;
	else if (proc->gman->player.speed.x < -proc->gman->player.m_speed.x)
		proc->gman->player.speed.x = -proc->gman->player.m_speed.x;
	if (proc->gman->player.speed.y > proc->gman->player.m_speed.y)
		proc->gman->player.speed.y = proc->gman->player.m_speed.y;
	else if (proc->gman->player.speed.y < -proc->gman->player.m_speed.y)
		proc->gman->player.speed.y = -proc->gman->player.m_speed.y;
	decrement_speed(proc);
	make_player_position(proc);
}
