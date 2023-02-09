#include "libft.h"
#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"

// todo

// args, read
void	error_exit(const char *msg, void *ptr, const int status)
{
	ft_printf("Error: %s\n", msg);
	if (ptr)
		free(ptr);
	exit(status);
}

// parse, parse2
void	clear_before_exit(const t_info *info, const char *msg, const size_t n)
{
	clear_data((t_list *)info->head);
	clear_map_to_n(info->map, n);
	error_exit(msg, NULL, EXIT_FAILURE);
}

// display
void	exit_mlx_p(const t_mlx *mlxs)
{
	clear_data((t_list *)mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	error_exit(ERR_MLX, NULL, EXIT_FAILURE);
}

// display
void	exit_win_p(const t_mlx *mlxs)
{
	clear_data((t_list *)mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	mlx_destroy_display(mlxs->display->mlx_p);
	free(mlxs->display->mlx_p);
	error_exit(ERR_MLX, NULL, EXIT_FAILURE);
}

// display, image, key, mouse
void	exit_img_p(const t_mlx *mlxs)
{
	clear_data((t_list *)mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	mlx_destroy_window(mlxs->display->mlx_p, mlxs->display->win_p);
	mlx_destroy_display(mlxs->display->mlx_p);
	free(mlxs->display->mlx_p);
	error_exit(ERR_MLX, NULL, EXIT_FAILURE);
}
