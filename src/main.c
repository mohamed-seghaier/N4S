/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "include/n4s.h"

int	ia_mazing()
{
	scan_front(putstr(LIDAR, 1));
	mov_front();
	mov_wheels();
	check_wall();
	radar_viewer();
	return (1);
}

int	main()
{
	if (!(g_scan = malloc(sizeof(double) * 32)) ||
	!(g_part = malloc(sizeof(int) * 9)))
		return (84);
	putstr(START, 1);
	while (ia_mazing());
	putstr(STOP, 1);
	free(g_scan);
	free(g_part);
	return (0);
}
