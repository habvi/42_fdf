#ifndef HOOK_H
# define HOOK_H

# include <X11/keysym.h>

# define SHIFT_WIDTH		40
# define ANGLE_ROTATE		10

# define Z_LOWER_BOUNDS		1
# define Z_UPPER_BOUNDS		11
# define Z_EMPHASIS_DELTA	1
# define ADJUST_DELTA		10
# define ZOOM_DELTA			(1.5)

typedef enum e_key {
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
	KEY_ONE = XK_1,
	KEY_TWO = XK_2,
	KEY_H = XK_h,
	KEY_J = XK_j,
	KEY_K = XK_k,
	KEY_L = XK_l,
	KEY_N = XK_n,
	KEY_M = XK_m,
	KEY_I = XK_i,
	KEY_P = XK_p,
	KEY_ESC = XK_Escape
}	t_key;

typedef enum e_mouse {
	MOUSE_UP = 4,
	MOUSE_DOWN = 5
}	t_mouse;

// mouse.c
int		mouse_hook(\
		const t_mouse mouse_code, const int x, const int y, t_mlx *mlxs);
int		minimize_window(const t_mlx *mlxs);

// key.c
int		key_hook(const t_key keycode, t_mlx *mlxs);

// key_operation.c
void	move_in_4_directions(t_mlx *mlxs, const t_key keycode);
void	emphasize_height(t_mlx *mlxs, const t_key keycode);
void	rotate_in_3_directions(t_mlx *mlxs, const t_key keycode);
void	switch_iso(t_mlx *mlxs, const t_key keycode);

#endif
