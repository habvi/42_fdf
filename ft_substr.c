#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	tail;
	size_t	len_substr;
	char	*res;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start || len == 0)
	{
		start = ft_min(len_s, start);
		len_substr = 0;
	}
	else
	{
		tail = ft_min(len_s, start + len);
		len_substr = tail - start;
	}
	res = (char *)malloc(sizeof(char) * (len_substr + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, len_substr + 1);
	return (res);
}
