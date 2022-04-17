/*
** EPITECH PROJECT, 2018
** str_to_wordtab.c
** File description:
** str_to_wordtab.c
*/

#include "include/n4s.h"

char	*grabstr(char *str, int seplvl, int i, char c)
{
	int y = 0;
	char *new;

	while (i < seplvl) {
		if (str[y] == c)
			i += 1;
		y += 1;
	}
	i = 0;
	while (str[i] != c)
		i += 1;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[y] != c && str[y]) {
		new[i] = str[y];
		i += 1;
		y += 1;
	}
	new[i] = 0;
	return (new);
}

char	**wordtab(char *str, char c)
{
	int i = 1;
	int y = 0;
	char **new;

	if (!str)
		return (NULL);
	while (str[y]) {
		if (str[y] == c)
			i+= 1;
		y += 1;
	}
	if ((new = malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	y = 0;
	while (y < i) {
		new[y] = grabstr(str, y, 0, c);
		y += 1;
	}
	new[y] = NULL;
	return (new);
}
