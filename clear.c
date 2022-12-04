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
