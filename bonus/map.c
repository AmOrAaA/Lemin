/*
** map.c for map in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Wed Apr 19 14:10:35 2017 Ryan Granet
** Last update Sun Apr 30 15:01:10 2017 Ryan Granet
*/

#include <stdlib.h>
#include "lem_in.h"

char	**create_empty_map(char **map, t_pars *info)
{
  int	y;
  int	x;

  y = 0;
  if ((map = malloc(sizeof(char *) * (max_y(info->all) + 1))) == NULL)
    return (NULL);
  while (y != max_y(info->all) + 1)
    {
      x = -1;
      if ((map[y] = malloc(sizeof(char) * (max_x(info->all) + 1))) == NULL)
	return (NULL);
      while (++x != max_x(info->all))
	map[y][x] = ' ';
      map[y][x] = '\0';
      y++;
    }
  map[y] = NULL;
  return (map);
}

char	**create_map(t_pars *info)
{
  char	**map;
  t_compt	coor;

  if ((map = create_empty_map(map, info)) == NULL)
    return (NULL);
  if ((map = add_room(map, info)) == NULL)
    return (NULL);
  map = choose_direction(map, coor, info);
  return (map);
}

char	**add_room(char **map, t_pars *info)
{
  int	y;
  int	x;
  int	i;
  char	*name;

  i = -1;
  while (info->all[++i])
    {
      y = found_y(info->all[i]);
      x = found_x(info->all[i]);
      if ((name = my_strcpy(info->all[i])) == NULL)
	return (NULL);
      map = add_new_room(map, y, x, name);
    }
  return (map);
}

char	**add_new_room(char **map, int	axe_y, int start, char *name)
{
  int	i;

  i = 0;
   map[axe_y][start++] = '[';
  while (name[i])
    {
      map[axe_y][start] = name[i];
      i++;
      start++;
    }
  i++;
  map[axe_y][start] = ']';
  return (map);
}
