/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != 0) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
