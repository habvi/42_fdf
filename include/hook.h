#ifndef HOOK_H
# define HOOK_H

# define SHIFT_WIDTH	20

# define Z_LOWER_BOUNDS	1
# define Z_UPPER_BOUNDS	5

# define EXIT_EVENT		33
# define EXIT_MASK		17

typedef enum e_key {
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_ESC = 65307
}	t_key;

typedef enum e_mouse {
	// MOUSE_LEFT = 1,
	// MOUSE_RIGHT = 3,
	MOUSE_UP = 4,
	MOUSE_DOWN = 5
}	t_mouse;

// mouse.c
int	mouse_hook(t_mouse mouse_code, int x, int y, t_mlx *mlxs);

// key.c
int	key_hook(t_key keycode, t_mlx *mlxs);

#endif
