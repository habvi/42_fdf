#include "libft.h"

uint32_t	base_index(const char *base, char c)
{
	uint32_t	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

bool	ft_atox_with_bool(const char *str, uint32_t *num)
{
	const uint32_t	base_num = (uint32_t)ft_strlen(BASE16_UPPER);
	bool			at_least_one_digit;
	uint32_t		digit_base;
	size_t			i;

	if (ft_strlen(str) < LEN_0X)
		return (false);
	if (str[0] != '0' || str[1] != 'x')
		return (false);
	i = 2;
	at_least_one_digit = false;
	while (str[i] && i < COLOR_DIGIT_MAX)
	{
		if (!ft_strchr(BASE16_LOWER, str[i]) && \
			!ft_strchr(BASE16_UPPER, str[i]))
			return (false);
		at_least_one_digit = true;
		digit_base = base_index(BASE16_UPPER, ft_toupper(str[i]));
		*num = *num * base_num + digit_base;
		i++;
	}
	return (str[i] == '\0' && i % 2 == 0 && at_least_one_digit);
}

// #include <stdio.h>

// int main(void)
// {
// 	char		*color = "0x80202011";
// 	uint32_t	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%d: %u\n", num == 0x80202011, num);

// 	color = "0x256872";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%d: %u\n", num == 0x256872, num);

// 	color = "0xffffffff";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%d: %u\n", num == 0xffffffff, num);

// 	color = "0xFF0000";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%d: %u\n", num == 0xFF0000, num);

// 	// error
// 	color = "0x00x788";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%u\n", num);

// 	color = "0xFF00g0";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%u\n", num);

// 	color = "0x123456789";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%u\n", num);

// 	color = "0x1234567";
// 	num = 0;
// 	printf("%d, ", ft_atox_with_bool(color, &num));
// 	printf("%u\n", num);

// 	return (0);
// }
