/*
** EPITECH PROJECT, 2017
** my_put_pixel.c
** File description:
** draw a pixel on the screen
*/

#include "my.h"
#include "procedural.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *buffer;
	int bitsPerPixel = 32;

	buffer = malloc(sizeof(framebuffer_t));
	buffer->width = width;
	buffer->height = height;
	buffer->pixels = malloc(width * height * (bitsPerPixel / 8));
	for (int i = 0; i < (width * height * (bitsPerPixel / 8)); i++)
                buffer->pixels[i] = 255;
	return (buffer);
}

void my_put_pixel(framebuffer_t *buffer, int x, int y, sfColor color)
{
	int a = 0;

	if (x < 0 || WIDTH <= x || y < 0 || HEIGHT <= y)
		return;
	a = (y * buffer->width + x) * 4;
	buffer->pixels[a] = color.r;
	buffer->pixels[a + 1] = color.g;
	buffer->pixels[a + 2] = color.b;
	buffer->pixels[a + 3] = color.a;
}
