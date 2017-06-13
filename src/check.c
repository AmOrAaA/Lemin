/*
** check.c for  in /home/amoraa/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat Apr 29 17:45:11 2017 Florian Testu
** Last update Sat Apr 29 17:47:55 2017 Florian Testu
*/

#include "lem_in.h"

int     check_file_nbr1(char **tab)
{
  if (tab[0][0] == '#')
    return (84);
  if (tab[0][0] == '\0' && tab[1] == NULL)
    {
      my_putstr("#number_of_ants\n");
      return (84);
    }
  return (0);
}

int     check_file_nbr2(int nbr, char **tab)
{
  my_putstr("#number_of_ants\n");
  my_put_nbr(nbr);
  my_putchar('\n');
  if (tab[2] == NULL)
    return (84);
  return (0);
}

int     check_file_nbr3(char *copy)
{
  if (copy == NULL || copy[0] == '\0')
    {
      my_putstr("#number_of_ants\n");
      return (84);
    }
  return (0);
}

int     check_file_nbr(char **tab)
{
  int   i;
  int   nbr;
  char  *copy;

  i = -1;
  if ((check_file_nbr1(tab)) != 0)
    return (84);
  while (tab[0][++i] != '\0');
  if ((copy = malloc(sizeof(char) * i + 1)) == NULL)
    return (0);
  i = -1;
  while (tab[0][++i] != '\0')
    {
      if (tab[0][i] < '0' && tab[0][i] > '9')
        return (84);
      copy[i] = tab[0][i];
    }
  if ((check_file_nbr3(copy)) != 0)
    return (0);
  copy[i] = '\0';
  nbr = my_getnbr(copy);
  if ((check_file_nbr2(nbr, tab)) != 0)
    return (84);
  return (nbr);
}

char    **check_all_file(char **tab)
{
  int   i;
  int   j;
  int   x;
  char  **copy;

  i = -1;
  x = 0;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
        {
          if (tab[i][j] == '-')
            x++;
        }
      if (x > 0)
        {
          copy = NULL;
          copy = remp_copy(tab, copy, i);
          break;
        }
    }
  return (copy);
}
