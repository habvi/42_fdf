#include "libft.h"
#include "fdf.h"
#include "error.h"
#include "draw.h"
#include <stdint.h>

static bool	is_correct_extension_include(\
		const char *filepath, const size_t len_filepath, char **index)
{
	*index = ft_strnstr(filepath, FILE_EXTENSION, len_filepath);
	if (*index == NULL)
		return (false);
	return (true);
}

static bool	is_valid_path(const char *filepath, char *index)
{
	if (filepath == index)
		return (false);
	if (*(index - 1) == '/')
		return (false);
	return (true);
}

static bool	is_valid_extension(const char *filepath, const size_t len_filepath)
{
	while (*filepath != '.')
		filepath++;
	if (ft_strncmp(filepath, FILE_EXTENSION, len_filepath) != 0)
		return (false);
	return (true);
}

static uint8_t	check_filepath(const char *filepath)
{
	const size_t	len_filepath = ft_strlen(filepath);
	char			*index;

	index = NULL;
	if (!is_correct_extension_include(filepath, len_filepath, &index))
		return (INVALID_EXTENSION);
	if (!is_valid_path(filepath, index))
		return (INVALID_FILETYPE);
	if (!is_valid_extension(filepath, len_filepath))
		return (INVALID_EXTENSION);
	return (SUCCESS);
}

void	check_args(const int argc, char *const argv[])
{
	uint8_t	result;

	if (argc != 2)
	{
		(void)argv;
		error_exit(ERR_MSG_ARGS, NULL, EXIT_FAILURE);
	}
	result = check_filepath(argv[1]);
	if (result == INVALID_EXTENSION)
		error_exit(ERR_MSG_FILE_EXTENSION, NULL, EXIT_FAILURE);
	else if (result == INVALID_FILETYPE)
		error_exit(ERR_MSG_FILETYPE, NULL, EXIT_FAILURE);
}
