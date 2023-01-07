#ifndef COLOR_H
# define COLOR_H

# define COLOR_MASK		0xFF
# define RED_SHIFT		16
# define GREEN_SHIFT	8

typedef enum e_color
{
	COLOR_WHITE = 0x00ffffff,
	COLOR_PINK = 0x00f193df,
	// COLOR_YELLOW = 0x00f2ec5a,
	// COLOR_GREEN = 0x0061ff76,
	COLOR_BLUE = 0x002a89e5
}	t_color;

// color.c
void	set_default_color(t_point *point, const int z);
int		get_current_color(const t_point current, t_point start, \
							t_point end, const t_xy delta);

#endif
