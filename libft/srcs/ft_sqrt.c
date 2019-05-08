#include "libft.h"

double	ft_sqrt(double nb)
{
	double x;
	double y;
	double e;

	x = nb;
	y = 1;
	e = 0.000001;
	while (x - y > e)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
}