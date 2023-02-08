#ifndef MENU_H
# define MENU_H

# include <stdlib.h>

# define MENU_HEIGHT		320
# define MENU_WIDTH			180
# define WIN_MARGIN			30

# define W_TITLE_SPACE		35
# define W_SUBTITLE_SPACE	10
# define W_CONTENT_SPACE	30

# define H_LINE_SPACE		20

# define MENU_BG_COLOR		0x00e8e8e8
# define MENU_STR_COLOR		0x00000000

typedef struct s_menu {
	size_t	x_title;
	size_t	x_sub_title;
	size_t	x_keycode;
}	t_menu;

// draw_menu.c
void	draw_menu_string(const t_mlx *mlxs);

#endif
