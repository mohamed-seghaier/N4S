/*
** EPITECH PROJECT, 2018
** isfloat.c
** File description:
** isfloat.c
*/

#include "include/n4s.h"

double	isfloat(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i]) {
		if (str[i] == ':')
			break;
		if ((str[i] < '0' && str[i] != '.') || str[i] > '9')
			return (-1);
		i++;
	}
	return (atof(str));
}
