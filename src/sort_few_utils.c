/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viny <viny@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:07:03 by viny              #+#    #+#             */
/*   Updated: 2023/06/20 15:06:20 by viny             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_pos(t_nb **stack)
{
	int		i;
	int		the_nb;
	t_nb	*temp;

	i = 1;
	if (!(*stack))
		return (0);
	temp = (*stack);
	the_nb = temp->nb;
	while (temp && temp->next != NULL)
	{
		if (the_nb > temp->next->nb)
			i++;
		else if (the_nb < temp->next->nb)
			return (i);
		temp = temp->next;
	}
	return (i);
}

void	sort_pa_five_moove_i_four(t_nb **stack_a)
{
	reverse_rotate(stack_a, 'a');
	swap(stack_a, 'a');
	rotate(stack_a, 'a');
	rotate(stack_a, 'a');
}

void	sort_pa_five_moove_i_three(t_nb **stack_a)
{
	swap(stack_a, 'a');
	rotate(stack_a, 'a');
	swap(stack_a, 'a');
	reverse_rotate(stack_a, 'a');
}
