#include "ft_printf.h"

void		ft_type_char(int c, t_struct *f)
{
	if (f->flagleft == 0)
	{
		while (f->width-- > 1)
			if (f->flagzero == 0)
				g_fsize += write(1, " ", 1);
			else
				g_fsize += write(1, "0", 1);
	}
	g_fsize += write(1, &c, 1);
	if (f->flagleft == 1)
		while (f->width-- > 1)
			g_fsize += write(1, " ", 1);
}
