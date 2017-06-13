/*
** my_file.c for  in /home/amoraa/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat Apr 29 17:30:39 2017 Florian Testu
** Last update Sun Apr 30 03:49:02 2017 Florian Testu
*/

#include "lem_in.h"

void    print_number_all2(t_pars list, int start, int end, int i)
{
  while (list.all[++i] != NULL)
    {
      if (list.all[i][0] == '#')
        {
          if (i == start)
            {
              my_putstr("##start\n");
              start = -1;
            }
          if (i == end)
            {
              my_putstr("##end\n");
              end = -1;
            }
        }
      else
        {
          my_putstr(list.all[i]);
          my_putchar('\n');
        }
    }
}

void    print_number_all(t_pars list)
{
  int   i;
  int   start;
  int   end;

  i = -1;
  while (list.file[++i] != NULL)
    {
      if ((my_strcmp("##start", list.file[i])) == 0)
        start = i;
      if ((my_strcmp("##end", list.file[i])) == 0)
        end = i;
    }
  i = 0;
  my_putstr("#rooms\n");
  print_number_all2(list, start, end, i);
}

int     my_file2(t_pars *list, char **tab, int i)
{
  if ((list->all = check_all_file(tab)) == NULL)
    i = 84;
  if ((list->path = check_all_path(tab)) == NULL)
    i = 86;
  if ((list->start = check_start(tab)) == NULL)
    i = 85;
  if ((list->end = check_end(tab)) == NULL)
    i = 85;
  return (i);
}

int     my_file3(int i, char **tab, t_pars *list)
{
  if (i == 84)
    return (84);
  if ((print_if_ok(tab)) == 84)
    return (84);
  if (i != 86 && i != 85 && i != 84)
    {
      if ((check_path_start(list)) == 84)
	i = 86;
      if ((check_path_end(list)) == 84)
	i = 86;
    }
  if (i == 85)
    {
      my_putstr("#moves\n");
      return (84);
    }
  if (i == 86)
    {
      my_putstr("#moves\n");
      return (84);
    }
  if ((all_check_end(list)) == 84)
    return (84);
  return (0);
}

int     my_file(t_pars *list)
{
  char  *buff;
  char  *tmp;
  char  **tab;
  int   i;

  i = 0;
  if ((tmp = malloc(sizeof(char*))) == NULL)
      return (0);
  while ((buff = get_next_line(0)) != NULL)
    {
      tmp = my_strfcat(tmp, buff);
      tmp = my_strfcat(tmp, "\n");
      free(buff);
    }
  tab = my_str_to_wordtab(tmp);
  if ((list->nbr = check_file_nbr(tab)) == 84)
    return (84);
  if (list->nbr < 0)
    return (84);
  i = my_file2(list, tab, i);
  if ((my_file3(i, tab, list)) == 84)
    return (84);
  return (0);
}
