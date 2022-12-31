#include "fdf.h"
#include <stdio.h> // to do: erase printf

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
	list = NULL;
}

static void	del(void *content)
{
	free(content);
}

void	clear_data(t_list *data)
{
	ft_lstclear(&data, del);
}

void	clear_map_to_n(t_map *map, size_t n)
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

// only one ptr
int	close_window(int keycode, t_mlx *mlxs)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		clear_data(mlxs->data);
		clear_map_to_n(mlxs->map, mlxs->map->height);
		// mlx
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		mlx_destroy_window(mlxs->display->mlx_p, mlxs->display->win_p);
		mlx_destroy_display(mlxs->display->mlx_p);
		free(mlxs->display->mlx_p);
		exit(SUCCESS);
	}
	return (0);
}
