#include "fdf.h"
#include <stdio.h> // to do: printf -> ft_printf

// t_list *data ??
size_t	read_map(int fd, t_list **data)
{
	char	*line;
	t_list	*node;
	size_t	line_count;
	t_list	*head;
	char	*msg;

	line_count = 0;
	head = *data;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		// remove '\n' here?
		node = ft_lstnew(line);
		// to do: check data malloc error, free head ~ now
		if (node == NULL)
		{
			clear_data(*data);
			return (0);
		}
		if (line_count >= 2)
			data = &((*data)->next);
		ft_lstadd_back(data, node);
		// to do: all node keeps head
		line_count++;
	}
	if (*data == NULL)
	{
		msg = "empty file";
		print_msg_and_exit(msg, NULL, EXIT_ERROR);
	}
	return (line_count);
}
