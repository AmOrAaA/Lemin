/*
** room.c for room in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Sun Apr 30 12:54:50 2017 Ryan Granet
** Last update Sun Apr 30 13:12:54 2017 Ryan Granet
*/

#include <stdlib.h>
#include "lem_in.h"

char	*get_room(char *info, int nb)
{
  char	*str;
  int	a;
  int	i;
  int	cnt;

  i = cnt = -1;
  a = strlen_sep(info, '-');
  if (nb == 1)
    {
      if ((str = malloc(sizeof(char) * (a + 1))) == NULL)
        return (NULL);
      while (info[++i] != '-')
        str[i] = info[i];
      str[i] = '\0';
    }
  if (nb == 2)
    {
      if ((str = malloc(sizeof(char) * (my_strlen_n(a, info) + 1))) == NULL)
        return (NULL);
      i = a;
      while (info[++i])
        str[++cnt] = info[i];
      str[++cnt] = '\0';
    }
  return (str);
}
