/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 16:25:08 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

#include "push_swap.h"

//inits stack a by maratana
t_list	*init_a(int argc, char **argv)
{
	t_list	*ret;
	t_list	*new;
	int		i;
	int		*conv;

	i = 1;
	conv = &ft_atoi(argv[i]);
	ret = ft_lstnew(conv);
	i++;
	while (i < argc)
	{
		conv = &ft_atoi(argv[i]);
		new = ft_lstnew(conv);
		ft_lstadd_back(&ret, new);
		i++;
	}
	return (ret);
}

#include "push_swap.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d ", *(*lst)->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc < 2)
	{
		ft_printf("Usage: ./push_swap <numbers...>\n");
		return (1);
	}
	a = init_a(argc, argv);
	if (!a)
		return (1);
	ft_printf("Before swap:\n");
	print_list(a);
	/*swap(&a, 'a');
	ft_printf("After swap:\n");
	print_list(a);*/
	return (0);
}
