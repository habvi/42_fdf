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

static bool	is_overflow(size_t *num, int c, int op)
{
	size_t	ov_div;
	size_t	ov_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10 + (op == -1);
	if (*num > ov_div)
		return (true);
	if (*num == ov_div && (size_t)c - '0' > ov_mod)
		return (true);
	return (false);
}

// if "-", return (0)
bool	ft_atoi_with_bool(const char *str, size_t *num)
{
	int	op;

	*num = 0;
	op = 1;
	while (is_space(*str))
		str++;
	if (is_operator(*str))
	{
		op = ',' - *str;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_overflow(num, *str, op))
		{
			*num = 0;
			return (false);
		}
		*num = *num * 10 + *str - '0';
		str++;
	}
	*num = (int)(*num * op);
	return (true);
}
