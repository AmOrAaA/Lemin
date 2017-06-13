/*
** all_cmp.c for  in /home/AmOrAA/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Sat Apr 22 14:59:46 2017 Florian Testu
** Last update Thu Apr 27 21:35:39 2017 Florian Testu
*/

#include "lem_in.h"

int     check_idem_path_second(t_pars *list, char *copy, int i)
{
  while (list->path[++i] != NULL)
    {
      if ((my_strcmp(list->path[i], copy)) == 0)
        return (0);
    }
  return (0);
}

int     check_idem_room_second(char **list, char *copy, int i)
{
  char  *copy2;
  int   k;
  int   j;

  j = -1;
  while (list[++i] != NULL)
    {
      j = k = -1;
      copy2 = NULL;
      free(copy2);
      while (list[i][++j] && list[i][j] != ' ');
      if ((copy2 = malloc(sizeof(char) * (strd(list[i], j)) + 1)) == NULL)
          return (84);
      while (list[i][++j] != '\0')
        copy2[++k] = list[i][j];
      if ((my_strcmp(copy, copy2)) == 0)
        return (0);
    }
  return (0);
}

int     check_idem_error_second(char **list, char *copy, int i)
{
  char  *copy2;
  int   k;
  int   j;

  j = -1;
  while (list[++i] != NULL)
    {
      j = k = -1;
      copy2 = NULL;
      free(copy2);
      while (list[i][++j] && list[i][j] != ' ');
      if ((copy2 = malloc(sizeof(char) * (strd(list[i], j)) + 1)) == NULL)
          return (84);
      while (list[i][++j] != '\0')
        copy2[++k] = list[i][j];
      if ((my_strcmp(copy, copy2)) == 0)
        return (84);
      my_putstr(list[i]);
      my_putchar('\n');
    }
  return (0);
}
