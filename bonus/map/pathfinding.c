/*
** pathfinding.c for pathfinding in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Wed Apr 26 10:01:48 2017 Jonathan Delestre
** Last update Wed Apr 26 11:42:07 2017 Jonathan Delestre
*/

#include "lem_in.h"

int		path_end(t_hill *hill, char **link)
{
  int		i;

  i = -1;
  while (link[++i])
    {
      while (hill->prev != NULL)
	hill = hill->prev;
      while (hill->next != NULL)
	{
	  if (my_cmp(hill->name, link[i]) == 0 && hill->end >= 0)
	    return (i);
	  hill = hill->next;
	}
      if (my_cmp(hill->name, link[i]) == 0 && hill->end >= 0)
	return (i);
    }
  return (-1);
}
