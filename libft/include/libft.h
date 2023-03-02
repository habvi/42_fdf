#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>

// ft_atoi, ft_atox
# define INVALID_CHAR		-1
# define BASE10				"0123456789"
# define BASE16_LOWER		"0123456789abcdef"
# define BASE16_UPPER		"0123456789ABCDEF"
# define LEN_0X				2
# define COLOR_DIGIT_MAX	10

uint8_t	base_index(const char *base, char c);
bool	ft_atoi_n_with_bool(\
			const char *str, int *num, const char *base, uint8_t len);
bool	ft_atox_with_bool(const char *str, int64_t *num);
bool	ft_isdigit(int c);
int		ft_max(const int x, const int y);
int		ft_min(const int x, const int y);
double	ft_min_double(const double x, const double y);
char	**ft_split(char const *s, char c, size_t *list_size);
char	*ft_strchr(const char *s, int int_c);
char	*ft_strdup(const char *s);
void    ft_strlcpy_void(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strndup(const char *s, size_t maxlen);
size_t  ft_strnlen(const char *s, size_t maxlen);
int		ft_toupper(int c);

#endif
