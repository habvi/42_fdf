#include "fdf.h"
#include "../libft/include/libft.h"

static const char	**split_map_line(\
					t_info *info, t_list *data, size_t *list_size, size_t i)
{
	const char	**list = NULL;

	list = (const char **)ft_split(data->content, ' ', list_size);
	if (list == NULL)
		clear_before_exit(info, ERR_MSG_MALLOC, i);
	return (list);
}

static void	init_color_map(int *map, int x, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		map[i] = x;
		i++;
	}
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
		clear_before_exit(info, ERR_MSG_MALLOC, i + 1);
	}
	init_color_map(map->color_map[i], -1, list_size);
}

static void	check_map_line_width(\
			t_info *info, const char **list, size_t list_size, size_t i)
{
	t_map	*map;

	map = info->map;
	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		clear_split_list((char **)list);
		clear_before_exit(info, ERR_MSG_MAP_WIDTH, i + 1);
	}
}

size_t	comma_index(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			break;
		i++;
	}
	return (i);
}

static void	convert_map_atoi(t_info *info, const char **list, size_t i)
{
	t_map	*map;
	bool	is_invalid_num;
	size_t	j;
	size_t	max_len;
	int		num;

	map = info->map;
	is_invalid_num = true;
	j = 0;
	while (list[j] != NULL)
	{
		// convert_map_height();
		max_len = comma_index(list[j]);
		is_invalid_num &= ft_atoi_n_with_bool(list[j], &num, BASE10, max_len);
		map->height_map[i][j] = num;
		// printf("map_height : %zu %d %d\n", max_len, is_invalid_num, map->height_map[i][j]);
		// convert_map_color();
		if (list[j][max_len] == ',')
		{
			num = 0;
			is_invalid_num &= ft_atox_with_bool(&list[j][max_len + 1], &num);
			map->color_map[i][j] = num;
			// printf("map_color %d %d[[%s]]: \n", num, is_invalid_num, &list[j][max_len + 1]);
		}
		j++;
		// printf("\n\n");
	}
	if (!is_invalid_num)
	{
		clear_split_list((char **)list);
		clear_before_exit(info, ERR_MSG_MAP_HEIGHT, i + 1);
	}
}

// needs i-th data
void	set_data_to_map(t_info *info, t_list *data, size_t i)
{
	size_t		list_size;
	const char	**list = split_map_line(info, data, &list_size, i);

	init_map_line(info, list, list_size, i);
	check_map_line_width(info, list, list_size, i);
	convert_map_atoi(info, list, i);
	clear_split_list((char **)list);
}
