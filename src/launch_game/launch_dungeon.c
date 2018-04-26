/*
** EPITECH PROJECT, 2018
** launch_dungeon.c
** File description:
** launch the dungeon game
*/

#include "my.h"
#include "procedural.h"

void init_player(gmanager_t *gman, proc_t *proc)
{
	sfVector2f zoom = {1, 1};
	sfTexture *player_texture = sfTexture_createFromFile(
	"ressources/car2.png", NULL);

	gman->player.texture = player_texture;
	gman->player.sprite = sfSprite_create();
	gman->player.pos = get_entry_pos(proc);
	gman->player.rect.left = 0;
	gman->player.rect.top = 0;
	gman->player.rect.width = 48;
	gman->player.rect.height = 48;
	gman->player.velocity.y = 0;
	gman->player.velocity.x = 0;
	gman->player.speed.x = 0;
	gman->player.speed.y = 0;
	gman->player.m_speed.x = speed * 50;
	gman->player.m_speed.y = speed * 50;
	sfSprite_setTexture(gman->player.sprite, player_texture, sfTrue);
	sfSprite_setTextureRect(gman->player.sprite, gman->player.rect);
	sfSprite_setPosition(gman->player.sprite, gman->player.pos);
	sfSprite_setScale(gman->player.sprite, zoom);
}

gmanager_t *init_dungeon_game(proc_t *proc)
{
	gmanager_t *gman = malloc(sizeof(gmanager_t));

	gman->mode.width = WIDTH;
	gman->mode.height = HEIGHT;
	gman->mode.bitsPerPixel = 32;
	gman->window = sfRenderWindow_create(gman->mode, window_name, sfClose,
	NULL);
	init_player(gman, proc);
	gman->camera_pos = gman->player.pos;
	gman->camera = sfRenderWindow_getDefaultView(gman->window);
	sfView_zoom(gman->camera, 0.5);
	sfView_setCenter(gman->camera, gman->camera_pos);
	sfRenderWindow_setView(gman->window, gman->camera);
	init_minimap(gman);
	return (gman);
}

int draw_sprites_map(gage_t *gage, proc_t *proc)
{
	for (int y = 0; proc->map[y] != NULL; y++) {
		for (int x = 0; proc->map[y][x] != '\0'; x++) {
			if (proc->smap[y][x] != NULL) {
				sfRenderWindow_drawSprite(proc->gman->window,
				proc->smap[y][x]->sprite, NULL);
			}
		}
	}
	sfRenderWindow_drawSprite(proc->gman->window,
	proc->gman->player.sprite, NULL);
	verify_minimap(gage);
	return (1);
}

int update_sprite(proc_t *proc)
{
	sfVector2f player_pos;

	update_player_position(proc);
	player_pos.x = proc->gman->player.pos.x -
	(proc->gman->player.rect.width / 10);
	player_pos.y = proc->gman->player.pos.y -
	(proc->gman->player.rect.height / 10);
	sfSprite_setPosition(proc->gman->player.sprite, player_pos);
	update_camera_position(proc);
	return (1);
}

int launch_dungeon_game(gage_t *gage)
{
	gage->proc->gman = init_dungeon_game(gage->proc);
	while (sfRenderWindow_isOpen(gage->proc->gman->window)) {
		verif_input_map(gage);
		update_sprite(gage->proc);
		sfRenderWindow_clear(gage->proc->gman->window,
		gage->pvar->background);
		draw_sprites_map(gage, gage->proc);
		sfRenderWindow_display(gage->proc->gman->window);
		verify_exit_player(gage);
	}
	free_gage_game(gage);
	return (1);
}
