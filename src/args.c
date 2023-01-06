#include "fdf.h"

static void	is_correct_extension(const char *filepath)
{
	const char	extension[] = ".fdf";
	size_t		len_extension;
	size_t		len_filepath;

	len_extension = ft_strlen(extension);
	len_filepath = ft_strlen(filepath);
	if (!ft_strchr(filepath, '.') || len_filepath <= len_extension)
		error_exit(ERR_MSG_FILEPATH, (char *)filepath, EXIT_FAILURE);
	while (len_extension)
	{
		len_extension--;
		len_filepath--;
		if (filepath[len_filepath] != extension[len_extension])
			error_exit(ERR_MSG_FILE_EXTENSION, (char *)filepath, EXIT_FAILURE);
	}
}

static const char	*parse_filepath(const char *filepath_org)
{
	const char	*filepath = ft_strtrim(filepath_org, " ");

	if (filepath == NULL)
		error_exit(ERR_MSG_MALLOC, NULL, EXIT_FAILURE);
	return (filepath);
}

static int	check_filepath(const char *filepath_org)
{
	const char	*filepath = parse_filepath(filepath_org);
	int			fd;

	is_correct_extension(filepath);
	fd = open(filepath, O_RDONLY);
	free((char *)filepath);
	if (fd == OPEN_ERROR)
		error_exit(strerror(errno), NULL, EXIT_FAILURE);
	return (fd);
}

int	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
		error_exit(ERR_MSG_ARGS, NULL, EXIT_FAILURE);
	fd = check_filepath(argv[1]);
	return (fd);
}
