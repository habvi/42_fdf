#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

static void	init_map(t_map *map, size_t line_count, const t_list *data)
{
	map->width = 0;
	map->height = line_count;
	// ft_calloc?
	map->height_map = (int **)malloc(sizeof(int *) * map->height);
	// ft_calloc?
	map->color_map = (int **)malloc(sizeof(int *) * map->height);
	if (map->height_map == NULL || map->color_map == NULL)
		clear_and_exit(map, data, MALLOC_ERROR_MSG, 0);
}

void	parse_map(t_map *map, t_list *data, size_t line_count)
{
	const t_list	*head = data;
	size_t			i;
	size_t			len;

	init_map(map, line_count, head);
	i = 0;
	while (data)
	{
		len = ft_strlen(data->content);
		if (data->content[len - 1] == '\n')
		{
			data->content[len - 1] = '\0';
			len--;
		}
		// printf("|%s| %zu\n", data->content, len);
		set_data_to_map(map, head, data, i);
		// set_height_map, set_color_map, error
		data = data->next;
		i++;
	}
}
