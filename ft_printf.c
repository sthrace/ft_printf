/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:32:14 by sthrace           #+#    #+#             */
/*   Updated: 2021/02/16 16:35:33 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
	int			i;
	t_struct	f;

	va_start(args, format);
	str = (char *)format;
	g_fsize = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_init_formats(&f);
			i = ft_parser(str, args, (i + 1), &f);
		}
		else
			g_fsize += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (g_fsize);
}