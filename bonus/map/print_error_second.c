/*
** print_error_second.c for  in /home/AmOrAA/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Tue Apr 25 11:14:43 2017 Florian Testu
** Last update Sat Apr 29 17:53:30 2017 Florian Testu
*/

#include "lem_in.h"

char    *my_epur_str(char *str)
{
  int   i;
  int   j;
  char  *copy;

  if ((copy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] == ' ' && str[i + 1] == ' ');
      else
        {
	  if ((i == 0 && str[i] == ' ') ||
	      (i == 1 && str[i] == ' ' && str[i - 1] == ' '));
	  else
	    {
	      copy[j] = str[i];
	      j++;
	    }
        }
    }
  copy[j] = 0;
  return (copy);
}

void    print_ants(char **tab)
{
  my_putstr("#number_of_ants\n");
  my_putstr(tab[0]);
}

int	check_char(char **tab, int i)
{
  int	j;

  j = -1;
  while (tab[i][++j] != '\0')
    {
      if (tab[i][j] == '-')
	return (0);
    }
  return (84);
}

int	check_space(char **tab, int i, int x)
{
  int	j;

  if (i > x)
    {
      j = -1;
      while (tab[i] && tab[i][++j] != '\0')
	{
	  if (tab[i][j] < '0' || tab[i][j] > '9')
	    {
	      if ((check_char(tab, i)) == 84)
	      	{
	      	  my_putstr("#moves\n");
	      	  return (84);
	      	}
	    }
	}
      if (j <= 1)
	{
	  my_putstr("#moves\n");
	  return (84);
	}
    }
  return (0);
}

int    print_if_second_ok(char **tab, int x)
{
  int   i;
  int   j;

  i = 0;
  while (tab[++i] != NULL)
    {
      tab[i] = my_epur_str(tab[i]);
      print_if_second_ok1(i, x);
      if (tab[i][0] == '#')
	print_if_second_ok3(tab, i);
      else
        {
          j = check_space(tab, i, x);
          if (j == 84)
            return (84);
          else if (j == 1)
            break;
          print_if_second_ok2(tab, i, x);
        }
    }
  return (0);
}
