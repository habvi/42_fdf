#include "libft.h"

int	base_index(const char *base, char c)
{
	size_t	i;

	i = 0;
	while (base[i] != c)
		i++;
	if (base[i] != c)
		return (INVALID_CHAR);
	return (i);
}

bool	ft_atox_with_bool(const char *str, int *num)
{
	const size_t	base_num = ft_strlen(BASE16_LOWER);
	bool			at_least_one_digit;
	int				base_i;
	size_t			i;
	char			c;

	if (ft_strlen(str) < 2)
		return (false);
	if (str[0] != '0' || str[1] != 'x')
		return (false);
	i = 2;
	at_least_one_digit = false;
	while (str[i] && (ft_strchr(BASE16_LOWER, str[i]) != NULL || \
						ft_strchr(BASE16_UPPER, str[i]) != NULL))
	{
		c = ft_toupper(str[i]);
		base_i = base_index(BASE16_UPPER, c);
		if (base_i == INVALID_CHAR)
			return (false);
		at_least_one_digit = true;
		*num = *num * base_num + base_i;
		i++;
	}
	return (at_least_one_digit);
}
