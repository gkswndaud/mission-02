/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobae <seobae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:07:33 by seobae            #+#    #+#             */
/*   Updated: 2020/10/31 17:41:15 by seobae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char	*ft_read_file(char *path)
{
	int				dict;
	int				i;
	unsigned int	file_size;
	char			current;
	char			*filestr;

	if ((dict = open(path, O_RDONLY)) < 0)
		return (NULL);
	file_size = 0;
	while (read(dict, &current, 1))
		file_size++;
	if (!(filestr = malloc(sizeof(*filestr) * (file_size + 1))))
		return (NULL);
	close(dict);
	dict = open(path, O_RDONLY);
	i = 0;
	while (read(dict, filestr + i, 1))
		i++;
	close(dict);
	filestr[file_size] = '\0';
	return (filestr);
}

char	**ft_get_lines(char *path)
{
	char **lines;
	char *filestr;

	if (!(filestr = ft_read_file(path)))
		return (NULL);
	lines = ft_split(filestr, '\n');
	free(filestr);
	return (lines);
}

int		ft_get_number_lines(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

int		is_whitespace(char ch)
{
	return (ch == ' ' || ch == '\n' || ch == '\v' ||
			ch == '\t' || ch == '\r');
}

char	*str_cut(char *str, int start, int end)
{
	int		index;
	char	*result;

	index = 0;
	result = malloc(sizeof(char) * (end - start + 1));
	while (start + index < end)
	{
		result[index] = str[start + index];
		index++;
	}
	result[index] = '\0';
	free(str);
	return (result);
}

char	*ft_strip_free(char *str)
{
	int	size;
	int	index;
	int	start;
	int	end;

	index = 0;
	size = str_len(str);
	while (is_whitespace(str[index]))
		index++;
	start = index;
	while (is_whitespace(str[size - 1]))
		size--;
	end = size;
	return (str_cut(str, start, end + 1));
}

t_dict	*ft_parsing(char **dict, int len)
{
	int		i;
	t_dict	*dict_src;
	char	**value;

	if (!(dict_src = malloc(sizeof(*dict_src) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		value = ft_split(dict[i], ':');
		if (value == 0)
			continue ;
		dict_src[i].number = value[0];
		dict_src[i].text = value[1];
		i++;
	}
	dict_src[i].text = NULL;
	return (dict_src);
}

t_dict	*ft_init_dict(void)
{
	t_dict	*dict;
	char	**c;
	int		len;

	c = NULL;
	if (!(c = ft_get_lines(DICT_PATH)))
		return (NULL);
	len = ft_get_number_lines(c);
	dict = ft_parsing(c, len);
	return (dict);
}

int		main(void)
{
	t_dict	*dict;

	dict = ft_init_dict();
	int i;

	i = 0;
	while (dict[i].text != '\0')
	{
		printf("%s --- %s\n", dict[i].number, dict[i].text);
		i++;
	}
	return (0);
}
