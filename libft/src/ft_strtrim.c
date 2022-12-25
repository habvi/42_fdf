#include "libft.h"

static char const	*search_set( \
					char const *s, char const *set, const int direction)
{
	while (*s && ft_strchr(set, *s))
		s += direction;
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len_s;
	char const	*head = s1;
	char const	*tail = s1;
	size_t		total;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len_s = ft_strlen(s1);
	total = 0;
	if (len_s)
	{
		head = search_set(s1, set, 1);
		tail = search_set(s1 + len_s - 1, set, -1);
		if (head <= tail)
			total = tail - head + 1;
	}
	return (ft_substr(s1, head - s1, total));
}
