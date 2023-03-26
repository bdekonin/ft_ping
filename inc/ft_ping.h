/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ping.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 19:37:23 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/03/26 17:00:08 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

#include <netinet/ip.h>
#include <unistd.h>  // for getpid, getuid
#include <netdb.h>   // for getaddrinfo, freeaddrinfo
#include <sys/time.h> // for gettimeofday
#include <arpa/inet.h> // for inet_ntop, inet_pton
#include <stdlib.h> // for exit
#include <signal.h> // for signal, alarm
#include <sys/socket.h> // for setsockopt, recvmsg, sendto, socket
#include <stdio.h> // for printf and its family
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
# include <stdbool.h>

#include "../libft/libft.h" // for your libft functions

/* Parsing */
# define F_HELP "-h"
# define F_VERBOSE "-v"

typedef struct	s_args {
	int			timeout;
	int			packets_size;
	int			ttl_value;
	int			deadline;
	double		interval;
	int			num_packets;

	int			verbose;
	char		*hostname;
	char		*port;
}				t_args;

typedef struct	s_ping {
	t_args			args;
}				t_ping;


// Print
int print_help(int exit_code);
int print_error(const char *error);

// Parser
void parser(t_ping *ping, int argc, const char **argv);

#endif // FT_PING_HPP