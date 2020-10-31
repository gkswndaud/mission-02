/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobae <seobae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:22:04 by seobae            #+#    #+#             */
/*   Updated: 2020/10/31 22:23:00 by seobae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\v' ||
			c == '\t' || c == '\r' || c == '\f');
}

char	*ft_str_cut(char *str, int start, int end)
{
	int		index;
	char	*result;

	index = 0;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start + index < end)
	{
		result[index] = str[start + index];
		index++;
	}
	result[index] = '\0';
	free(str);
	return (result);
}

char	*ft_strip(char *str)
{
	int	size;
	int	index;
	int	start;
	int	end;

	index = 0;
	size = 0;
	while (str[size])
		size++;
	while (is_whitespace(str[index]))
		index++;
	start = index;
	while (is_whitespace(str[size - 1]))
		size--;
	end = size;
	return (ft_str_cut(str, start, end + 1));
}
