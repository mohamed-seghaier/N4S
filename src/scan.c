/*
** EPITECH PROJECT, 2018
** scan.c
** File description:
** scan.c
*/

#include "include/n4s.h"

void	scan_front(char *str)
{
	int y = 0;
	char **p;

	if ((p = wordtab(str, ':')) != NULL)
		while (y < 32) {
			if (p[y] != NULL)
				g_scan[y] = atof(p[y]);
			else
				g_scan[y] = 0;
			y += 1;
		}
	free(p);
	free(str);
}

void	radar_viewer()
{
	double m = 0;
	int y = 0;
	int n = 0;
	int nb = 0;

	while (y < 32) {
		if (g_scan[y] > m)
			m = g_scan[y];
		y += 1;
	}
	y = 0;
	while (y < 32) {
		n = g_scan[y] / m * 50;
		nb = 50 - n;
		fprintf(stderr, "%d::", y);
		if (n == 50) fprintf(stderr, "%lf::", g_scan[y]);
	        while (n-- > 0)
			putstr("_", 2);
		while (nb-- > 0)
		putstr("#", 2);
		putstr("\n", 2);
		y += 1;
	}
}

int	greater_pos(int *arr, int size, int max)
{
	int y = 0;
	int t = 0;

	while (y < size) {
		fprintf(stderr, "%d:%d\n", y, arr[y]);
		if (arr[y] > t && arr[y] != max)
			t = arr[y];
		y += 1;
	}
	y = 0;
	while (arr[y] != t)
		y += 1;
	fprintf(stderr, "%d", y);
	return (y);
}

int	calc_direction()
{
	int y = 0;
	int n = 0;

	while (y < 8)
		g_part[y++] = 0;
	y = 0;
	while (y < 32) {
		g_part[n] += g_scan[y];
		y += 1;
		if ((y % 4) == 0)
			n += 1;
	}
	n = 0;
	y = 0;
	if (g_scan[15] > 1000 && g_part[0] > 300 && g_part[7] > 300)
		while (y < 8) {
			if (g_part[y] > n)
				n = g_part[y];
			y += 1;
		}
	return (greater_pos(g_part, 8, n));
}
