/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 08:58:59 by jkauker           #+#    #+#             */
/*   Updated: 2024/05/08 20:38:38 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

# include <stdio.h>
# include <stdarg.h>


#define GARBAGE_COLLECTOR_SIZE 50
#define GARBAGE_ERROR_EXPAND -2
#define GARBAGE_ERROR_CREATE -1
#define GARBAGE_SUCCESS 0

static int *garbage_col_count(void)
{
	static int	count = 0;

	return (&count);
}

static void	***garbage_col_get(void)
{
	static void	**garbage = NULL;

	return (&garbage);
}

static int	ft_garbage_col_create(void)
{
	void	***garbage;

	garbage = garbage_col_get();
	if (*garbage)
		return (1);
	*garbage_col_count() = 0;
	*garbage = malloc(sizeof(void *) * GARBAGE_COLLECTOR_SIZE);
	if (!*(garbage))
		return (0);
	return (1);
}

// returns 0 on success and otherwise the number of elements that were able to be added
// returns -1 when the garbage collector has not been created
// retuen -2 when the garbage collector is full and could not be realloced
int	ft_garbage_col_add(void *ptr)
{
	void	***garbage;
	int		*count;

	garbage = garbage_col_get();
	if (!*garbage && !ft_garbage_col_create())
		return (GARBAGE_ERROR_CREATE);
	count = garbage_col_count();
	if (*count >= GARBAGE_COLLECTOR_SIZE)
	{
		*garbage = realloc(*garbage, sizeof(void *) // TODO: change realloc to ft_realloc once its added
				* GARBAGE_COLLECTOR_SIZE * 2);
		if (!*garbage)
			return (GARBAGE_ERROR_EXPAND);
	}
	(*garbage)[(*count)++] = ptr;
	return (GARBAGE_SUCCESS);
}

int	ft_garbage_col_add_many(int count, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, count);
	i = 0;
	ret = 0;
	while (i < count)
	{
		ret = ft_garbage_col_add(va_arg(args, void *));
		if (ret != GARBAGE_SUCCESS)
			break ;
		i++;
	}
	va_end(args);
	return (ret);
}

int	ft_garbage_col_add_array(void **array, int size)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret = ft_garbage_col_add(array[i]);
		if (ret != GARBAGE_SUCCESS)
			break ;
		i++;
	}
	if (ret != GARBAGE_SUCCESS)
		return (i);
	ret = ft_garbage_col_add(array);
	return (ret);
}

void	ft_garbage_col_clear(void)
{
	void	***garbage;
	int		*count;
	int		i;

	garbage = garbage_col_get();
	if (!*garbage)
		return ;
	count = garbage_col_count();
	i = 0;
	while (i < *count)
	{
		free((*garbage)[i]);
		i++;
	}
	free(*garbage);
	*garbage = NULL;
	*count = 0;
}
