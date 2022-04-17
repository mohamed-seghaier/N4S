/*
** EPITECH PROJECT, 2018
** move.c
** File description:
** move.c
*/

#include "include/n4s.h"

double	split_wheels(int axe)
{
	double d = 0;

	if (axe == -1)
		return (axe);
	if (axe == 0 || axe == 7)
		d = 0.2;
	else if (axe == 1 || axe == 6)
		d = 0.13;
	else if (axe == 2 || axe == 5)
		d = 0.08;
	else if (axe == 3 || axe == 4)
		d = 0.05;
	if (axe >= 4)
		d *= -1;
	return (d);
}

void	mov_wheels()
{
	double a;
	double d;
	char buf[15];
	char *m_str;

	if ((d = split_wheels(calc_direction())) == -1)
		return ;
	a = g_scan[15];
	if (g_part[0] < g_part[7] * 0.1)
		a = 200;
	else if (g_part[7] < g_part[0] * 0.1)
		a = 200;
	if (a <= 1000)
		d *= (1 + (1 - (a / 600)));
	else
		d /= 2;
	fprintf(stderr, "<<%lf>>\n", d);
	m_str = stkstr(stkstr("WHEELS_DIR:", gcvt(d, 10, buf)), "\n");
	putstr(m_str, 1);
}

void	mov_front()
{
	char buf[15];
	char *s_str;
	double sd = 0;

	if (g_scan[15] < 1000)
		sd = g_scan[15];
	else if (g_scan[20] < 1000)
		sd = g_scan[20];
	else if (g_scan[10] < 1000)
		sd = g_scan[10];
	if (sd == 0) {
		putstr("car_forward:0.8\n", 1);
		return ;
	}
	sd /= 1000;
	if (g_scan[15] < 200)
		sd = 0.1;
	s_str = stkstr(stkstr("CAR_FORWARD:", gcvt(sd, 10, buf)), "\n");
	putstr(s_str, 1);
}

void    check_wall()
{
	int y = 0;
	double wd;
	char buf[10];
	char *d;
	int ct = 0;

	while (y < 32) {
		if (g_scan[y] < 100)
			ct += 1;
		y += 1;
	}
	if (ct < 4)
		return ;
	wd = atof(putstr(WHEEL, 1));
	d = stkstr(stkstr("WHEELS_DIR:", gcvt((wd * -1), 10, buf)), "\n");
	putstr(d, 1);
	putstr("CAR_BACKWARDS:0.3\n", 1);
	sleep(4);
	putstr("CAR_FORWARD:0.05\n", 1);
}
