#ifndef COLOR_H
# define COLOR_H

# define DEFAULT_COLOR_BLOCK	(0.25)
# define COLOR_MASK				0xFF
# define RED_SHIFT				16
# define GREEN_SHIFT			8

typedef enum e_color
{
	COLOR_WHITE = 0x00ffffff,
	COLOR_PINK = 0x00f189df,
	// COLOR_PINK_BLUE = 0x00a889df,
	// COLOR_BLUE_PINK = 0x006c89df,
	COLOR_YELLOW = 0x00f2ec5a,
	COLOR_GREEN = 0x0061ff76,
	COLOR_BLUE = 0x002a89df
}	t_color;

// color.c
int		get_current_color(const t_point current, t_point start, \
							t_point end, const t_xy delta);
void	set_default_color(const t_mlx *mlxs, t_point *point, const int z);

#endif
