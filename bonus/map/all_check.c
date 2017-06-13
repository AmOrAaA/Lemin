/*
** all_check.c for  in /home/amoraa/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Fri Apr 14 20:42:03 2017 Florian Testu
** Last update Sun Apr 30 04:25:18 2017 Florian Testu
*/

#include "lem_in.h"

char    *check_start(char **tab)
{
  int   i;
  int	x;
  char  *copy;

  i = -1;
  x = 0;
  copy = NULL;
  while (tab[++i] != NULL)
    {
      if (x > 1)
      	return (NULL);
      if ((my_strcmp("##start", tab[i])) == 0)
	{
	  if ((check_end_ok(tab, i)) != 0)
	      return (NULL);
	  copy = remp_start(copy, tab, i);
	  x++;
	}
    }
  return (copy);
}

int	check_end_ok(char **tab, int i)
{
  int	j;
  int	x;

  i++;
  x = 1;
  j = -1;
  if (tab[i][0] == '#')
    return (84);
  while (tab[i][++j] != ' ');
  while (tab[i][++j] != '\0')
    {
      if (tab[i][j] < '0' || tab[i][j] > '9')
	{
	  if (tab[i][j] == ' ')
	    x++;
	  if (x == 2)
	    break;
	  if (tab[i][j] != ' ')
	    return (84);
	}
    }
  return (0);
}

char    *check_end(char **tab)
{
  int   i;
  int	x;
  char  *copy;

  i = -1;
  copy = NULL;
  x = 0;
  while (tab[++i] != NULL)
    {
      if (x > 1)
	return (NULL);
      if ((my_strcmp("##end", tab[i])) == 0)
        {
	  if ((check_end_ok(tab, i)) == 84)
	    return (NULL);
          copy = remp_start(copy, tab, i);
	  x++;
        }
    }
  return (copy);
}

char	**check_all_path2(int j, char **copy, char **tab, int i)
{
  if (j == 0)
    {
      copy = NULL;
      copy = remp_copy_path(tab, copy, i);
      return (copy);
    }
  else
    return (NULL);
}

char	**check_all_path(char **tab)
{
  int   i;
  int	j;
  char  **copy;

  i = -1;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
	{
	  if (tab[i][j] == '-')
	    {
	      j = 0;
	      break;
	    }
	}
      if (j == 0)
	break;
    }
  copy = NULL;
  if ((copy = check_all_path2(j, copy, tab, i)) == NULL)
    return (NULL);
  return (copy);
}
