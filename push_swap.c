/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 12:17:14 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/22 13:37:09 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "lib_ft/libft.h"
#include "push_swap.h"

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

int	main(void)
{
	ft_printf("Hello from push_swap!\n");
	return (0);
}
