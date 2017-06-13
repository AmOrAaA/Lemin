/*
** cmp.c for cmp in /home/Nyavenger/Colles/CPE_2016_stumper1
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Tue Apr 18 16:01:06 2017 Jonathan Delestre
** Last update Wed Apr 19 11:17:48 2017 Jonathan Delestre
*/

#include "lem_in.h"

int	my_cmp(char *s1, char *s2)
{
  int	i;

  i = -1;
  if (my_strlen(s2) > my_strlen(s1))
    return (1);
  while (s2[++i])
    if (s2[i] != s1[i])
      return (1);
  if (s2[i] != s1[i])
    return (1);
  return (0);
}

int	my_ccmp(char *s1, char *s2)
{
  int	i;

  i = -1;
  if (my_strlen(s2) > my_strlen(s1))
    return (1);
  while (s2[++i])
    if (s2[i] != s1[i])
      return (1);
  return (0);
}
