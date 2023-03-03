#ifndef ERROR_H
# define ERROR_H

# define OPEN_ERROR					-1

# define ERR_MSG_ARGS				"invalid number of arguments"
# define ERR_MSG_FILE_EXTENSION		"invalid file extension"
# define ERR_MSG_FILETYPE			"invalid file type"
# define ERR_MSG_INVALID_MAP		"invalid map"
# define ERR_MSG_MALLOC				"malloc"
# define ERR_MSG_EMPTY				"empty file"
# define ERR_MSG_MAP_WIDTH			"invalid map width"
# define ERR_MLX					"from mlx"

typedef enum e_error_code {
	INVALID_ARGC = 1,
	INVALID_EXTENSION = 2,
	INVALID_FILETYPE = 3,
	INVALID_MAP = 4,
	ERROR_MALLOC_FDF = 5,
	ERROR_EMPTY_FILE = 6,
	ERROR_MAP_WIDTH = 7,
	ERROR_MLX = 8
}	t_error_code;

#endif
