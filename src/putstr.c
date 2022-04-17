/*
** EPITECH PROJECT, 2018
** putstr.c
** File description:
** putstr.c
*/

#include "include/n4s.h"

char	*get_data(char *ans, int i, int min, int max)
{
	int tmp;
	char *new;

	while (max != 3)
		if (ans[min++] == ':')
			max++;
	max = strlen(ans);
	while (ans[--max] != ':')
        tmp = strlen(ans) - min - (strlen(ans) - max);
	if (!(new = malloc(tmp + 1)))
		return (NULL);
	while (i + min < max) {
		new[i] = ans[i + min];
		i++;
	}
	new[i] = 0;
	if (new[0] == 'T') {
		putstr(new, 2);
		exit(EXIT_SUCCESS);
	}
	free(ans);
	return (new);
}

int	strnchar(char *str, char c)
{
	int i = 0;
	int count = 0;

	if (str == NULL)
		return (0);
        while (str[i]) {
		if (str[i] == c)
			count += 1;
		i += 1;
	}
	return (count);
}

char	*putstr(char *str, int fd)
{
	if (str != NULL)
		write(fd, str, strlen(str));
	if (fd != 1)
		return (NULL);
	str = get_line(0);
	if (strnchar(str, ':') <= 3)
		return (NULL);
	str = get_data(str, 0, 0, 0);
	return (str);
}
