/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_filter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyoun <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:04:23 by seyoun            #+#    #+#             */
/*   Updated: 2020/10/31 22:47:37 by seyoun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.c"

int		input_filter(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2){
		ft_put_err_str("[Error] the number of args aren't 1. Input only one string.");
		return (2);	
	}
	
	while (argv[1][i] != '\0')
	{
		if ( '0' <= argv[1][i] && argv[1][i] <= '9' )
		{
		/* 	output_proc_here */
			return (0);
		}
		if (is_whitespace(argv[1][i]) > 0)
		{
			return (1); 
		}
		if (is_writespace(argv[1][i]) == 0)
		{
			return (0);
		}
		if ( '0' > argv[1][i] && argv[1][i] > '9' )
		{
			ft_put_err_str("[Error] charactor contained in input.");
			return (2);
		}
		i++;
	}
	return (2);
}

