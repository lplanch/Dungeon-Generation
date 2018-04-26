/*
** EPITECH PROJECT, 2018
** procedural_struct.h
** File description:
**
*/

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
} framebuffer_t;

typedef struct minimap {
	framebuffer_t *f_background;
	framebuffer_t *f_minimap;
	sfTexture *fb_texture;
	sfTexture *fm_texture;
	sfSprite *fb_sprite;
	sfSprite *fm_sprite;
} minimap_t;

typedef struct proc_room
{
	int pos1[2];
	int pos2[2];
	int width;
	int height;
	int center[2];
} proom_t;

typedef struct map_sprite
{
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
} smap_t;

typedef struct player_manager
{
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f velocity;
	sfVector2f speed;
	sfVector2f m_speed;
} player_t;

typedef struct game_manager
{
	sfVideoMode mode;
	sfRenderWindow *window;
	sfView *camera;
	player_t player;
	sfVector2f camera_pos;
	minimap_t *minimap;
} gmanager_t;

typedef struct proc_gen
{
	gmanager_t *gman;
	proom_t **proom;
	smap_t ***smap;
	char **map;
	sfTexture *blocks_texture;
	unsigned int current_floor;
} proc_t;

typedef struct proc_var
{
	char *texture_path;
	unsigned int map_width;
	unsigned int map_height;
	unsigned int max_room_s;
	unsigned int min_room_s;
	unsigned int nbr_rooms;
	unsigned int current_floor;
	unsigned int max_floor;
	sfColor background;
} proc_var_t;

typedef struct game_agent
{
	proc_t *proc;
	proc_var_t *pvar;
} gage_t;
