#include "fdf.h"

static void	is_correct_extension(const char *filepath)
{
	const char	extension[] = ".fdf";
	size_t		len_extension;
	size_t		len_filepath;
	char		*msg;

	len_extension = ft_strlen(extension);
	len_filepath = ft_strlen(filepath);
	if (!ft_strchr(filepath, '.') || len_filepath <= len_extension)
	{
		msg = "invalid filepath";
		print_msg_and_exit(msg, (char *)filepath, ERROR);
	}
	while (len_extension)
	{
		len_extension--;
		len_filepath--;
		if (filepath[len_filepath] != extension[len_extension])
		{
			msg = "invalid file's extension";
			print_msg_and_exit(msg, (char *)filepath, ERROR);
		}
	}
}

static const char	*parse_filepath(const char *filepath_org)
{
	const char	*filepath = ft_strtrim(filepath_org, " ");

	if (filepath == NULL)
		print_msg_and_exit(MALLOC_ERROR_MSG, NULL, ERROR);
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
		print_msg_and_exit(strerror(errno), NULL, ERROR);
	return (fd);
}

int	check_args(int argc, char *argv[])
{
	char	*msg;
	int		fd;

	if (argc != 2)
	{
		msg = "invalid number of arguments";
		print_msg_and_exit(msg, NULL, ERROR);
	}
	fd = check_filepath(argv[1]);
	return (fd);
}
