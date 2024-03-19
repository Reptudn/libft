/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:58:37 by jonask            #+#    #+#             */
/*   Updated: 2024/03/19 11:34:42 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "limits.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	int		*pog;
	size_t	total;

	if (size != 0 && nmenb > SIZE_T_MAX / size)
		return (0);
	total = nmenb * size;
	pog = malloc(total);
	if (!pog)
		return (0);
	ft_memset(pog, 0, total);
	return (pog);
}
