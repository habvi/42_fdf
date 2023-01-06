#include "libft.h"

bool	is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

bool	is_operator(int c)
{
	return (c == '-' || c == '+');
}

bool	is_overflow(int *num, int c, int op, const char *base)
{
	const size_t	base_num = ft_strlen(base);
	int				ov_div;
	int				ov_mod;

	ov_div = INT_MAX / base_num;
	ov_mod = INT_MAX % base_num + (op == -1);
	if (*num > ov_div)
	{
		*num = 0;
		return (true);
	}
	if (*num == ov_div && base_index(base, c) > ov_mod)
	{
		*num = 0;
		return (true);
	}
	return (false);
}

bool	ft_atoi_n_with_bool(\
					const char *str, int *num, const char *base, size_t len)
{
	const size_t	base_num = ft_strlen(base);
	int				op;
	bool			at_least_one_digit;
	int				base_i;
	size_t			i;

	i = 0;
	*num = 0;
	op = 1;
	while (is_space(*str) && i < len)
	{
		str++;
		i++;
	}
	if (is_operator(*str) && i < len)
	{
		op = ',' - *str;
		str++;
		i++;
	}
	at_least_one_digit = false;
	while (ft_strchr(base, *str) != NULL && i < len)
	{
		base_i = base_index(base, *str);
		if (base_i == INVALID_CHAR)
			return (false);
		at_least_one_digit = true;
		if (is_overflow(num, *str, op, base))
			return (false);
		*num = *num * base_num + base_i;
		str++;
		i++;
	}
	if (i != len || !at_least_one_digit)
		return (false);
	*num *= op;
	return (true);
}
