/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 21:56:39 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/17 14:15:39 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

static int string_compar(const void *one, const void *two)
{
	const char **a = (const char**)one;
	const char **b = (const char**)two;
	return ft_strcmp(*a, *b);
}

t_vars *parser(int argc, const char **argv)
{
	const char *help_flag = "-h";
	const char *verbose_flag = "-v";

	if (argc <= 1)
		exit(print_help(EXIT_SUCCESS));

	/* Parse Help */
	if (ft_lfind_index(&help_flag, argv, argc, sizeof(const char *), string_compar) != -1)
		exit(print_help(EXIT_SUCCESS));

	t_vars *vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		exit(print_error("Malloc failed"));

	/* Parse verbose */
	int verbose_index = ft_lfind_index(&verbose_flag, argv, argc, sizeof(const char *), string_compar);
	if (verbose_index != -1)
	{
		vars->verbose = 1;
	}

	/* Parse hostname */
	int hostname_index = -1;
	for(int i = 1; i < argc; i++)
	{
		if(i != verbose_index)
		{
			hostname_index = i;
			break;
		}
	}

	if(hostname_index == -1)
		exit(print_error("No hostname provided"));

	if (ft_strlen(argv[hostname_index]) > 255)
		exit(print_error("Hostname too long"));

	if (vars->verbose == 1 && argc != 3)
		exit(print_error("Please provide only one hostname. Use -h for help"));
	if (!vars->verbose && argc != 2)
		exit(print_error("Please provide only one hostname. Use -h for help"));

	char *semicolen = ft_strnstr(argv[hostname_index], ":", ft_strlen(argv[hostname_index]));
	// Check if a semicolon is present in the hostname, if so, assign the string after the semicolon to "vars->port"
	if (semicolen)
	{
		semicolen += 1;
		vars->port = ft_strdup(semicolen);
		semicolen[0] = '\0';
	}
	// If no semicolon is present, assign "80" to "vars->port"
	else
		vars->port = ft_strdup("80");
	// If the memory allocation for "vars->port" fails, free the memory for "vars" and call the function "print_error" and exit the program.
	if (!vars->port)
	{
		free(vars);
		exit(print_error("Malloc failed"));
	}
	// Assign a copy of the hostname to "vars->hostname"
	vars->hostname = ft_strdup(argv[hostname_index]);
	if (!vars->hostname)
	{
		free(vars);
		free(vars->port);
		exit(print_error("Malloc failed"));
	}
	return (vars);
}

