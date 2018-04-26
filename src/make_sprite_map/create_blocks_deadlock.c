/*
** EPITECH PROJECT, 2018
** create_blocks_deadlock.c
** File description:
** file to stock all functions about creating blocks for deadlock
*/

#include "my.h"
#include "../../include/procedural.h"

void make_deadlock_top_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 48;
	smap->rect.top = 240;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_deadlock_bot_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 0;
	smap->rect.top = 240;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_deadlock_left_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 144;
	smap->rect.top = 240;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_deadlock_right_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 96;
	smap->rect.top = 240;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

int is_ground(char chr)
{
	if (chr == ' ' || chr == 'S' || chr == 'E')
		return (1);
	return (0);
}
