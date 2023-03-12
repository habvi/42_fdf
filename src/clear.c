#include <stdlib.h> // free, exit
#include "list.h"
#include "fdf.h"
#include "mlx.h"
#include "hook.h"

// parse2
void	clear_split_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
	// to do
	// list = NULL;
}

static void	del(void *content)
{
	free(content);
}

// read, exit
void	clear_data(t_list *data)
{
	ft_lstclear(&data, del);
}

// exit
void	clear_map_to_n(const t_map *map, const size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(map->height_map[i]);
		free(map->color_map[i]);
		i++;
	}
	free(map->height_map);
	free(map->color_map);
}

// key
int	close_window(const t_mlx *mlxs)
{
	clear_data(mlxs->data);
	clear_map_to_n(mlxs->map, mlxs->map->height);
	mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
	mlx_destroy_window(mlxs->display->mlx_p, mlxs->display->win_p);
	mlx_destroy_display(mlxs->display->mlx_p);
	free(mlxs->display->mlx_p);
	exit(EXIT_SUCCESS);
}
