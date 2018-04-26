/*
** EPITECH PROJECT, 2018
** procedural.h
** File description:
** ezwin
*/

#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#include "procedural_struct.h"

#define MIN(a, b) ((a < b)? a : b)
#define MAX(a, b) ((a > b)? a : b)

//GAME MANAGE
static const unsigned int WIDTH = 1664;
static const unsigned int HEIGHT = 936;
static const char window_name[13] = "INTO THE DEEP";

//PLAYER
static const float speed = 0.018;

//MAKE MAP
proc_t *map_creation(gage_t *gage);
void make_positions_proom(gage_t *gage, proc_t *proc);
void make_holes(proom_t *proom, char **map, int i);
void make_map_better(char **map);
void increment_proc_struct(proc_var_t *pvar, proc_t *proc);
char **border_map(proc_var_t *pvar, char **map);
void print_map(char **map);

//CORRIDORS
void v_corridor(char **map, int y1, int y2, int x);
void h_corridor(char **map, int x1, int x2, int y);
void make_corridors(proc_t *proc, int length);

//CREATE MANDATORY BLOCKS
void create_entry(proc_t *proc);
void create_leave(proc_t *proc);
sfVector2f get_entry_pos(proc_t *proc);
sfVector2f get_exit_pos(proc_t *proc);
void verify_exit_player(gage_t *gage);
int verify_collide(char block);

//DRAW MAP
void draw_map(gage_t *gage);
void free_map_tbl(proc_t *proc);
smap_t ***create_sprite_map(gage_t *gage, char **map);

//MANAGER
int verif_input_map(gage_t *gage);
void update_camera_position(proc_t *proc);
void update_player_position(proc_t *proc);

//MINIMAP
void init_minimap(gmanager_t *gman);
void verify_minimap(gage_t *gage);

//FRAMEBUFFER
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_fill_screen(framebuffer_t *buffer, sfColor color);
void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color);
void fill_minimap_screen(framebuffer_t *buffer, sfColor color);

//CREATE BLOCKS
int is_ground(char chr);
int many_around(char **map, int x, int y);

void make_ground_block(sfTexture *blocks, smap_t *smap);
void make_exit_block(sfTexture *blocks, smap_t *smap);
void make_leftright_block(sfTexture *blocks, smap_t *smap);
void make_bot_block(sfTexture *blocks, smap_t *smap);
void make_top_block(sfTexture *blocks, smap_t *smap);

void make_corner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_botright_block(sfTexture *blocks, smap_t *smap);
void make_corner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_corner_topright_block(sfTexture *blocks, smap_t *smap);

void make_icorner_botleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_botright_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topleft_block(sfTexture *blocks, smap_t *smap);
void make_icorner_topright_block(sfTexture *blocks, smap_t *smap);

void make_deadlock_top_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_bot_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_right_block(sfTexture *blocks, smap_t *smap);
void make_deadlock_left_block(sfTexture *blocks, smap_t *smap);


//MAIN GAME
int launch_dungeon_game(gage_t *gage);
void free_dungeon(proc_t *proc);
void free_gage_game(gage_t *gage);
void next_level_screen(gage_t *gage);
