/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:13:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/17 19:16:40 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"

int main(int argc, char const **argv)
{
	t_vars *vars;

	vars = parser(argc, argv);





	// printf("Hostname: [%s][%s]\n", vars->hostname, vars->port);

	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	struct addrinfo *result;
	int status = getaddrinfo(vars->hostname, vars->port, &hints, &result);
	if (status != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		exit(EXIT_FAILURE);
	}

	// print out result
	struct addrinfo *rp;
	char *ipver;
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		char ipstr[INET6_ADDRSTRLEN];
		void *addr;

		if (rp->ai_family == AF_INET) {
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		} else {
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}

		inet_ntop(rp->ai_family, addr, ipstr, sizeof(ipstr));
		printf("%s: %s", ipver, ipstr);
	}
}

