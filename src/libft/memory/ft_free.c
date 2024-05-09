/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:22:51 by jkauker           #+#    #+#             */
/*   Updated: 2024/05/09 12:25:45 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_free_many_ret(void *return_val, int count, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, count);
	while (count--)
	{
		ptr = va_arg(args, void *);
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
	}
	va_end(args);
	return (return_val);
}

void	*ft_free_many(int count, ...)
{
	va_list	args;
	void	*ptr;

	va_start(args, count);
	while (count--)
	{
		ptr = va_arg(args, void *);
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
	}
	va_end(args);
	return (NULL);
}

void	*ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	*ft_free_ret(void *return_val, void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (return_val);
}
