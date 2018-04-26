/*
** EPITECH PROJECT, 2018
** my sort params
** File description:
** sort params
*/

#include "my.h"

int count_nbr_str(char **table)
{
	int len = 0;

	while (table[len] != NULL) {
		len = len + 1;
	}
	return (len);
}

char **my_sort_params(char **table)
{
	int i = 0;
	int j = 1;
	int len = count_nbr_str(table);
	char *temp;

	while (i < len) {
		while (j < len) {
			if (my_strcmp(table[i], table[j]) < 0) {
				temp = table[i];
				table[i] = table[j];
				table[j] = temp;
			} else
				j = j + 1;
		}
		j = 0;
		i = i + 1;
	}
	return (table);
}
