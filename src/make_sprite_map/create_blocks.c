/*
** EPITECH PROJECT, 2018
** create_blocks.c
** File description:
** make individual blocks
*/

#include "my.h"
#include "procedural.h"

void make_ground_block(sfTexture *blocks, smap_t *smap)
{
	int random = rand() % 16;

	smap->sprite = sfSprite_create();
	smap->rect.top = 192;
	if (random < 13)
		smap->rect.left = 48;
	if (random == 13)
		smap->rect.left = 96;
	if (random == 14)
		smap->rect.left = 144;
	if (random == 15)
		smap->rect.left = 0;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_leftright_block(sfTexture *blocks, smap_t *smap)
{
	int random = rand() % 3;

	smap->sprite = sfSprite_create();
	smap->rect.top = 0;
	if (random == 0)
		smap->rect.left = 0;
	if (random == 1)
		smap->rect.left = 45;
	if (random == 2)
		smap->rect.left = 96;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_exit_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 144;
	smap->rect.top = 336;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_top_block(sfTexture *blocks, smap_t *smap)
{
	int random = rand() % 3;

	smap->sprite = sfSprite_create();
	smap->rect.top = 48;
	if (random == 0)
		smap->rect.left = 0;
	if (random == 1)
		smap->rect.left = 48;
	if (random == 2)
		smap->rect.left = 96;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_bot_block(sfTexture *blocks, smap_t *smap)
{
	int random = rand() % 3;

	smap->sprite = sfSprite_create();
	smap->rect.top = 96;
	if (random == 0)
		smap->rect.left = 0;
	if (random == 1)
		smap->rect.left = 48;
	if (random == 2)
		smap->rect.left = 96;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}
