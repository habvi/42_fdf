#include "fdf.h"

static void	add_line_to_data(t_list **data, const t_list *head, char *line, size_t line_count)
{
	t_list	*node;

	node = ft_lstnew(line);
	if (node == NULL)
	{
		clear_data((t_list *)head);
		print_msg_and_exit(MALLOC_ERROR_MSG, NULL, EXIT_ERROR);
	}
	if (line_count >= 2)
		data = &((*data)->next);
	ft_lstadd_back(data, node);
	// to do: all node keeps head
}

// t_list *data ??
size_t	read_map(int fd, t_list **data)
{
	size_t			line_count;
	char			*line;
	const t_list	*head = *data;
	char			*msg;

	line_count = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_line_to_data(data, head, line, line_count);
		line_count++;
	}
	if (*data == NULL)
	{
		msg = "empty file";
		print_msg_and_exit(msg, NULL, EXIT_ERROR);
	}
	return (line_count);
}
