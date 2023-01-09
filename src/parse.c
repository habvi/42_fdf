#include "fdf.h"
#include "libft.h"

static void	init_map(const t_info *info, const size_t line_count)
{
	t_map	*map;

	map = info->map;
	map->width = 0;
	map->height = line_count;
	map->height_map = (int **)malloc(sizeof(int *) * map->height);
	map->color_map = (int **)malloc(sizeof(int *) * map->height);
	if (map->height_map == NULL || map->color_map == NULL)
		clear_before_exit(info, ERR_MSG_MALLOC, 0);
}

void	parse_map(const t_info *info, const size_t line_count)
{
	t_list	*data;
	size_t	i;
	size_t	len;

	init_map(info, line_count);
	data = info->data;
	i = 0;
	while (data)
	{
		len = ft_strlen(data->content);
		if (data->content[len - 1] == '\n')
		{
			data->content[len - 1] = '\0';
			len--;
		}
		set_data_to_map(info, data, i);
		data = data->next;
		i++;
	}
}
