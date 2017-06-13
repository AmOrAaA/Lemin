/*
** my_strncpy.c for my_strncopy in /home/Nyavenger/CPool_Day06
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Mon Oct 10 09:44:22 2016 Jonathan Delestre
** Last update Sat Apr 22 02:00:41 2017 Jonathan Delestre
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	count;

  count = 0;
  while (count < n)
    {
      dest[count] = src[count];
      count = count + 1;
    }
  dest[count] = '\0';
  return (dest);
}

char	*my_strxncpy(char *dest, char *src, int n, int x)
{
  int	count;
  int	start;

  count = x;
  start = 0;
  while (count < x + n)
    {
      dest[start] = src[count];
      count += 1;
      start += 1;
    }
  dest[start] = '\0';
  return (dest);
}
