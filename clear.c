#include "fdf.h"

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

int close_window(int keycode, t_for_exit *for_exit)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC) {
		clear_data(for_exit->data);
		clear_map_to_n(for_exit->map, for_exit->map->height);

		mlx_destroy_image(for_exit->display->mlx_p, for_exit->img->img);
		mlx_destroy_window(for_exit->display->mlx_p, for_exit->display->window_p);
		mlx_destroy_display(for_exit->display->mlx_p);
		free(for_exit->display->mlx_p);
		exit(EXIT_SUCCESS);
	}
	return (0);
}