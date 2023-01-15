/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:13:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/15 13:55:23 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"


int main(int argc, char const **argv)
{
	t_vars *vars;


	vars = parser(argc, argv);

	printf("Hostname: %s\n", vars->hostname);
	// print_help();
		// const char **result2 = ft_lfind(&key2, array2, nmemb, sizeof(const char*), string_compar);
}
