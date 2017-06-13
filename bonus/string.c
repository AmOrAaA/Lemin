/*
** cnt.c for cnt in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Fri Apr 21 15:18:04 2017 Ryan Granet
** Last update Sun Apr 30 14:07:23 2017 Ryan Granet
*/

#include <stdlib.h>
#include "lem_in.h"

int     strlen_sep(char *str, char sep)
{
  int   i;

  i = 0;
  while (str[i] != '\0' && str[i] != sep)
    i++;
  return (i);
}

char    *my_strcpy(char *str)
{
  char  *cpy;
  int   i;

  i = -1;
  if ((cpy = malloc(sizeof(char) * (strlen_sep(str, ' ') + 1))) == NULL)
    return (NULL);
  while (str[++i] != '\0' && str[i] != ' ')
    cpy[i] = str[i];
  cpy[i] = '\0';
  return (cpy);
}

int     my_strlen_n(int forward, char *str)
{
  int   i;
  int   cnt;

  i = 0;
  cnt = 0;
  while (i++ != forward);
  i++;
  while (str[i] != '\n' && str[i])
    {
      i++;
      cnt++;
    }
  return (cnt);
}

int     add_strlen(char *str, int x)
{
  int   i;

  i = strlen_sep(str, ' ');
  x = i + x + 2;
  return (x - 1);
}
