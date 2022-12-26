#include "fdf.h"

void	display_map(t_list *data, size_t line_count)
{
	t_map		map;
	t_for_exit	for_exit;

	parse_map(&map, data, line_count);
	// ↓↓↓ before exit: must free(map->height_map, map->color_map) ↓↓↓

	for_exit.map = &map;
	for_exit.data = data;
	draw_map(&map, &for_exit);

	// ↑↑↑ before exit: must clear_data(data) ↑↑↑
	// clear_data(data);
	// clear_map_to_n(&map, map.height);
}
