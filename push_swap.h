/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:17 by ccascava          #+#    #+#             */
/*   Updated: 2026/11/11 15:57:47 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "utils.h"

t_list	*init_a(char **argv);
void	print_list(t_list *lst_a, t_list *lst_b);
void	bubble_sort(t_list **a, t_list **b);
int		is_sorted(t_list **lst);
void	complex_sort(t_list **a, t_list **b, int size);

#endif
