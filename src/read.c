#include "../libft/include/get_next_line.h" // to do: only gnl?
#include "fdf.h"

static void	add_line_to_data(\
			t_list **data, const t_list *head, char *line, size_t line_count)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (node == NULL)
	{
		clear_data((t_list *)head);
		error_exit(ERR_MSG_MALLOC, NULL, EXIT_FAILURE);
	}
	if (line_count >= 2)
		data = &((*data)->next);
	ft_lstadd_back(data, node);
}

// t_list *data ??
size_t	read_map(int fd, t_list **data)
{
	size_t			line_count;
	char			*line;
	const t_list	*head;

	line_count = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_line_to_data(data, head, line, line_count);
		if (!line_count)
			head = *data;
		line_count++;
	}
	if (*data == NULL)
		error_exit(ERR_MSG_EMPTY, NULL, EXIT_FAILURE);
	return (line_count);
}
