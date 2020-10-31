/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobae <seobae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:22:41 by seobae            #+#    #+#             */
/*   Updated: 2020/10/31 17:09:41 by seobae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_is_space(char c, char target)
{
	return (c == target);
}

int		count_words(char *str, char target)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_space(*str, target))
			str++;
		if (*str && !ft_is_space(*str, target))
		{
			count++;
			while (*str && !ft_is_space(*str, target))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str, char target)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !ft_is_space(str[i], target))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_is_space(str[i], target))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char target)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, target) + 1));
	while (*str)
	{
		while (*str && ft_is_space(*str, target))
			str++;
		if (*str && !ft_is_space(*str, target))
		{
			arr[i] = malloc_word(str, target);
			i++;
			while (*str && !ft_is_space(*str, target))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
