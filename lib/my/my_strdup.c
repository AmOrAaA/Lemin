/*
** my_strdup.c for my_strdup in /home/Nyavenger/PSU/PSU_2016_minishell2/lib/my
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Thu Apr  6 09:59:23 2017 Jonathan Delestre
** Last update Fri Apr 21 17:59:43 2017 Jonathan Delestre
*/

#include "my.h"

char	*my_strdup(char *str)
{
  char	*dup;
  int	x;

  x = -1;
  if ((dup = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[++x] != 0)
    dup[x] = str[x];
  dup[x] = '\0';
  return (dup);
}
