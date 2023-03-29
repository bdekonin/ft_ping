/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bdekonin <bdekonin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:13:40 by bdekonin      #+#    #+#                 */
/*   Updated: 2023/03/29 20:27:36 by bdekonin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_ping.h"
#include <errno.h>

int create_socket(t_ping *ping) {
	struct timeval timeout;

	int ttl_value = 64;

	// ping->sockfd

	ping->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (ping->sockfd < 0) {
		perror("[create_socket - socket()]: ");
		exit(EXIT_FAILURE);
	}
	if (setsockopt(ping->sockfd, IPPROTO_IP, IP_TTL, &ttl_value, sizeof(ttl_value)) < 0)
		exit(EXIT_FAILURE);
	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;   // 0.1 seconds
	if (setsockopt(ping->sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
		perror("[create_socket - setsockopt()]: ");
		exit(EXIT_FAILURE);
	}
	return (ping->sockfd);
}

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

