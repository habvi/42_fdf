#include <stdlib.h> // malloc
#include "libft.h"
#include "list.h"
#include "fdf.h"
#include "error.h"
#include "draw.h"

static char	**split_map_line(\
	const t_info *info, t_list *data, size_t *list_size, const size_t i)
{
	char	**list;

	list = ft_split(data->content, ' ', list_size);
	if (list == NULL)
		clear_before_exit(info, i, ERROR_MALLOC_FDF);
	return (list);
}

static void	init_color_map(int64_t *map, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		map[i] = NONE_COLOR;
		i++;
	}
}

static void	init_map_line(\
	const t_info *info, char **list, const size_t list_size, const size_t i)
{
	t_map	*map;

	map = info->map;
	map->height_map[i] = (int *)malloc(sizeof(int) * list_size);
	map->color_map[i] = (int64_t *)malloc(sizeof(int64_t) * list_size);
	if (map->height_map[i] == NULL || map->color_map[i] == NULL)
	{
		clear_split_list(list);
		clear_before_exit(info, i + 1, ERROR_MALLOC_FDF);
	}
	init_color_map(map->color_map[i], list_size);
}

static void	check_map_line_width(\
	const t_info *info, char **list, const size_t list_size, const size_t i)
{
	t_map	*map;

	map = info->map;
	if (map->width == 0)
		map->width = list_size;
	else if (map->width != list_size)
	{
		clear_split_list(list);
		clear_before_exit(info, i + 1, ERROR_MAP_WIDTH);
	}
}

// needs i-th data
void	set_data_to_map(t_info *info, t_list *data, const size_t i)
{
	size_t	list_size;
	char	**list;

	list = split_map_line(info, data, &list_size, i);
	init_map_line(info, list, list_size, i);
	check_map_line_width(info, list, list_size, i);
	convert_map_height_and_color(info, list, i);
	clear_split_list(list);
}
