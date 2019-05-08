#include "libft.h"

int		ft_nblenbase(uintmax_t n, unsigned int base)
{
	return (n < base ? 1 : 1 + ft_nblenbase(n / base, base));
}
