#include <fcntl.h> // open
#include <string.h> // strerror
#include <errno.h>
#include "libft.h"
#include "fdf.h"
#include "error.h"

int	open_file(const char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);

	if (fd == OPEN_ERROR)
		error_exit(strerror(errno), NULL, EXIT_FAILURE);
	return (fd);
}

static void	check_file_extension(const char *filepath)
{
	const char	*extension = FILE_EXTENSION;
	size_t		len_extension;
	size_t		len_filepath;

	len_extension = ft_strlen(extension);
	len_filepath = ft_strlen(filepath);
	if (!ft_strchr(filepath, '.') || len_filepath <= len_extension)
		error_exit(ERR_MSG_FILEPATH, NULL, EXIT_FAILURE);
	if (filepath[len_filepath - len_extension - 1] == '/')
		error_exit(ERR_MSG_FILEPATH, NULL, EXIT_FAILURE);
	while (len_extension)
	{
		len_extension--;
		len_filepath--;
		if (filepath[len_filepath] != extension[len_extension])
			error_exit(ERR_MSG_FILE_EXTENSION, NULL, EXIT_FAILURE);
	}
}

void	check_args(const int argc, const char *argv[])
{
	if (argc != 2)
	{
		(void)argv;
		error_exit(ERR_MSG_ARGS, NULL, EXIT_FAILURE);
	}
	check_file_extension(argv[1]);
}
