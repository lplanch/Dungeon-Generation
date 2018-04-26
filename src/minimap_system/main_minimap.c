/*
** EPITECH PROJECT, 2018
** minimap_system.c
** File description:
** make minimap on screen
*/

#include "my.h"
#include "../../include/procedural.h"

void init_minimap(gmanager_t *gman)
{
	gman->minimap = malloc(sizeof(minimap_t));

	gman->minimap->f_background = framebuffer_create(WIDTH, HEIGHT);
	gman->minimap->fb_texture = sfTexture_create(WIDTH, HEIGHT);
	gman->minimap->fb_sprite = sfSprite_create();

	sfSprite_setTexture(
	gman->minimap->fb_sprite, gman->minimap->fb_texture, sfTrue);

	my_fill_screen(gman->minimap->f_background, sfWhite);
	gman->minimap->f_minimap = framebuffer_create(WIDTH, HEIGHT);
}

void draw_minimap(gmanager_t *gman)
{
	sfTexture_updateFromPixels(gman->minimap->fb_texture,
	gman->minimap->f_background->pixels, WIDTH, HEIGHT, 0, 0);
	sfRenderWindow_drawSprite(gman->window, gman->minimap->fb_sprite, NULL);
}

void verify_minimap(gage_t *gage)
{
	if (sfKeyboard_isKeyPressed(sfKeyTab) == sfTrue) {
		draw_minimap(gage->proc->gman);
	}
}
