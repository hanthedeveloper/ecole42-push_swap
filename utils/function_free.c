/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haincel <haincel@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 16:39:06 by haincel           #+#    #+#             */
/*   Updated: 2026/09/12 16:41:14 by haincel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// stack freeleme funck

char	**ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}