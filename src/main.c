/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:13:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/01/15 18:38:25 by bdekonin      ########   odam.nl         */
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

	int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (sockfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in dest_addr;
	memset(&dest_addr, 0, sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_addr.s_addr = inet_addr(vars->hostname);

	struct icmphdr echo_request;
	memset(&echo_request, 0, sizeof(echo_request));
	echo_request.type = ICMP_ECHO;
	echo_request.code = 0;
	echo_request.un.echo.id = getpid();
	echo_request.un.echo.sequence = 0;

	printf("send\n");
	int bytes_sent = sendto(sockfd, &echo_request, sizeof(echo_request), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr));
	dprintf("send %d\n", bytes_sent);
	if (bytes_sent < 0)
	{
		perror("sendto");
	}
	else
	{
		printf("Sent %d bytes to %s\n", bytes_sent, vars->hostname);
	}
}
