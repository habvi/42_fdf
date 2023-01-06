#ifndef MENU_H
# define MENU_H

# include <stdlib.h>

# define MENU_HEIGHT				320
# define MENU_WIDTH					180
# define WIN_MARGIN					50

# define W_TITLE_SPACE				40
# define W_SUBTITLE_SPACE			10
# define W_CONTENT_SPACE			30

# define H_LINE_SPACE				20

# define MENU_COLOR					0x00000000

typedef struct s_menu {
	size_t	x_title;
	size_t	x_sub_title;
	size_t	x_keycode;
}	t_menu;

// draw_menu.c
void	draw_menu_string(t_mlx *mlxs);

#endif
