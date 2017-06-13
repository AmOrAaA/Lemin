/*
** print_error.c for  in /home/AmOrAA/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Tue Apr 25 10:45:20 2017 Florian Testu
** Last update Tue Apr 25 11:20:26 2017 Florian Testu
*/

#include "lem_in.h"

void    print_error(char **tab, int x)
{
  int   j;

  print_ants(tab);
  j = 0;
  my_putstr("\n#rooms\n");
  while (++j != x)
    {
      if (tab[j][0] == '#')
        x++;
    }
  j = 0;
  print_error_second(tab, j, x);
}

void    print_error_second_path_second(char **tab, int j)
{
  if (tab[j][0] == '#')
    {
      if ((my_strcmp("##start", tab[j])) != 0
          && (my_strcmp("##end", tab[j])) != 0);
      else
        {
          my_putstr(tab[j]);
          my_putchar('\n');
        }
    }
  else
    {
      my_putstr(tab[j]);
      my_putchar('\n');
    }
}

void    print_error_second_path(char **tab, int j, int x, int i)
{
  int   k;

  while (++j <= x)
    {
      if (i >= 1)
        {
          k = -1;
          while (tab[j][++k] != '\0')
            {
              if (tab[j][k] == '-')
                {
                  my_putstr("##tunnels\n");
                  i = -1;
                  break;
                }
            }
        }
      print_error_second_path_second(tab, j);
    }
}

void    print_error_second(char **tab, int j, int x)
{
  while (++j < x)
    {

      if (tab[j][0] == '#')
        {
          if ((my_strcmp("##start", tab[j])) != 0
              && (my_strcmp("##end", tab[j])) != 0);
          else
            {
              my_putstr(tab[j]);
              my_putchar('\n');
            }
        }
      else
        {
          my_putstr(tab[j]);
          my_putchar('\n');
        }
     }
  my_putstr(tab[j + 1]);
  my_putchar('\n');
}

void    print_error_path(char **tab, int x, int i)
{
  int   j;

  print_ants(tab);
  j = 0;
  my_putstr("\n#rooms\n");
  while (++j <= x)
    {
      if (tab[j][0] == '#')
        x++;
    }
  j = 0;
  print_error_second_path(tab, j, x, i);
}
