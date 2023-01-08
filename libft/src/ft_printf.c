#include "ft_printf.h"
#include "libft.h"

static void	parse_format(t_info_pf *info, va_list *args_list)
{
	info->fmt++;
	while (*info->fmt && ft_strchr(FORMAT_TYPES, *info->fmt) == NULL)
	{
		set_format_flags(info);
		if (info->error)
			return ;
	}
	check_ignored_flags(info);
	info->type = *info->fmt;
	convert_to_str(info, args_list);
	if (info->error)
		return ;
	info->fmt++;
	set_field_width(info);
	info->output = (char *)malloc(sizeof(char) * (info->field_width + 1));
	if (info->output == NULL)
	{
		info->error = ERROR_MALLOC;
		free_dup_str(info);
		return ;
	}
	set_output(info);
}

static void	format_specifier_mode(t_info_pf *info, va_list *args_list)
{
	parse_format(info, args_list);
	if (info->error)
		return ;
	info->is_format_specifier = false;
	put_output(info);
}

static void	normal_char_mode(t_info_pf *info)
{
	while (*info->fmt && *info->fmt != '%')
	{
		if (write(STDOUT_FILENO, info->fmt, 1) == ERROR || \
			info->total_len == INT_MAX)
		{
			info->error = EXIT;
			return ;
		}
		info->total_len++;
		info->fmt++;
	}
	info->is_format_specifier = true;
	if (!info->fmt)
		info->fmt++;
}

static void	format_specifier_or_not(t_info_pf *info, va_list *args_list)
{
	while (*info->fmt)
	{
		if (info->is_format_specifier)
		{
			format_specifier_mode(info, args_list);
			clear_fmt_info(info);
		}
		else
			normal_char_mode(info);
		if (info->error)
			return ;
	}
}

int	ft_printf(const char *format, ...)
{
	t_info_pf	info;
	va_list		args_list;

	va_start(args_list, format);
	init_info(&info, format);
	format_specifier_or_not(&info, &args_list);
	va_end(args_list);
	if (info.error)
		return (ERROR);
	return (info.total_len);
}
