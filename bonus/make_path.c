/*
** make_path.c for make path in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Sun Apr 30 13:27:55 2017 Ryan Granet
** Last update Sun Apr 30 15:12:06 2017 Ryan Granet
*/

#include "lem_in.h"

char	**trace_v(t_compt coor, char **map, int a)
{
  if (a == 1)
    {
      coor.y--;
      while (map[coor.y][coor.x] == ' ' && map[coor.y - 1][coor.x])
        map[coor.y--][coor.x] = '|';
    }
  else if (a == -1)
    while (map[coor.y][coor.x] == ' ' && map[coor.y + 1][coor.x])
      map[coor.y++][coor.x] = '|';
  return (map);
}

char	**trace_h(t_compt coor, char **map, int a)
{
  if (a == 1)
    while (map[coor.y][coor.x] == ' ' && map[coor.y][coor.x + 1])
      map[coor.y][coor.x++] = '-';
  else if (a == -1)
    {
      coor.x--;
      while (map[coor.y][coor.x] == ' ' && map[coor.y][coor.x - 1])
        map[coor.y][coor.x--] = '-';
    }
  return (map);
}

char    **trace_path(t_compt coor, char **map, t_trace trace)
{
  if (trace.left_right == 1 && trace.up_down == 0)
    {
      coor.x = coor.x + my_strlen(trace.first_room) + 2;
      map = trace_h(coor, map, 1);
    }
  else if (trace.left_right == 0 && trace.up_down == 1)
    {
      coor.x = coor.x + (my_strlen(trace.first_room) / 2) + 1;
      map = trace_v(coor, map, 1);
    }
  else if (trace.left_right == -1 && trace.up_down == 0)
    map = trace_h(coor, map, -1);
  else if ((trace.left_right == -1 && trace.up_down == -1)
           || trace.left_right == 0)
    {
      coor.x = coor.x + (my_strlen(trace.first_room) / 2) + 1;
      coor.y++;
      map = trace_v(coor, map, -1);
    }
  return (map);
}
