/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:46:02 by junghan           #+#    #+#             */
/*   Updated: 2020/11/01 00:29:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"
#include <stdio.h>


int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_strcount(t_dict *dict)
{
	int i;
	
	i = 0;
	while (dict[i].text)
	{
		i++;
	}
	return (i);
}

int ft_strcmp(char *c, t_dict *dict)
{
	int i;

	i = 0;
	while (c[i] || dict[i].number)
	{
		if (c[i] != dict[i].number[i])
			return(c[i] - dict[i].number);
		i++;
	}
	return (0);
}

void print_text(int idx) //해당 위치의 구조체value값을 출력
{
	int i;

	i = 0;
	while (dict[idx].text[i])
	{
		write(1, (&dict[idx].text[i]), 1);
		i++;
	}
}

void search_dict(char *c, t_dict *dict) //argv 해당 자릿수(1의 자리)의 값과 dict의 text를 비교
{
	int i;
	int count;

	i = 0;
	count = ft_strcount(dict);
	while (i < count)
	{
		if (ft_strcmp(c, dict) == 0) //비교
		{
			print_text(dict[i].text); //해당 자릿수 출력
			return ;
		}
		i++;
	}	
}

void print_1digit(char *c, t_dict *dict, int len) //1의 자리
{
	int i;
	char tmp[2];

	i = 0;
	while (i < 1) //1개만 받아줌 100의 자리와 1의 자리는 동일
		tmp[i++] = c[len--];
	search_dict(c, dict);//tmp 와 dict.text를 비교
	if (len != 1)
		write(1, " ", 1);
}

void print_2digit(char *c, t_dict *dict, int *len) //10의 자리
{
	int i;
	char tmp[3];

	i = 0;
	while (i < 2) //2개 받아줌
		tmp[i++] = c[(*len)--];
	if (c[len + 2] == '1') //10 ~19 일경우 len를 두개건너뛰고 출력
	{
		search_dict(tmp, dict);
		write(1, " ", 1);
	}
	else				   //20 ~ 90일 경우 len 값을 하나 올려줌
	{
		tmp[1] = '0';
		search_dict(tmp, dict);
		(*len)++;
		write(1, " ", 1);
	}
}

void print_3digit(char *c, t_dict *dict, int len) //100의 자리
{
	int i;	//인덱스 설정
	char tmp[2]; //argv 의 값을 받아줌

	i = 0;
	while (i < 1) //1개만 받아줌
		tmp[i++] = c[len--];
	search_dict(tmp, dict);//tmp 와 dict.text를 비교
	write(1, " ", 1);
	write(1, "hundred", 6);
	write(1, " ", 1);
}

void find_range(t_dict * dict, int len, char *argv) // 1000이상 출력부분
{
	int i;
	int str_len;
	int text_len;

	i = 0;
	while (i < ft_strcount(dict)) //딕셔너리 탐색
	{
		if (len > 3 && (ft_strlen(dict[i].number) / 3 == ft_strlen(argv) / 3)) //만약 자릿수가 3 이상이고 몫이 같을때
			print_text(i); //ex dict[i].number 1,000,000   ==  2,234,552
		i++;
	}
}

void	conv_text(char *argv, t_dict *dict)
{
	int len;
	int idx;

	len = ft_strlen(argv);
	while (idx < len)//argv[9]의 숫자의나머지값기준
	{
		if (idx % 3 == 0) //해당위치가 100의 자리일경우	
		{
			print_3digit(argv, dict);
		}
		else if (idx % 3 == 2) //해당위치가 10의 자리일경우
		{
			print_2digit(argv, dict, &len);
		}
		else if (idx % 3 == 1) //해당위치가 1의 자리일경우
		{
			print_1digit(argv, dict);
			find_range(dict, len, argv);//해당 위치가 1000이상이면 인자값출력
		}
		idx++;
	}
}
