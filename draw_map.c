#include "fdf.h"
#include <stdio.h> // todo: printf -> ft_printf

void	exit_malloc_error(t_list **data)
{
	printf("Error no.%d : %s\n", errno, strerror(errno));
	clear_data(data);
	exit (errno);
}

void	exit_map_error(void)
{
	printf("Error: invalid map\n");
	exit (1);
}

void	init_map(t_map *map, t_list *data, size_t line_count)
{
	size_t	len;

	map->height = line_count;
	map->height_map = (int **)malloc(sizeof(int *) * (map->height + 1));
	map->color_map = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (errno)
		exit_malloc_error(&data);
	while (data)
	{
		len = ft_strlen(data->content);
		if (data->content[len - 1] == '\n')
		{
			data->content[len - 1] = '\0';
			len--;
		}
		printf("|%s| %zu\n", data->content, len);
		// ft_split(data->content, ' '), error
		// check_width(), error
		// set_height_map, set_color_map, error
		data = data->next;
	}
	map->height_map[map->height] = NULL;
	free(map->height_map);
	free(map->color_map);
}

void	draw_map(t_list **data, size_t line_count)
{
	t_map	map;

	init_map(&map, *data, line_count);
	// ↓↓↓ before exit: must free(map->height_map, map->color_map) ↓↓↓

	// display_map(data);

	// ↑↑↑ before exit: must clear_data(data) ↑↑↑
	clear_data(data);
}
