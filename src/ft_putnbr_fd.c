/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:18:27 by jonask            #+#    #+#             */
/*   Updated: 2024/03/19 11:34:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_special(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[11];
	int		i;

	i = 10;
	ft_memset(buffer, 'a', 11);
	if (is_special(n, fd) == 1)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buffer[i--] = n % 10 + '0';
		n /= 10;
	}
	i = 0;
	while (i < 11)
	{
		if (buffer[i] != 'a')
			write(fd, &buffer[i], 1);
		i++;
	}
}
