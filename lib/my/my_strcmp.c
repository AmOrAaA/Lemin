/*
** my_strcmp.c for my_strcmp in /home/Nyavenger/CPool_Day06
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Mon Oct 10 11:21:14 2016 Jonathan Delestre
** Last update Mon Oct 10 19:15:35 2016 Jonathan Delestre
*/

int	my_strcmp(char *s1, char *s2)
{
  int	count;
  int	result;

  count = 0;
  result = 0;
  while (s1[count] != '\0')
    {
      if (s1[count] <= s2[count])
	result = result - (s2[count] - s1[count]);
      if (s1[count] >= s2[count])
	result = result + (s1[count] - s2[count]);
      if (result != 0)
	return (result);
      count = count + 1;
    }
  return (result);
}
