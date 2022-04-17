/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "include/n4s.h"

char	*reall_add(char *str, char c)
{
	char *n;
	int y = strlen(str);

	if ((n = malloc(sizeof(char) * (y + 2))) == NULL)
		return (NULL);
	y = 0;
	while (str[y]) {
		n[y] = str[y];
		y += 1;
	}
	n[y++] = c;
	n[y] = '\0';
	free(str);
	return (n);
}

char	*get_line(const int fd)
{
	char *str = strdup("");
	char c = 0;

	while (read(fd, &c, 1) > 0 && c != '\n')
		if ((str = reall_add(str, c)) == NULL)
			return (NULL);
	if (strcmp(str, "") == 0 && c == 0)
		return (NULL);
	return (str);
}
