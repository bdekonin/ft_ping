/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 21:56:39 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/14 21:58:31 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

int string_compar(const void *one, const void *two)
{
	const char **a = (const char**)one;
	const char **b = (const char**)two;
	return ft_strcmp(*a, *b);
}

void parser(int argc, const char **argv)
{
	const char *help_short = "-h";
	const char *help_long = "--help";
	
	if (argc > 1 && ft_lfind(&help_short, argv, argc, sizeof(const char *), string_compar))
		exit(print_help());
	if (argc > 1 && ft_lfind(&help_long, argv, argc, sizeof(const char *), string_compar))
		exit(print_help());
	printf("Other!!!\n");
}