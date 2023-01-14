/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 21:57:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/14 21:57:20 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

/**
 * @brief Prints the usage information and available options for the command
 * 
 * @return EXIT_FAILURE
 */

int print_help()
{
	printf("usage: ping [hostname] [-h] [-v] hostname\n\nPing a host\n\npositional arguments:\n  hostname\t\tThe hostname to ping\n\noptional arguments:\n  -h\t\tshow this help message and exit\n  -v\t\tenable verbose output\n\n");
	return (EXIT_FAILURE);
}
