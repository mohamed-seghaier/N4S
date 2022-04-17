/*
** EPITECH PROJECT, 2018
** n4s.h
** File description:
** n4s.h
*/

#ifndef N4S_H_
# define N4S_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define START	"START_SIMULATION\n"
# define STOP	"STOP_SIMULATION\n"
# define LIDAR	"GET_INFO_LIDAR\n"
# define INFO	"GET_INFO_SIMTIME\n"
# define WHEEL	"GET_CURRENT_WHEELS\n"
# define SPEED	"GET_CURRENT_SPEED\n"

double	*g_scan;
int	*g_part;

int	main();
int	ia_mazing();
void	mov_wheels();
int	calc_direction();
void	radar_viewer();
void	scan_front(char *);
void	mov_front();
void	check_wall();
char	**wordtab(char *, char);
char	*stkstr(char *, char *);
char	*grabstr(char *, int, int, char);
char	*get_line(const int);
char	*reall_add(char *, char);
double	isfloat(char *);
char	*putstr(char *, int);

#endif /*N4S_H_*/
