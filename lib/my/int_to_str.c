/*
** EPITECH PROJECT, 2018
** int_to_str.c
** File description:
** change an int into string
*/

#include "my.h"

int get_upper_nbr(int nbr)
{
	int dis = 1;

	while (dis <= nbr) {
		dis = dis * 10;
	}
	return (dis);
}

int count_chr_nbr(int nbr)
{
	int dis = 1;
	int res = 0;

	while (dis <= nbr) {
		dis = dis * 10;
		res += 1;
	}
	return (res);
}

void is_nbr_neg(int *nbr, int *is_neg)
{
	if (*nbr < 0) {
		*nbr = *nbr * -1;
		*is_neg = 1;
	}
}

void increment_neg(char *result, int *iter, int is_neg)
{
	if (is_neg == 1) {
		*iter += 1;
		result[0] = '-';
	}
}

char *int_to_str(int nbr)
{
	char *result;
	int is_neg = 0;
	int iter = 0;
	int dis = 1;

	if (nbr == 0) {
		result = my_calloc(sizeof(char) * 2);
		result[0] = '0';
		return (result);
	}
	is_nbr_neg(&nbr, &is_neg);
	result = my_calloc(sizeof(char) * (count_chr_nbr(nbr) + is_neg + 1));
	dis = get_upper_nbr(nbr);
	increment_neg(result, &iter, is_neg);
	while (dis > 1) {
		result[iter] = (nbr % dis) / (dis / 10) + 48;
		iter += 1;
		dis = dis / 10;
	}
	return (result);
}
