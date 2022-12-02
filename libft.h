#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

bool	ft_atoi_with_bool(const char *str, size_t *num);
bool	ft_isdigit(int c);
char	**ft_split(char const *s, char c, size_t *list_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif