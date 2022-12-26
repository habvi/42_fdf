#include "fdf.h"

// to do: 4 val
static const char	**split_map_line(t_map *map, const t_list *head, t_list *data, size_t *list_size, size_t i)
{
	const char	**list = NULL;

	list = (const char **)ft_split(data->content, ' ', list_size);
	if (list == NULL)
		clear_and_exit(map, head, MALLOC_ERROR_MSG, i);
	return (list);
}

static void	init_map_line(t_map *map, const t_list *head, const char **list, size_t list_size, size_t i)
{
	map->height_map[i] = (int *)malloc(sizeof(int) * list_size);
	map->color_map[i] = (int *)malloc(sizeof(int) * list_size);
	if (map->height_map[i] == NULL || map->color_map[i] == NULL)
	{
		clear_split_list((char **)list);
		clear_and_exit(map, head, MALLOC_ERROR_MSG, i + 1);
	}
}

static void	check_map_line_width(t_map *map, const t_list *head, const char **list, size_t list_size, size_t i)
{
	char	*msg;

	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		clear_split_list((char **)list);
		msg = "invalid map width";
		clear_and_exit(map, head, msg, i + 1);
	}
}

static void	convert_map_height_str_to_int(t_map *map, const t_list *head, const char **list, size_t i)
{
	size_t		j;
	int			num;
	bool		is_invalid_num;
	char		*msg;

	is_invalid_num = true;
	j = 0;
	while (list[j] != NULL)
	{
		is_invalid_num &= ft_atoi_with_bool(list[j], &num);
		map->height_map[i][j] = num;
		j++;
	}
	if (!is_invalid_num)
	{
		clear_split_list((char **)list);
		msg = "invalid map height integer";
		clear_and_exit(map, head, msg, i + 1);
	}
}

void	set_data_to_map(t_map *map, const t_list *head, t_list *data, size_t i)
{
	size_t		list_size;
	const char	**list = split_map_line(map, head, data, &list_size, i);

	init_map_line(map, head, list, list_size, i);
	check_map_line_width(map, head, list, list_size, i);

	// to do: add color_map, error
	convert_map_height_str_to_int(map, head, list, i);
	clear_split_list((char **)list);
}
