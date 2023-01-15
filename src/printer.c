/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 21:57:17 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/15 17:35:32 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

/**
 * @brief Prints the usage information and available options for the command
 * 
 * @return EXIT_FAILURE
 */

int print_help(int exit_code)
{
	printf("usage: ping [-h] [-v] <destination> \n\nPing a host\n\npositional arguments:\n  destination\tThe destination to ping\n\noptional arguments:\n  -h\t\tshow this help message and exit\n  -v\t\tenable verbose output\n");
	return (exit_code);
}

int print_error(const char *error)
{
	fprintf(stderr, "Error: %s\n", error);
	return (EXIT_FAILURE);
}