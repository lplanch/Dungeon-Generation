/*
** EPITECH PROJECT, 2018
** make_blocks_icorner.c
** File description:
** file to stock all functions about creating blocks for corner for interior
*/

#include "my.h"
#include "procedural.h"

void make_icorner_topleft_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 144;
	smap->rect.top = 288;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_icorner_topright_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 96;
	smap->rect.top = 288;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_icorner_botleft_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 48;
	smap->rect.top = 288;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_icorner_botright_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 0;
	smap->rect.top = 288;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}
