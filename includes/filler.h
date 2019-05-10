#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_point
{
	int			i;
	int			x;
	int			y;
	double		min;
	int			good;
}				t_point;

typedef struct	s_piece
{
	int			width;
	int			height;
	int			p_cnt;
	t_point		*p;
	char 		**square;
}				t_piece;

typedef struct	s_map
{
	int			width;
	int			height;
	int			size;
	char 		**board;
}				t_map;

typedef struct	s_filler
{
	char		me;
	char		bot;
	int			size;
	int			init_m;
	char		*data;
	t_map		map;
	t_piece		piece;
	t_point		pnt;
}				t_filler;


/*
**-------------------------------- INIT GAME --------------------------------
*/

int		get_player_id(t_filler *filler);
int		get_map_size(t_filler *filler);
int		get_piece_size(t_filler *filler);
int		init_map(t_filler *filler);
int		init_piece(t_filler *filler);

/*
**----------------------------------- MAP -----------------------------------
*/

int		check_map_data(t_filler *filler);
//int		fill_map(t_filler *filler, char *line);
int		fill_map(t_filler *filler);
int		parse_map(t_filler *filler);

/*
**---------------------------------- PIECE ----------------------------------
*/

int		valid_line(t_filler *filler, char *line);
int		fill_piece(t_filler *filler);
int		parse_piece(t_filler *filler);
void	get_point_pos(t_filler *filler);

/*
**-------------------------------- TEST PIECE ---------------------------------
*/

int		is_pnt_placeable(t_filler *filler, t_point *to_test, t_point *ref);
int		check_piece_pnts(t_filler *filler, t_point *ref);
int		check_around_ref(t_filler *filler, t_point *ref);
void	free_piece(t_piece *piece);

/*
**----------------------------- DIST CALCULATIONS -----------------------------
*/

int		get_min_dist(t_filler *filler, t_point *ref);
double	min_dist(t_filler *filler, t_point *test, t_point *ref, t_point *bot);
double	piece_pnt_min_dist(t_filler *filler, t_point *ref, t_point *bot);

/*
**-------------------------------- FILLER ---------------------------------
*/

int		main(void);
int		get_info(t_filler *filler);
int		play(t_filler *filler);
int		errors(t_filler *filler, int i);


void	print_piece_pos(t_filler *filler);
void	print_map(t_filler *filler);
void	print_pos(t_filler *filler);
void	print_piece(t_filler *filler);
void	free_map(t_map *map);
//void	free_map(t_filler *filler);
void	free_struct(t_filler *filler);

int		check_good(t_filler *filler);

int		get_info(t_filler *filler);

int		init_game(t_filler *filler);
int		start_game(t_filler *filler);
int		game_end(t_filler *filler, int end);
int		my_pos(t_filler *filler, t_point *ref);
int	check_overflow(t_filler *filler, int x, int y);
int		chek_map_line_nb(char *str);
int		check_map_first_line(char *str);


#endif