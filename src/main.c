/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:13:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/03/27 22:22:39 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"
#include <errno.h>

int main(int argc, char const **argv)
{
	t_ping ping;

	ft_bzero(&ping, sizeof(t_ping));
	parser(&ping, argc, argv);

	// Printing out ping->args
	printf("verbose: %d\n", ping.args.verbose);
	printf("hostname: %s\n", ping.args.hostname);
	printf("port: %s\n", ping.args.port);
}

