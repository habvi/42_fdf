#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"
#include "error.h"
#include <stdint.h>

// args, read
void	error_exit(const uint8_t error_code)
{
	static const char	*msgs[] = {NULL, \
								ERR_MSG_ARGS, \
								ERR_MSG_FILE_EXTENSION, \
								ERR_MSG_FILETYPE, \
								ERR_MSG_INVALID_MAP, \
								ERR_MSG_MALLOC, \
								ERR_MSG_EMPTY, \
								ERR_MSG_MAP_WIDTH, \
								ERR_MLX};

	ft_printf("Error: %s\n", msgs[error_code]);
	exit(EXIT_FAILURE);
}

void	error_exit_errno(const char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

// convert, parse, set_data
void	clear_before_exit(\
			const t_info *info, const uint8_t error_code, const size_t n)
{
	clear_data(info->head);
	clear_map_to_n(info->map, n);
	error_exit(error_code);
}

// display
void	exit_mlx_p(const t_mlx *mlxs)
{
	clear_data(mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	error_exit(ERROR_MLX);
}

// display
void	exit_win_p(const t_mlx *mlxs)
{
	clear_data(mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	mlx_destroy_display(mlxs->display->mlx_p);
	free(mlxs->display->mlx_p);
	error_exit(ERROR_MLX);
}

// display, image, key, mouse
void	exit_img_p(const t_mlx *mlxs)
{
	clear_data(mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	mlx_destroy_window(mlxs->display->mlx_p, mlxs->display->win_p);
	mlx_destroy_display(mlxs->display->mlx_p);
	free(mlxs->display->mlx_p);
	error_exit(ERROR_MLX);
}
