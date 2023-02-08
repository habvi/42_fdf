#ifndef HOOK_H
# define HOOK_H

# define SHIFT_WIDTH		40
# define ANGLE_ROTATE		10

# define Z_LOWER_BOUNDS		1
# define Z_UPPER_BOUNDS		11
# define Z_EMPHASIS_DELTA	1
# define ADJUST_DELTA		10
# define ZOOM_DELTA			(1.5)

typedef enum e_key {
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_H = 104,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_N = 110,
	KEY_M = 109,
	KEY_I = 105,
	KEY_P = 112,
	KEY_ESC = 65307
}	t_key;

typedef enum e_mouse {
	MOUSE_UP = 4,
	MOUSE_DOWN = 5
}	t_mouse;

// mouse.c
int	mouse_hook(\
		const t_mouse mouse_code, const int x, const int y, const t_mlx *mlxs);
int	minimize_window(const t_mlx *mlxs);

// key.c
int	key_hook(const t_key keycode, const t_mlx *mlxs);

// key_operation.c
void    move_in_4_directions(t_mlx *mlxs, const t_key keycode);
void    emphasize_height(t_mlx *mlxs, const t_key keycode);
void    rotate_in_3_directions(t_mlx *mlxs, const t_key keycode);
void    switch_iso(t_mlx *mlxs, const t_key keycode);

#endif
