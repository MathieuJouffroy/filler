#include "libft.h"

double	ft_pow(double nb, int pow)
{
	double	tmp;

	if (pow == 0)
		return (1);
	tmp = ft_pow(nb, pow / 2);
	if ((pow % 2) == 0)
		return (tmp * tmp);
	else
	{
		if (pow > 0)
			return (nb * tmp * tmp);
		else
			return ((tmp * tmp) / nb);
	}
}