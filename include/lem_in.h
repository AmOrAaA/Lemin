/*
** lem_in.h for lem_in in /home/Broscas/CPE_2016_Lemin/include
** 
** Made by Ryan Granet
** Login   <Broscas@epitech.net>
** 
** Started on  Mon Apr 10 11:59:42 2017 Ryan Granet
** Last update Sun Apr 30 15:58:43 2017 Florian Testu
*/

#ifndef LEMIN_H_
# define LEMIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my.h"

int		printed;

typedef struct	s_pars
{
  int		nbr;
  char		*start;
  char		*end;
  char		**all;
  char		**path;
  char		**file;
}		t_pars;

typedef struct	s_hill
{
  int		ant;
  int		posx;
  int		posy;
  int		start;
  int		end;
  char		*name;
  char		**link;
  struct s_hill	*next;
  struct s_hill	*prev;
}		t_hill;

typedef struct	s_compt
{
  int		k;
  int		x;
  int		j;
  int		y;
}		t_compt;

typedef struct  s_trace
{
  int   left_right;
  int   up_down;
  char  *first_room;
  char  *sec_room;
}               t_trace;

void	print_error(char **, int);
void	print_error_path(char **, int, int);
void	print_ants(char **);
void	print_error_second(char **, int, int);
void	print_number_all(t_pars);
void	print_if_second_ok1(int, int);
void	print_if_second_ok2(char **, int, int);
void	print_if_second_ok3(char **, int);
void	init_hill(t_hill **hill, t_pars *list);
void	add_hill(t_hill **hill, t_pars *list, int pos);
void	fill_path(t_hill **hill, t_pars *list);
void	mem_free(t_pars *list);
void	my_print_map(char **);

int	path_end(t_hill *hill, char **link);
int	lemin(t_pars *list);
int	move_ant(t_hill *hill, int ant_nb, char **link, int max);
int	add_ants(t_hill *hill, int max_ants);
int	print_error_start(int, char **);
int	print_error_end(int, char **);
int	print_if_second_ok(char **, int);
int	print_if_ok(char **);
int	main();
int	my_cmp(char *, char *);
int	my_ccmp(char *, char *);
int	max_y(char **);
int	my_put_errnbr(int);
int	coor_check(char **);
int	my_cmp(char *, char *);
int	my_puterr(char *, int);
int	my_retstr(char *, int);
int	my_ccmp(char *, char *);
int	check_file_nbr(char **);
int	all_check_end(t_pars *);
int	strlen_spe(char *, char);
int	check_comment(char **, int);
int	check_my_coor_tab(char **);
int	check_double_coor_tab(char **);
int	my_mod_strlen_at_the_line(char *, char );
int	my_mod_len_space(char *, char );
int	my_stlen(char *);
int	check_room(char **, char *);
int	strd(char *, int);
int	check_idem_path_second(t_pars *, char *, int);
int	check_idem_room_second(char **, char *, int);
int	check_double_path(t_pars *);
int	check_error_path(t_pars *, char **);
int	check_idem_path(t_pars *);
int	check_idem_room(t_pars *);
int	check_end_ok(char **, int);
int	my_file(t_pars *);
int	check_path_end(t_pars *);
int	check_path_end1(t_pars *, char *, int, int);
int	check_path_end2(t_pars *, char *, int, int);
int	check_path_start(t_pars *);
int     get_nb_all(t_pars *, char *);
int     my_strlen_n(int, char *);
int     left_or_right(t_compt, char *);
int     up_or_down(t_compt);
int     found_x(char *);
int     found_y(char *);
int     strlen_sep(char *, char);
int     max_x(char **);
int	add_strlen(char *, int);

char	*my_strcpy(char *);
char	*check_end(char **);
char	*check_start(char **);
char	*take_my_room(t_pars *);
char	*remp_start(char *, char **, int);
char    *get_room(char *, int);

char	**create_map(t_pars *);
char	**check_all_file(char **);
char	**check_all_path(char **);
char	**my_str_to_wordtab(char *);
char    **add_room(char **, t_pars *);
char	**remp_copy(char **, char **, int);
char	**create_empty_map(char **, t_pars *);
char    **add_new_room(char **, int, int, char *);
char	**remp_copy_path(char **, char **, int);
char	**my_mod_str_to_wordtab(char *, char );
char	**full_tab(char **, char *, char, int);
char    **choose_direction(char **, t_compt, t_pars *);
char    **trace_path(t_compt, char **, t_trace);
char    **right_or_left(t_compt, t_pars *, int, char **);
char    **trace_h(t_compt, char **, int);
char    **trace_v(t_compt, char **, int);

#endif
