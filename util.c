void	ft_put_err_char(char c)
{
	write(2, &c, 1);
}

void	ft_put_err_str(char *str)
{
	int i = 0;

	i=0;
	while(str[i]){
		ft_put_err_char(str[i]);
		i++;
	}
}

int		is_whitespace(char ch)
{
	return (ch == ' ' || ch == '\n' || ch == '\v' ||
			ch == '\t' || ch == '\r');
}
