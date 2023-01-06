#ifndef COLOR_H
# define COLOR_H

# define COLOR_MASK		0xFF
# define RED_SHIFT		16
# define GREEN_SHIFT	8

typedef enum e_color
{
	COLOR_WHITE = 0x00ffffff,
	COLOR_PINK = 0x00f193df,
	COLOR_GREEN = 0x0061ff76
}	t_color;

// color.c
int	get_current_color(t_point current, t_point start, \
						t_point end, const t_xy delta);

#endif
