/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:48:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/18 18:03:59 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* ft_strlen */

#include <unistd.h> /* write */
#include <stdio.h> /* perror */
#include <errno.h> /* ERRNO */
#include <stdlib.h> /* exit */

#define RED "\033[0;31m"
#define HYEL "\e[0;93m"
#define RESET "\e[0m"

void	non_fatal_error(char *msg)
{
	write(STDERR_FILENO, RED, 8);
	write(STDERR_FILENO, "ERROR!\n", 8);
	write(STDERR_FILENO, HYEL, 8);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, RESET, 5);
}

void	fatal_perror(char *msg)
{
	write(STDERR_FILENO, HYEL, 8);
	perror(msg);
	write(STDERR_FILENO, RESET, 5);
	exit(errno);
}
