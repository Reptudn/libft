/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:20:48 by jkauker           #+#    #+#             */
/*   Updated: 2024/05/09 12:21:14 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	**ft_strarrdup(char **str)
{
	char	**new_str;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new_str = malloc(sizeof(char *) * (i + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		new_str[i] = ft_strdup(str[i]);
		if (!new_str[i])
		{
			while (i >= 0)
				free(new_str[i--]);
			free(new_str);
			return (NULL);
		}
	}
	new_str[i] = NULL;
	return (new_str);
}
