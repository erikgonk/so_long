/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:30:14 by erigonza          #+#    #+#             */
/*   Updated: 2024/01/20 18:54:10 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*hal;

	hal = (t_list *)malloc(sizeof(*hal));
	if (!hal)
		return (NULL);
	hal->content = content;
	hal->next = NULL;
	return (hal);
}

/*
 int	main(void)
{
	t_list *h;

	char	*j = "hola";

	h = ft_lstnew((void *)j);
	printf("%s\n", (char *)h->content);
	free(h);
	return (0);
}
*/
