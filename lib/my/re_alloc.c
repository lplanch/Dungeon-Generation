/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** best project
*/

#include <stdlib.h>
#include "my.h"

char *my_re_alloc(char *str, int value)
{
	char *str2 = my_calloc(sizeof(char) * value);

	my_strcpy(str2, str);
	free(str);
	return (str2);
}
