#include "fdf.h"

// to do: 4 val
static const char	**split_map_line(\
					t_info *info, t_list *data, size_t *list_size, size_t i)
{
	const char	**list = NULL;

	list = (const char **)ft_split(data->content, ' ', list_size);
	if (list == NULL)
		clear_and_exit(info, MALLOC_ERROR_MSG, i);
	return (list);
}

static void	init_map_line(\
			t_info *info, const char **list, size_t list_size, size_t i)
{
	t_map	*map;

	map = info->map;
	map->height_map[i] = (int *)malloc(sizeof(int) * list_size);
	map->color_map[i] = (int *)malloc(sizeof(int) * list_size);
	if (map->height_map[i] == NULL || map->color_map[i] == NULL)
	{
		clear_split_list((char **)list);
		clear_and_exit(info, MALLOC_ERROR_MSG, i + 1);
	}
}

static void	check_map_line_width(\
			t_info *info, const char **list, size_t list_size, size_t i)
{
	t_map	*map;
	char	*msg;

	map = info->map;
	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		clear_split_list((char **)list);
		msg = "invalid map width";
		clear_and_exit(info, msg, i + 1);
	}
}

static void	convert_map_height_str_to_int(\
			t_info *info, const char **list, size_t i)
{
	t_map	*map;
	bool	is_invalid_num;
	size_t	j;
	int		num;
	char	*msg;

	map = info->map;
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
		clear_and_exit(info, msg, i + 1);
	}
}

// needs i-th data
void	set_data_to_map(t_info *info, t_list *data, size_t i)
{
	size_t		list_size;
	const char	**list = split_map_line(info, data, &list_size, i);

	init_map_line(info, list, list_size, i);
	check_map_line_width(info, list, list_size, i);
	// to do: add color_map, error
	convert_map_height_str_to_int(info, list, i);
	clear_split_list((char **)list);
}
