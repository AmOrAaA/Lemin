/*
** check_path.c for  in /home/amoraa/lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sun Apr 30 01:53:09 2017 Florian Testu
** Last update Sun Apr 30 02:36:28 2017 Florian Testu
*/

#include "lem_in.h"

int     check_path_end1(t_pars *list, char *copy, int i, int y)
{
  int   x;
  int   k;
  int   j;

  x = k = 0;
  j = -1;
  while (list->path[i][++j] != '-')
    {
      if (list->path[i][j] != copy[k] || x > y)
        break;
      k++;
      x++;
    }
  if (x == y)
    return (0);
  return (84);
}

int     check_path_end2(t_pars *list, char *copy, int i, int y)
{
  int   x;
  int   k;
  int   j;

  x = k = 0;
  j = -1;
  while (list->path[i][++j] != '-');
  while (list->path[i][++j] != '\0')
    {
      if (list->path[i][j] != copy[k])
        break;
      k++;
      x++;
    }
  if (x == y)
    return (0);
  return (84);
}

int     check_path_start(t_pars *list)
{
  int   i;
  int   y;
  char  *copy;

  i = -1;
  if ((copy = malloc(sizeof(char) * (my_strlen(list->start)))) == NULL)
    return (84);
  while (list->start[++i] && list->start[i] != ' ')
    copy[i] = list->start[i];
  copy[i] = '\0';
  i = -1;
  y = my_strlen(copy);
  while (list->path[++i] != NULL)
    {
      if ((check_path_end1(list, copy, i, y)) == 0)
        return (0);
      if ((check_path_end2(list, copy, i, y)) == 0)
        return (0);
    }
  return (84);
}

int     check_path_end(t_pars *list)
{
  int   i;
  int   y;
  char  *copy;

  i = -1;
  if ((copy = malloc(sizeof(char) * my_strlen(list->start))) == NULL)
    return (84);
  while (list->end[++i] && list->end[i] != ' ')
    copy[i] = list->end[i];
  copy[i] = '\0';
  i = -1;
  y = my_strlen(copy);
  while (list->path[++i] != NULL)
    {
      if ((check_path_end1(list, copy, i, y)) == 0)
        return (0);
      if ((check_path_end2(list, copy, i, y)) == 0)
        return (0);
    }
  return (84);
}
