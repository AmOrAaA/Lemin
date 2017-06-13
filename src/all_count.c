/*
** all_count.c for  in /home/AmOrAA/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Sat Apr 22 14:56:16 2017 Florian Testu
** Last update Sat Apr 29 16:17:52 2017 Florian Testu
*/

#include "lem_in.h"

int     check_comment(char **tab, int j)
{
  int   i;

  i = -1;
  while (tab[j][++i] != '\0')
    {
      if (tab[j][i] == '#')
        return (1);
    }
  return (0);
}

int     check_room(char **tab, char *copy)
{
  int   i;

  i = -1;
  while (tab[++i] != NULL)
    {
      if ((my_strcmp(tab[i], copy)) == 0)
        return (0);
    }
  return (84);
}

int     strd(char *str, int j)
{
  int   y;

  y = 0;
  while (str[++j] != '\0')
    y++;
  return (y);
}

int     my_stlen(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0');
  return (i);
}
