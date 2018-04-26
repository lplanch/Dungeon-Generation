/*
** EPITECH PROJECT, 2018
** create_blocks_corner.c
** File description:
** file to stock all functions about creating blocks for corner
*/

#include "my.h"
#include "../../include/procedural.h"

void make_corner_topleft_block(sfTexture *blocks, smap_t *smap)
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

void make_corner_topright_block(sfTexture *blocks, smap_t *smap)
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

void make_corner_botleft_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 0;
	smap->rect.top = 144;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}

void make_corner_botright_block(sfTexture *blocks, smap_t *smap)
{
	smap->sprite = sfSprite_create();
	smap->rect.left = 48;
	smap->rect.top = 144;
	smap->rect.width = 48;
	smap->rect.height = 48;
	sfSprite_setTexture(smap->sprite, blocks, sfTrue);
	sfSprite_setTextureRect(smap->sprite, smap->rect);
	sfSprite_setPosition(smap->sprite, smap->pos);
}
