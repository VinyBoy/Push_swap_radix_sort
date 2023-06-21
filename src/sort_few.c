/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnieto-j <vnieto-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:52:47 by viny              #+#    #+#             */
/*   Updated: 2023/06/21 15:34:18 by vnieto-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_few(t_nb **stack_a, t_nb **stack_b, int argc)
{
	if (argc == 3)
		sort_two(stack_a);
	else if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5 || argc == 6)
		sort_four_five(stack_a, stack_b, argc);
}

void	sort_two(t_nb **stack_a)
{
	if (a_is_sorted(*stack_a) == 1)
		swap(stack_a, 'a');
}

void	sort_three(t_nb **stack_a)
{
	const int	a = (*stack_a)->nb;
	const int	b = (*stack_a)->next->nb;
	const int	c = (*stack_a)->next->next->nb;

	if (a_is_sorted(*stack_a) == 1)
	{
		if (a > b && b < c && a < c)
			swap(stack_a, 'a');
		if (a < b && b > c && a > c)
			reverse_rotate(stack_a, 'a');
		if (a > b && b < c && a > c)
			rotate(stack_a, 'a');
		if (a < b && b > c && a < c)
		{
			swap(stack_a, 'a');
			rotate(stack_a, 'a');
		}
		if (a > b && b > c && a > c)
		{
			swap(stack_a, 'a');
			reverse_rotate(stack_a, 'a');
		}
	}
}

void	sort_four_five(t_nb **stack_a, t_nb **stack_b, int argc)
{
	if (argc == 5)
	{
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_a, stack_b);
		sort_pa_four(stack_a);
	}
	else if (argc == 6)
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort_three(stack_a);
		push_a(stack_a, stack_b);
		sort_pa_four(stack_a);
		push_a(stack_a, stack_b);
		sort_pa_five(stack_a);
	}
}

void	sort_pa_four(t_nb **stack_a)
{
	int	i;

	i = return_pos(stack_a);
	if (i == 1)
		;
	else if (i == 2)
		swap(stack_a, 'a');
	else if (i == 3)
	{
		reverse_rotate(stack_a, 'a');
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (i == 4)
		rotate(stack_a, 'a');
	else
		ft_exit_error();
}
