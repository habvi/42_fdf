#include "libft.h"

static bool	is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

static bool	is_operator(int c)
{
	return (c == '-' || c == '+');
}

static bool	is_overflow(int *num, int c, int op, const char *base)
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

static int	move_space_and_op(const char *str, size_t *i, size_t len)
{
	int	op;

	op = 1;
	while (is_space(str[*i]) && *i < len)
		(*i)++;
	if (is_operator(str[*i]) && *i < len)
	{
		op = ',' - str[*i];
		(*i)++;
	}
	return (op);
}

// if "-", return (0) -> fixed
bool	ft_atoi_n_with_bool(\
					const char *str, int *num, const char *base, size_t len)
{
	const size_t	base_num = ft_strlen(base);
	bool			at_least_one_digit;
	int				op;
	int				base_i;
	size_t			i;

	i = 0;
	*num = 0;
	op = move_space_and_op(str, &i, len);
	at_least_one_digit = false;
	while (ft_strchr(base, str[i]) != NULL && i < len)
	{
		base_i = base_index(base, str[i]);
		if (base_i == INVALID_CHAR)
			return (false);
		at_least_one_digit = true;
		if (is_overflow(num, str[i], op, base))
			return (false);
		*num = *num * base_num + base_i;
		i++;
	}
	if (i != len || !at_least_one_digit)
		return (false);
	*num *= op;
	return (true);
}
