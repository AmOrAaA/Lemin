/*
** ants.c for ants in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Sat Apr 22 19:03:21 2017 Jonathan Delestre
** Last update Sat Apr 29 14:23:14 2017 Jonathan Delestre
*/

#include "lem_in.h"

int	print_ant(int ant, char *name)
{
  printed++;
  if (printed > 0)
    my_putchar(' ');
  my_putchar('P');
  my_put_nbr(ant);
  my_putchar('-');
  my_putstr(name);
  return (ant);
}

int	process_ant(t_hill *hill, int ant_nb)
{
  if (hill->ant == 0)
    {
      print_ant(ant_nb, hill->name);
      hill->end++;
    }
  else
    hill->ant = print_ant(ant_nb, hill->name);
  return (-1);
}

int	move_ant(t_hill *hill, int ant_nb, char **link, int max)
{
  int	i;

  i = -1;
  if (ant_nb == max)
    i++;
  if (path_end(hill, hill->link) != -1)
    i = path_end(hill, hill->link) -1;
  while (link[++i])
    {
      while (hill->prev != NULL)
	hill = hill->prev;
      while (hill->next != NULL)
	{
	  if (my_cmp(hill->name, link[i]) == 0 && hill->ant <= 0)
	    return (process_ant(hill, ant_nb));
	  hill = hill->next;
	}
      if (my_cmp(hill->name, link[i]) == 0 && hill->ant <= 0)
	return (process_ant(hill, ant_nb));
    }
  return (ant_nb);
}

int	spawn_ants(t_hill *hill, int max_ants, char **link)
{
  int	ant_nb;
  int	i;

  i = -1;
  ant_nb = max_ants;
  while (link[++i])
    {
      while (hill->prev != NULL)
	hill = hill->prev;
      while (hill->next != NULL)
	{
	  if (my_cmp(hill->name, link[i]) == 0 && hill->ant <= 0)
	    {
	      ant_nb++;
	      process_ant(hill, ant_nb);
	    }
	  hill = hill->next;
	}
      if (my_cmp(hill->name, link[i]) == 0 && hill->ant <= 0)
	{
	  ant_nb++;
	  process_ant(hill, ant_nb);
	}
    }
  return (ant_nb - max_ants);
}

int	add_ants(t_hill *hill, int max_ants)
{
  int	added;

  added = 0;
  while (hill->prev != NULL)
    hill = hill->prev;
  while (hill->next != NULL)
    {
      if (hill->start >= 0)
	hill->start -= (added = spawn_ants(hill, max_ants, hill->link));
      hill = hill->next;
    }
  if (hill->start >= 0)
    hill->start -= (added = spawn_ants(hill, max_ants, hill->link));
  while (hill->prev != NULL)
    hill = hill->prev;
  return (added);
}
