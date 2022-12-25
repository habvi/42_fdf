#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

void	exit_malloc_error(t_map *map, t_list *data)
{
	printf("Error no.%d : %s\n", errno, strerror(errno));
	clear_data(data);
	clear_map_to_n(map, 0);
	exit (errno);
}

void	exit_map_error(void)
{
	printf(INVALID_MAP_MSG);
	exit (1);
}

void	set_data_to_map(t_map *map, t_list *head, t_list *data, size_t i)
{
	char	**list;
	size_t	list_size;
	size_t	j;
	int		num;
	bool	is_invalid_num;

	list = ft_split(data->content, ' ', &list_size);
	if (errno)
		exit_malloc_error(map, head);
	// to do: width error
	map->height_map[i] = (int *)malloc(sizeof(int) * list_size);
	map->color_map[i] = (int *)malloc(sizeof(int) * list_size);
	if (errno)
	{
		// to do: free height_map[0 ~ now]
		exit_malloc_error(map, head);
	}
	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		// exit_map_width_error(); free all
		printf("Error: width\n");
		printf(INVALID_MAP_MSG);
		exit (1);
	}
	// to do: add color_map, error
	// debug_split_list(list);
	is_invalid_num = true;
	j = 0;
	while (list[j] != NULL)
	{
		is_invalid_num &= ft_atoi_with_bool(list[j], &num);
		map->height_map[i][j] = num;
		// printf("%s/%d ", list[j], num);
		j++;
	}
	// printf("\n");
	clear_split_list(list);
	if (!is_invalid_num)
	{
		printf(INVALID_MAP_MSG);
		clear_data(head);
		clear_map_to_n(map, i + 1);
		exit (1);
	}
}

void	init_map(t_map *map, t_list *data, size_t line_count)
{
	size_t	len;
	size_t	i;
	t_list	*head;

	head = data;
	map->width = 0;
	map->height = line_count;
	map->height_map = (int **)malloc(sizeof(int *) * map->height);
	// to do: NULL
	map->color_map = (int **)malloc(sizeof(int *) * map->height);
	// to do: NULL
	if (errno)
		exit_malloc_error(map, head);
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
		// check_width(), error
		// set_height_map, set_color_map, error
		data = data->next;
		i++;
	}
}

void	draw_map(t_list *data, size_t line_count)
{
	t_map		map;
	t_for_exit	for_exit;

	init_map(&map, data, line_count);
	// ↓↓↓ before exit: must free(map->height_map, map->color_map) ↓↓↓

	for_exit.map = &map;
	for_exit.data = data;
	display_map(&map, &for_exit);

	// ↑↑↑ before exit: must clear_data(data) ↑↑↑
	// clear_data(data);
	// clear_map_to_n(&map, map.height);
}
