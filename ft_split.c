#include "libft.h"

static size_t	count_words(char const *lp, char c)
{
	char const	*rp = lp;
	size_t		words;

	words = 0;
	while (*rp != '\0')
	{
		while (*rp == c)
		{
			lp++;
			rp++;
		}
		while (*rp != c && *rp != '\0')
			rp++;
		if (lp != rp)
		{
			words++;
			lp = rp;
		}
	}
	return (words);
}

static bool	set_split_str(char const *lp, char c, char **list)
{
	char const	*rp = lp;
	size_t		i;

	i = 0;
	while (*rp != '\0')
	{
		while (*rp == c)
		{
			lp++;
			rp++;
		}
		while (*rp != c && *rp != '\0')
			rp++;
		if (lp != rp)
		{
			list[i] = ft_substr(lp, 0, rp - lp);
			if (list[i] == NULL)
				return (false);
			i++;
			lp = rp;
		}
	}
	return (true);
}

static void	free_all(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	size_t	list_size;
	char	**list;

	if (s == NULL)
		return (NULL);
	list_size = count_words(s, c);
	list = (char **)malloc(sizeof(char *) * (list_size + 1));
	if (list == NULL)
		return (NULL);
	if (set_split_str(s, c, list))
	{
		list[list_size] = NULL;
		return (list);
	}
	free_all(list);
	return (NULL);
}
