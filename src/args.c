#include "libft.h"
#include "fdf.h"
#include "error.h"
#include "draw.h"
#include <stdint.h>

static bool	is_correct_extension_include(\
			const char *filepath, const size_t len_filepath, char **dot_ptr)
{
	*dot_ptr = ft_strnstr(filepath, FILE_EXTENSION, len_filepath);
	if (*dot_ptr == NULL)
		return (false);
	return (true);
}

static bool	is_valid_extension(char *dot_ptr, const size_t len_filepath)
{
	if (ft_strncmp(dot_ptr, FILE_EXTENSION, len_filepath) != 0)
		return (false);
	return (true);
}

// ".fdf" included
static bool	is_valid_filetype(const char *filepath, char *dot_ptr)
{
	if (filepath == dot_ptr)
		return (false);
	if (*(dot_ptr - 1) == '/')
		return (false);
	return (true);
}

static bool	is_valid_filepath(const char *filepath, uint8_t *error_code)
{
	const size_t	len_filepath = ft_strlen(filepath);
	char			*dot_ptr;

	if (!is_correct_extension_include(filepath, len_filepath, &dot_ptr))
	{
		*error_code = INVALID_EXTENSION;
		return (false);
	}
	if (!is_valid_extension(dot_ptr, len_filepath))
	{
		*error_code = INVALID_EXTENSION;
		return (false);
	}
	if (!is_valid_filetype(filepath, dot_ptr))
	{
		*error_code = INVALID_FILETYPE;
		return (false);
	}
	return (true);
}

bool	check_args(const int argc, char *const argv[], uint8_t *error_code)
{
	const char	*filepath = argv[1];

	if (argc != 2)
	{
		*error_code = INVALID_ARGC;
		return (false);
	}
	if (!is_valid_filepath(filepath, error_code))
		return (false);
	return (true);
}
