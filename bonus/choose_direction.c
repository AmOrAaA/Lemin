/*
** choose_direction.c for dir in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Thu Apr 27 17:16:38 2017 Ryan Granet
** Last update Thu May  4 08:26:23 2017 Ryan Granet
*/

#include "lem_in.h"

char	**choose_direction(char **map, t_compt coor, t_pars *info)
{
  int	i;

  i = -1;
  while (info->path[++i])
    {
      map = right_or_left(coor, info, i, map);
    }
   my_print_map(map);
  return (map);
}

char	**right_or_left(t_compt coor, t_pars *info, int i, char **map)
{
  int	first;
  int	sec;
  t_trace	trace;

  if ((trace.first_room = get_room(info->path[i], 1)) == NULL)
    return (NULL);
  if ((trace.sec_room = get_room(info->path[i], 2)) == NULL)
    return (NULL);
  first = get_nb_all(info, trace.first_room);
  if ((coor.x = found_x(info->all[first])) == -84)
    return (NULL);
  if ((coor.y = found_y(info->all[first])) == -84)
    return (NULL);
  sec = get_nb_all(info, trace.sec_room);
  coor.j = found_x(info->all[sec]);
  coor.k = found_y(info->all[sec]);
  trace.up_down = up_or_down(coor);
  trace.left_right = left_or_right(coor, trace.first_room);
  map = trace_path(coor, map, trace);
  return (map);
}

int	left_or_right(t_compt coor, char *first_room)
{
  int	result;

  if (coor.x > coor.j)
    result = -1;
  else if (coor.x <= coor.j)
    if ((coor.x + (my_strlen(first_room) + 1)) > coor.j)
      result = 0;
    else if (coor.x + (my_strlen(first_room) + 1) < coor.j)
      result = 1;
  return (result);
}

int	up_or_down(t_compt coor)
{
  int	result;

  if (coor.y > coor.k)
    result = 1;
  else if (coor.y == coor.k)
    result = 0;
  else if (coor.y < coor.k)
    result = -1;
  return (result);
}

int	get_nb_all(t_pars *info, char *name)
{
  int	i;

  i = 0;
  while ((my_strcmp(name, info->all[i])) != 0)
    i++;
  return (i);
}
