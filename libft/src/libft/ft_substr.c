#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (i < maxlen && s[i])
		i++;
	return (i);
}

static char	*ft_strndup(const char *s, size_t maxlen)
{
	const size_t	len_s = ft_min(maxlen, ft_strnlen(s, maxlen));
	char			*dst;
	size_t			i;

	dst = (char *)malloc(sizeof(char) * (len_s + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strnlen(s, start);
	if (len_s < start)
		return (ft_strdup(""));
	return (ft_strndup(s + start, len));
}
