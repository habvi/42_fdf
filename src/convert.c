#include "fdf.h"
#include "../libft/include/libft.h"

static size_t	comma_index(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	return (i);
}

static void	calc_z_min_max(t_info *info, const int num)
{
	info->z_min = ft_min(info->z_min, num);
	info->z_max = ft_max(info->z_max, num);
}

static int	convert_height(\
const t_info *info, const char *num_str, size_t *max_len, bool *is_valid_num)
{
	int	num;

	num = 0;
	*max_len = comma_index(num_str);
	*is_valid_num &= ft_atoi_n_with_bool(num_str, &num, BASE10, *max_len);
	if (is_valid_num)
		calc_z_min_max((t_info *)info, num);
	return (num);
}

static int	convert_color(const char *color_str, bool *is_valid_num)
{
	int	num;

	num = 0;
	*is_valid_num &= ft_atox_with_bool(color_str, &num);
	return (num);
}

void	convert_map_height_and_color(\
					const t_info *info, const char **list, const size_t i)
{
	bool	is_valid_num;
	size_t	j;
	int		*height;
	int		*color;
	size_t	max_len;

	is_valid_num = true;
	j = 0;
	while (list[j] != NULL)
	{
		height = &info->map->height_map[i][j];
		*height = convert_height(info, list[j], &max_len, &is_valid_num);
		if (list[j][max_len] == ',')
		{
			color = &info->map->color_map[i][j];
			*color = convert_color(&list[j][max_len + 1], &is_valid_num);
		}
		j++;
	}
	if (!is_valid_num)
	{
		clear_split_list((char **)list);
		clear_before_exit(info, ERR_MSG_INVALID_MAP, i + 1);
	}
}
