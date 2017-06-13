/*
** main.c for main in /home/Broscas/CPE_2016_Lemin/src
** 
** Made by Ryan Granet
** Login   <Broscas@epitech.net>
** 
** Started on  Mon Apr 10 11:58:19 2017 Ryan Granet
** Last update Sun Apr 30 13:36:14 2017 Ryan Granet
*/

#include "lem_in.h"

char   	*remp_start(char *copy, char **tab, int i)
{
  int  	j;
  int  	k;

  j = -1;
  k = 0;
  i++;
  if (tab[i][0] == '\0')
    return (NULL);
  while (tab[i][++j] != '\0');
  if ((copy = malloc(sizeof(char) * j + 1)) == NULL)
    return (NULL);
  j = -1;
  while (tab[i][++j] != '\0')
    {
      if (tab[i][j] < '0' && tab[i][j] > '9' && tab[i][j] != ' ')
	return (0);
      copy[k] = tab[i][j];
      k++;
    }
  copy[k] = '\0';
  return (copy);
}

char   	**remp_copy_path(char **tab, char **copy, int i)
{
  t_compt	compt;

  compt.y = i - 1;
  while (tab[++compt.y] != NULL);
  copy = malloc(sizeof(char*) * compt.y + 1);
  compt.k = 0;
  compt.j = i - 1;
  while (tab[++compt.j] != NULL)
  {
    if ((check_comment(tab, compt.j)) != 1)
      {
	compt.x = my_strlen(tab[compt.j]);
	copy[compt.k] = malloc(sizeof(char) * compt.x + 1);
	compt.x = -1;
	while (tab[compt.j][++compt.x] != '\0')
	  {
	    if (tab[compt.j][compt.x] == ' ')
	      return (NULL);
	    copy[compt.k][compt.x] = tab[compt.j][compt.x];
	  }
	copy[compt.k++][compt.x] = '\0';
      }
  }
  copy[compt.k] = NULL;
  return (copy);
}

char   	**remp_copy(char **tab, char **copy, int i)
{
  int  	k;
  int  	x;
  int  	j;

  if ((copy = malloc(sizeof(char*) * i + 1)) == NULL)
    return (NULL);
  k = 0;
  j = 0;
  while (++j != i)
  {
    if ((check_comment(tab, j)) == 1);
    else
      {
	x = my_strlen(tab[j]);
	if ((copy[k] = malloc(sizeof(char) * x + 1)) == NULL)
	  return (NULL);
	x = -1;
	while (tab[j][++x] != '\0')
	  copy[k][x] = tab[j][x];
	copy[k][x] = '\0';
	k++;
      }
  }
  copy[k] = NULL;
  return (copy);
}

int		main(int argc, char **argv)
{
  t_pars	list;
  int		i;

  argv = argv;
  if (argc == 1)
    i = my_file(&list);
  if (i == 2)
    print_number_all(list);
  create_map(&list);
  if (i == 84)
    return (84);
  return (0);
}
