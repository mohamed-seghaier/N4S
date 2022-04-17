/*
** EPITECH PROJECT, 2018
** stkstr.c
** File description:
** stkstr.c 
*/

#include "include/n4s.h"

char	*stkstr(char *sta, char *stb)
{
	int i;
	char *new;

	if (!sta || !stb)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (strlen(sta) + strlen(stb) + 1))))
		return (NULL);
	i = 0;
	while (sta[i]) {
		new[i] = sta[i];
		i += 1;
	}
	while (stb[i - strlen(sta)]) {
		new[i] = stb[i - strlen(sta)];
		i += 1;
	}
	new[i] = 0;
	return (new);
}
