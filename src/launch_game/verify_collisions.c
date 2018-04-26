/*
** EPITECH PROJECT, 2018
** verify_collisions.c
** File description:
** verify collisions for player and map
*/

#include "my.h"
#include "procedural.h"

int verify_collide(char block)
{
	if (block == ' ' || block == 'E' || block == 'S') {
		return (1);
	}
	return (0);
}
