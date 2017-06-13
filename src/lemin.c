/*
** lemin.c for lemin in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Fri Apr 21 16:51:02 2017 Jonathan Delestre
** Last update Sat Apr 29 15:42:41 2017 Jonathan Delestre
*/

#include "lem_in.h"

void		fill_hill(t_hill *hill, t_pars *list)
{
  int		i;

  i = -1;
  while (list->all[++i])
    {
      if (i == 0)
	init_hill(&hill, list);
      else
	add_hill(&hill, list, i);
    }
  hill->next = NULL;
  while (hill->prev != NULL)
    hill = hill->prev;
}

int		check_exit(t_hill *hill, t_pars *list)
{
  int		ret;

  ret = 0;
  printed = -1;
  while (hill->prev != NULL)
    hill = hill->prev;
  while (hill->next != NULL)
    {
      if (hill->end >= 0)
	if (hill->end == list->nbr)
	  ret = 1;
      hill = hill->next;
    }
  if (hill->end >= 0)
    if (hill->end == list->nbr)
      ret = 1;
  while (hill->prev != NULL)
    hill = hill->prev;
  return (ret);
}

int		init_var()
{
  printed = -1;
  return (1);
}

int		game(t_hill *hill, t_pars *list)
{
  int		max_ants;
  int		ant_nb;

  max_ants = 0;
  while (check_exit(hill, list) != 1)
    {
      ant_nb = init_var();
      while (ant_nb <= list->nbr)
	{
	  if (hill->ant == ant_nb || hill->next == NULL)
	    {
	      if (hill->ant == ant_nb)
		hill->ant = move_ant(hill, ant_nb, hill->link, list->nbr);
	      ant_nb += 1;
	      while (hill->prev != NULL)
		hill = hill->prev;
	    }
	  else
	    hill = hill->next;
	}
      if (max_ants < list->nbr)
	max_ants += add_ants(hill, max_ants);
      my_putchar('\n');
    }
  return (0);
}

int		lemin(t_pars *list)
{
  t_hill	*hill;

  my_putstr("#moves\n");
  if ((hill = malloc(sizeof(t_hill))) == NULL)
    return (84);
  fill_hill(hill, list);
  if (game(hill, list) == 84)
    return (84);
  mem_free(list);
  return (0);
}
