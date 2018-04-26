/*
** EPITECH PROJECT, 2018
** main_draw_map.c
** File description:
** main file to stock all functions about drawing map
*/

#include "my.h"
#include "procedural.h"

smap_t *generate_block(sfTexture *blocks, char chr, smap_t *smap)
{
	switch (chr) {
	case 'E':
	case ' ':
		make_ground_block(blocks, smap);
		break;
	case 'S':
		make_exit_block(blocks, smap);
		break;
	case 'L':
	case 'R':
		make_leftright_block(blocks, smap);
		break;
	case 'T':
		make_top_block(blocks, smap);
		break;
	case 'V':
		make_bot_block(blocks, smap);
		break;
	case 'A':
		make_corner_topleft_block(blocks, smap);
		break;
	case 'P':
		make_corner_topright_block(blocks, smap);
		break;
	case 'W':
		make_corner_botleft_block(blocks, smap);
		break;
	case 'N':
		make_corner_botright_block(blocks, smap);
		break;
	case 'Y':
		make_deadlock_top_block(blocks, smap);
		break;
	case 'H':
		make_deadlock_bot_block(blocks, smap);
		break;
	case 'G':
		make_deadlock_left_block(blocks, smap);
		break;
	case 'J':
		make_deadlock_right_block(blocks, smap);
		break;
	case 'O':
		make_icorner_topright_block(blocks, smap);
		break;
	case 'Z':
		make_icorner_topleft_block(blocks, smap);
		break;
	case 'U':
		make_icorner_botleft_block(blocks, smap);
		break;
	case 'I':
		make_icorner_botright_block(blocks, smap);
		break;
	default:
		free(smap);
		smap = NULL;
		break;
	}
	return (smap);
}

smap_t ***create_sprite_map(gage_t *gage, char **map)
{
	smap_t ***smap = my_calloc(sizeof(smap_t **) * (count_lines(map) + 1));
	sfTexture *blocks = sfTexture_createFromFile(gage->pvar->texture_path,
	NULL);

	gage->proc->blocks_texture = blocks;
	for (int y = 0; map[y] != NULL; y++) {
		smap[y] = my_calloc(sizeof(smap_t *) * (my_strlen(map[y]) + 1));
		for (int x = 0; map[y][x] != '\0'; x++) {
			smap[y][x] = malloc(sizeof(smap_t));
			smap[y][x]->pos.x = x * 48;
			smap[y][x]->pos.y = y * 48;
			smap[y][x] = generate_block(blocks, map[y][x],
			smap[y][x]);
		}
	}
	return (smap);
}

void draw_map(gage_t *gage)
{
	gage->proc->smap = create_sprite_map(gage, gage->proc->map);

	launch_dungeon_game(gage);
}
