#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free
# include <unistd.h> // read
# include <stdbool.h>
# include <limits.h>

# define BUFFER_SIZE 1024
# define MY_OPEN_MAX 1024
# define LF         '\n'
# define READ_ERROR -1

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr_for_gnl(char const *s, unsigned int start, size_t len);
void	*ft_memmove_for_gnl(void *dst, const void *src, size_t len);

#endif
