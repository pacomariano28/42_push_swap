/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarian <frmarian@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:32:16 by frmarian          #+#    #+#             */
/*   Updated: 2024/09/27 12:32:52 by frmarian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft/libft.h"
# include "./lib/printf/ft_printf.h"
# include "stdlib.h"
# include "stdbool.h"
# include "limits.h"
# include "stdint.h"

/* CHUNK STRUCTS */
enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
};

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split_dest;

/* STACK  */
typedef struct s_pile
{
	int	*array;
	int	size;
	int	top;
	int	bottom;
}	t_pile;

typedef struct stack
{
	t_pile	a;
	t_pile	b;
}	t_stack;

/* --------------- */

/* STACKS INITIALIZATION */
char		**init_stacks(t_stack *stacks, int ac, char **av, bool *split_flag);
char		**process_av(int *ac, char **av);
void		init_pile(t_stack *stacks, t_pile *pile, int ac);
void		fill_pile(t_stack *stacks, t_pile *pile, int ac, char **av);

/* STACKS UTILITIES */
bool		valid_av(char *av);
void		check_doubles(t_stack *stacks, int *nums, int ac);
void		nums_ranked(int *nums, int *pile, int ac);

/* ERROR */
void		error(t_stack *stacks);
void		free_split(char **split_av);
void		free_and_exit(t_stack *stacks);
void		free_stacks(t_stack *stacks);
void		split_check(t_stack *stacks, char **split_av, bool flag);

/* SORT */
void		sort(t_stack *stacks, char **split_av, bool *split_flag);
void		sort_three_a(t_stack *stack);
void		sort_five_a(t_stack *stack);
void		chunk_sort(t_stack *stack);
int			value(t_pile *pile, int n);

/* SORT UTILS */
bool		is_sorted(t_stack *stacks);
int			next_down(t_pile *pile, int index);
int			next_up(t_pile *pile, int index);
bool		is_full(t_pile *pile);
int			current_size(t_pile *pile);

/* CHUNK SORT */
void		rec_chunk_sort(t_stack *stack, t_chunk *to_sort);
void		sort_two(t_stack *stack, t_chunk *to_sort);
void		sort_one(t_stack *stack, t_chunk *to_sort);

/* CHUNK SPLIT */
void		chunk_split(t_stack *stack, t_chunk *to_split, t_split_dest *dest);
void		split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max);
void		set_pivots(enum e_loc loc, int crt_size, int *pvt_1, int *pvt_2);

/* CHUNK UTILS */
int			chunk_max_value(t_stack *stack, t_chunk *chunk);
int			chunk_value(t_stack *stack, t_chunk *chunk, int n);
t_pile		*loc_to_stack(t_stack *stacks, enum e_loc loc);

/* CHUNK MOVEMENTS */
int			move_from_to(t_stack *stack, enum e_loc from, enum e_loc to);
void		move_from_top_a(t_stack *stack, enum e_loc to);
void		move_from_bottom_a(t_stack *stack, enum e_loc to);
void		move_from_top_b(t_stack *stack, enum e_loc to);
void		move_from_bottom_b(t_stack *stack, enum e_loc to);

/* CHUNK SORT OPTIMIZATION */
void		chunk_to_the_top(t_stack *stack, t_chunk *to_sort);

/* PILE MOVEMENTS */
void		push(t_pile *src, t_pile *dest);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
/* --- */
void		rotate(t_pile *pile);
void		rotate_a(t_stack *pile);
void		rotate_b(t_stack *pile);
void		rotate_ab(t_stack *pile);
/* --- */
void		r_rotate(t_pile *pile);
void		r_rotate_a(t_stack *stack);
void		r_rotate_b(t_stack *stack);
void		r_rotate_ab(t_stack *stack);
/* --- */
void		swap(t_pile *pile);
void		swap_a(t_stack *pile);
void		swap_b(t_stack *pile);
void		swap_ab(t_stack *pile);

#endif