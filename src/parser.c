/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 21:56:39 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/03/27 22:24:19 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

static int string_compar(const void *one, const void *two)
{
	const char **a = (const char**)one;
	const char **b = (const char**)two;
	return ft_strcmp(*a, *b);
}

static void parse_flags(int argc, const char **argv)
{
	const char *help_flag = F_HELP;
	const char *dashes = "--";

	if (argc <= 1)
		exit(print_help(EXIT_SUCCESS));

	/* Searching for a -h (help) flag */
	if (ft_lfind_index(&help_flag, argv, argc, sizeof(const char *), string_compar) != -1)
		exit(print_help(EXIT_SUCCESS));

	/* Check if there is a -- inside any of arrays. */
	if (ft_lfind_index(&dashes, argv, argc, sizeof(const char *), string_compar) != -1)
		exit(print_help(EXIT_SUCCESS));
}

static void error_checking(t_ping *ping, int argc, const char **argv, int hostname_index)
{
	/* Error checking */
	if(hostname_index == -1)
		exit(print_error("No hostname provided"));
	if (ft_strlen(argv[hostname_index]) > 255)
		exit(print_error("Hostname too long"));
	if (ping->args.verbose == 1 && argc != 3)
		exit(print_error("Please provide only one hostname. Use -h for help"));
	if (!ping->args.verbose && argc != 2)
		exit(print_error("Please provide only one hostname. Use -h for help"));
}

static void parse_hostname_and_port(t_ping *ping, const char *hostname)
{
	char *semicolen = ft_strnstr(hostname, ":", ft_strlen(hostname));

	// Check if a semicolon is present in the hostname, if so, assign the string after the semicolon to "vars->port"
	if (semicolen)
	{
		semicolen += 1;
		ping->args.port = ft_strdup(semicolen);
		semicolen -= 1;
		semicolen[0] = '\0';
	}
	// If no semicolon is present, assign "80" to "vars->port"
	else 
		ping->args.port = ft_strdup("80");

	// If the memory allocation for "vars->port" fails, free the memory for "vars" and call the function "print_error" and exit the program.
	if (!ping->args.port)
		exit(print_error("Malloc failed"));

	// Assign a copy of the hostname to "vars->hostname"
	ping->args.hostname = ft_strdup(hostname);
	if (!ping->args.hostname)
	{
		free(ping->args.port);
		exit(print_error("Malloc failed"));
	}
}

static int parsing_arguments(t_ping *ping, int argc, const char **argv)
{
	const char *verbose_flag = F_VERBOSE;
	const size_t size = sizeof(const char *);

	/* Parse verbose */
	int verbose_index = ft_lfind_index(&verbose_flag, argv, argc, size, string_compar);
	if (verbose_index != -1)
		ping->args.verbose = 1;

	/* Parse hostname */
	int hostname_index = -1;
	for (int i = 1; i < argc; i++)
	{
		if(i != verbose_index)
		{
			hostname_index = i;
			break;
		}
	}
	return hostname_index;
}

void parser(t_ping *ping, int argc, const char **argv)
{
	int hostname_index;

	parse_flags(argc, argv);

	hostname_index = parsing_arguments(ping, argc, argv);

	/* Functions */
	error_checking(ping, argc, argv, hostname_index);
	parse_hostname_and_port(ping, argv[hostname_index]);

	/* If no hostname was gives, or if hostname doesnt have any length*/
	if (!ping->args.hostname || ping->args.hostname[0] == '\0')
	{
		/* Last check to free a allocated hostname */
		if (ping->args.hostname)
			free(ping->args.hostname);
		free(ping->args.port);
		exit(print_error("No hostname provided"));
	}
}

