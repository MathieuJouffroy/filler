#include "filler.h"

int	check_map_data(t_filler *filler)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (ft_strcmp(filler->data, line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	ft_memdel((void**)&line);
	filler->pnt.min = filler->size;
	return (1);
}

int		fill_map(t_filler *filler)
{
	int		i;
	char *line;

	line = NULL;
	i = 0;
	if (get_next_line(0, &line) <= 0)
    	return (0);
	ft_memdel((void**)&line);
	while (i < filler->map.height)
	{
		if (get_next_line(0, &line) <= 0)
		{
			ft_memdel((void**)&line);
    		return (0);
		}
		filler->map.board[i] = ft_strsub(line, 4, filler->map.width + 1);
		ft_memdel((void**)&line);
		i++;
	}
	return (1);
}

int		parse_map(t_filler *filler)
{
	if (filler->init_m == 1)
	{
		if (!check_map_data(filler))
			return (errors(filler, 3));
	}
	if (!fill_map(filler))
		return (errors(filler, 5));
	filler->init_m = 1;
	return (1);
}