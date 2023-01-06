#include "debug.h"

static void	print_list_content(void *content)
{
	printf("%s", content);
}

void	debug_lst(t_list *lst, size_t line_count)
{
	printf("%zu lines\n\n", line_count);
	ft_lstiter(lst, print_list_content);
}

void	debug_split_list(char **list)
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

void	debug_map(t_map *map)
{
	printf("         H: %zu, W: %zu\n", map->height, map->width);
	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t j = 0; j < map->width; j++)
			printf("%d ", map->height_map[i][j]);
		printf("\n");
	}
	printf("==color map==\n");
	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t j = 0; j < map->width; j++)
			printf("%d ", map->color_map[i][j]);
		printf("\n");
	}
}
