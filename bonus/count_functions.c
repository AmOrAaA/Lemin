/*
** count_functions.c for count in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Sun Apr 30 13:50:47 2017 Ryan Granet
** Last update Sun Apr 30 15:01:14 2017 Ryan Granet
*/

#include "lem_in.h"

int     max_x(char **all)
{
  char  *str;
  int   x;
  int   y;
  int   max;

  max = 0;
  x = 0;
  y = 0;
  while (all[y])
    {
      while (all[y][x++] && all[y][x] != ' ');
      x++;
      while (all[y][x++] && all[y][x] != ' ');
      x++;
      if ((str = my_strcpy(&all[y][x])) == NULL)
	return (-84);
      x = my_getnbr(str);
      x = add_strlen(all[y], x);
      if (x > max)
        max = x;
      x = 0;
      free(str);
      y++;
    }
  return (max);
}

int     found_y(char *axe_y)
{
  int   i;
  int   y;
  char  *cpy;

  i = 0;
  while (axe_y[i++] != ' ');
  if ((cpy = my_strcpy(&axe_y[i])) == NULL)
    return (-84);
  y = my_getnbr(cpy);
  return (y);
}

int     max_y(char **all)
{
  char  *str;
  int   y;
  int   x;
  int   max;

  max = 0;
  x = 0;
  y = 0;
  while (all[y])
    {
      while (all[y][x++] != ' ');
      if ((str = my_strcpy(&all[y][x])) == NULL)
	return (-84);
      x = my_getnbr(str);
      if (x > max)
        max = x;
      x = 0;
      free(str);
      y++;
    }
  return (max);
}

int     found_x(char *axe_y)
{
  int   i;
  int   x;
  char  *cpy;

  i = 0;
  while (axe_y[i++] != ' ');
  i++;
  while (axe_y[i++] != ' ');
  if ((cpy = my_strcpy(&axe_y[i])) == NULL)
    return (-84);
  x = my_getnbr(cpy);
  return (x);
}
