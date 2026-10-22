/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:19:17 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 20:27:26 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "lib_ft/libft.h"

t_list	*init_a(int argc, char **argv);
void	swap(t_list **lst, char c);
void	push_a(t_list **lst_a, t_list **lst_b, char c);
void	push_b(t_list **lst_a, t_list **lst_b, char c);
void	rotate(t_list **lst, char c);
void	rotate_both(t_list **lst_a, t_list **lst_b);
void	rev_rotate(t_list **lst, char c);
void	rev_rotate_both(t_list **lst_a, t_list **lst_b);

#endif
