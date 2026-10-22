/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 14:01:44 by maratana         ###   ########.fr       */
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

	i = 1;
	ret = ft_lstnew(argv[i]);
	i++;
	while (i < argc)
	{
		new = ft_lstnew(argv[i]);
		ft_lstadd_back(ret, new);
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	a = init_a(argc, argv);
	ft_printf("Hello from push_swap!\n");
	return (0);
}
