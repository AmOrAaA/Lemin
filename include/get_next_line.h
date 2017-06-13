/*
** get_next_line.h for get_next_line in /home/Nyavenger/CPE/CPE_2016_getnextline/include
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Tue Jan  3 11:35:35 2017 Jonathan Delestre
** Last update Wed Apr 19 10:59:37 2017 Jonathan Delestre
*/

#ifndef	GET_NEXT_LINE_H_
#define	GET_NEXT_LINE_H_

#ifndef	READ_SIZE
#define	READ_SIZE (3)
#endif	/* !READ_SIZE */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(const int fd);

#endif
