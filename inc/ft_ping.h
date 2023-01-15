/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ping.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 19:37:23 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/15 13:55:38 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

#include <unistd.h>  // for getpid, getuid
#include <netdb.h>   // for getaddrinfo, freeaddrinfo
#include <sys/time.h> // for gettimeofday
#include <arpa/inet.h> // for inet_ntop, inet_pton
#include <stdlib.h> // for exit
#include <signal.h> // for signal, alarm
#include <sys/socket.h> // for setsockopt, recvmsg, sendto, socket
#include <stdio.h> // for printf and its family
#include "./../libft/libft.h" // for your libft functions

typedef struct	s_vars
{
	const char	*hostname;
	// _bool		verbose;
	int			verbose;
}				t_vars;

// Print
int print_help(int exit_code);
int print_error(const char *error);

// Parser
t_vars *parser(int argc, const char **argv);

#endif // FT_PING_HPP