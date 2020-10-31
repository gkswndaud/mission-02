/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobae <seobae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:15:08 by seobae            #+#    #+#             */
/*   Updated: 2020/10/31 17:20:32 by seobae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define DICT_PATH "numbers.dict"
# define BUFF_SIZE 1024

typedef struct	s_dict
{
	char		*number;
	char		*text;
}				t_dict;

char	**ft_split(char *str, char target);

#endif
