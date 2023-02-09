#include "fdf.h"
#include "mlx.h"
#include "menu.h"

static void	init_t_menu(t_menu *menu)
{
	menu->x_title = WIN_MARGIN + W_TITLE_SPACE;
	menu->x_sub_title = WIN_MARGIN + W_SUBTITLE_SPACE;
	menu->x_keycode = WIN_MARGIN + W_CONTENT_SPACE;
}

static void	draw(\
const t_mlx *mlxs, const size_t coord_x[], size_t *y, const char *menu_str[])
{
	size_t	i;

	i = 0;
	while (menu_str[i])
	{
		*y += H_LINE_SPACE;
		mlx_string_put(mlxs->display->mlx_p, mlxs->display->win_p, \
						coord_x[i], *y, MENU_STR_COLOR, (char *)menu_str[i]);
		i++;
	}
}

static void	draw_key_usage(const t_mlx *mlxs, const t_menu *menu, size_t *y)
{
	static const char	*menu_str[] = {"usage", \
										"----- KEY -----", \
										"*Translate*", \
										"up, down, left, right", \
										"*Rotate*", \
										"X,Y,Z : J/K, H/L, N/M", \
										"*Height Emphasis(max 10)*", \
										"1, 2", \
										"*Isometric or Parallel*", \
										"I, P", \
										"*Close window*", \
										"ESC", NULL};
	const size_t		coord_x[] = {menu->x_sub_title, \
									menu->x_title, \
									menu->x_sub_title, menu->x_keycode, \
									menu->x_sub_title, menu->x_keycode, \
									menu->x_sub_title, menu->x_keycode, \
									menu->x_sub_title, menu->x_keycode, \
									menu->x_sub_title, menu->x_keycode};

	draw(mlxs, coord_x, y, menu_str);
}

static void	draw_mouse_usage(const t_mlx *mlxs, const t_menu *menu, size_t *y)
{
	static const char	*menu_str[] = {"----- MOUSE -----", \
										"*Zoom in / out*", \
										"scroll up, down", NULL};
	const size_t		coord_x[] = {menu->x_title, \
									menu->x_sub_title, \
									menu->x_keycode};

	draw(mlxs, coord_x, y, menu_str);
}

void	draw_menu_string(const t_mlx *mlxs)
{
	t_menu	menu;
	size_t	y;

	init_t_menu(&menu);
	y = WIN_MARGIN;
	draw_key_usage(mlxs, &menu, &y);
	draw_mouse_usage(mlxs, &menu, &y);
}
