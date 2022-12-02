#include "fdf.h"
#include <stdio.h> // todo: printf -> ft_printf

void	exit_malloc_error(t_map *map, t_list *data)
{
	printf("Error no.%d : %s\n", errno, strerror(errno));
	free(map->height_map);
	free(map->color_map);
	clear_data(data);
	exit (errno);
}

void	exit_map_error(void)
{
	printf("Error: invalid map\n");
	exit (1);
}

void	debug_print_list(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		printf("%s ", list[i]);
		i++;
	}
	printf("\n");
}

void	free_all_list(char **list)
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

void	set_data_to_map(t_map *map, t_list *head, t_list *data, size_t i)
{
	char	**list;
	size_t	list_size;
	size_t	j;
	size_t	num;
	bool	is_invalid_num;

	list = ft_split(data->content, ' ', &list_size);
	if (errno)
		exit_malloc_error(map, head);
	// todo: width error
	map->height_map[i] = (int *)malloc(sizeof(int) * list_size);
	if (errno)
	{
		// todo: free height_map[0 ~ now]
		exit_malloc_error(map, head);
	}
	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		// exit_map_width_error(); free all
		printf("Error: width\n");
		exit (1);
	}
	// todo: add color_map, error
	// debug_print_list(list);
	is_invalid_num = true;
	j = 0;
	while (list[j] != NULL)
	{
		is_invalid_num &= ft_atoi_with_bool(list[j], &num);
		map->height_map[i][j] = num;
		printf("%s/%zu ", list[j], num);
		j++;
	}
	printf("\n");
	free_all_list(list);
	free(map->height_map[i]);
	if (!is_invalid_num)
	{
		printf("Error: overflow\n");
		clear_data(head);
		free(map->height_map);
		free(map->color_map);
		exit (1);
	}
}

void	clear_map(t_map *map)
{
	free(map->height_map);
	free(map->color_map);
}

void	init_map(t_map *map, t_list *data, size_t line_count)
{
	size_t	len;
	size_t	i;
	t_list	*head;

	head = data;
	map->width = 0;
	map->height = line_count;
	map->height_map = (int **)malloc(sizeof(int *) * map->height); // todo: NULL
	map->color_map = (int **)malloc(sizeof(int *) * map->height); // todo: NULL
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
	t_map	map;

	init_map(&map, data, line_count);
	// ↓↓↓ before exit: must free(map->height_map, map->color_map) ↓↓↓

	// display_map(map);

	// ↑↑↑ before exit: must clear_data(data) ↑↑↑
	clear_data(data);
	clear_map(&map);
}
