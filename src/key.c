#include "fdf.h"
#include "hook.h"
#include "mlx.h"
#include "ft_printf.h"

static bool	is_rolled_key(const t_key keycode)
{
	const t_key	keycodes[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, \
							KEY_ONE, KEY_TWO, \
							KEY_J, KEY_K, KEY_H, KEY_L, KEY_N, KEY_M, \
							KEY_I, KEY_P, 0};
	size_t		i;

	i = 0;
	while (keycodes[i])
	{
		if (keycode == keycodes[i])
			return (true);
		i++;
	}
	return (false);
}

static void	move_image(const t_mlx *mlxs, const t_key keycode)
{
	move_in_4_directions((t_mlx *)mlxs, keycode);
	emphasize_height((t_mlx *)mlxs, keycode);
	rotate_in_3_directions((t_mlx *)mlxs, keycode);
	switch_iso((t_mlx *)mlxs, keycode);
}

int	key_hook(const t_key keycode, const t_mlx *mlxs)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode == KEY_ESC)
		close_window(mlxs);
	else if (is_rolled_key(keycode))
	{
		move_image(mlxs, keycode);
		mlx_destroy_image(mlxs->display->mlx_p, mlxs->img->img);
		set_image(mlxs);
		if (mlxs->img->img == NULL)
			exit_img_p(mlxs);
		draw_image(mlxs);
	}
	return (SUCCESS);
}
