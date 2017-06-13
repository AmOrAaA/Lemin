/*
** print_error_four.c for  in /home/amoraa/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat Apr 29 17:51:56 2017 Florian Testu
** Last update Sat Apr 29 17:52:54 2017 Florian Testu
*/

#include "lem_in.h"

int     print_error_end(int i, char **tab)
{
  int   x;

  my_putstr("#number_of_ants\n");
  my_putstr(tab[0]);
  my_putstr("\n#rooms\n");
  x = 0;
  i = 0;
  while (tab[++i] != NULL)
    {
      if ((my_strcmp("##end", tab[i])) == 0)
        {
          x = x + 1;
          if (x == 2)
            return (0);
        }
      my_putstr(tab[i]);
      my_putchar('\n');
    }
  return (0);
}

int     print_error_start(int i, char **tab)
{
  int   x;

  my_putstr("#rooms\n");
  x = 0;
  i = 0;
  while (tab[++i] != NULL)
    {
      if ((my_strcmp("##start", tab[i])) == 0)
        {
          x = x + 1;
          if (x == 2)
            return (0);
        }
      my_putstr(tab[i]);
      my_putchar('\n');
    }
  return (0);
}

int    print_if_ok(char **tab)
{
  int   i;
  int   j;
  int   x;

  i = -1;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
        {
          if (tab[i][j] == '-')
            {
              j = -1;
              break;
            }
        }
      if (j == -1)
        break;
    }
  x = i;
  if ((print_if_second_ok(tab, x)) == 84)
    return (84);
  return (0);
}
