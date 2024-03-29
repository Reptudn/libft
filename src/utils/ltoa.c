/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2024/03/19 11:33:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ltoa(long n)
{
	char		*str;
	int			digits;
	long long	_n;

	_n = n;
	if (n == 0)
		return (ft_strdup("0"));
	digits = get_digits(_n);
	if (_n < 1)
	{
		digits += 1;
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
		str[0] = '-';
		_n = -_n;
	}
	else
	{
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	put_nb_in_str(_n, digits, str);
	return (str);
}
