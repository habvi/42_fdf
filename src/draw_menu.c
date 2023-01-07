#include "fdf.h"
#include "menu.h"

static void	init_t_menu(t_menu *menu)
{
	menu->x_title = WIN_MARGIN + W_TITLE_SPACE;
	menu->x_sub_title = WIN_MARGIN + W_SUBTITLE_SPACE;
	menu->x_keycode = WIN_MARGIN + W_CONTENT_SPACE;
}

static void	draw(t_mlx *mlxs, size_t x, size_t *y, char *str)
{
	*y += H_LINE_SPACE;
	mlx_string_put(mlxs->display->mlx_p, mlxs->display->win_p, \
					x, *y, MENU_STR_COLOR, str);
}

static void	draw_key_usage(t_mlx *mlxs, t_menu *menu, size_t *y)
{
	char	*str;

	str = "----- KEY -----";
	draw(mlxs, menu->x_title, y, str);
	str = "*Translate*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "up, down, left, right";
	draw(mlxs, menu->x_keycode, y, str);
	str = "*Rotate*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "H, J, K, L";
	draw(mlxs, menu->x_keycode, y, str);
	str = "*Height Emphasis(max 10)*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "1, 2";
	draw(mlxs, menu->x_keycode, y, str);
	str = "*Isometric or Parallel*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "I, P";
	draw(mlxs, menu->x_keycode, y, str);
	str = "*Close window*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "ESC";
	draw(mlxs, menu->x_keycode, y, str);
}

static void	draw_mouse_usage(t_mlx *mlxs, t_menu *menu, size_t *y)
{
	char	*str;

	str = "----- MOUSE -----";
	draw(mlxs, menu->x_title, y, str);
	str = "*Zoom in / out*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "scroll up, down";
	draw(mlxs, menu->x_keycode, y, str);
	str = "*Close window*";
	draw(mlxs, menu->x_sub_title, y, str);
	str = "x";
	draw(mlxs, menu->x_keycode, y, str);
}

void	draw_menu_string(t_mlx *mlxs)
{
	t_menu	menu;
	size_t	y;
	char	*str;

	init_t_menu(&menu);
	y = WIN_MARGIN;
	str = "usage";
	draw(mlxs, menu.x_sub_title, &y, str);
	draw_key_usage(mlxs, &menu, &y);
	draw_mouse_usage(mlxs, &menu, &y);
}
