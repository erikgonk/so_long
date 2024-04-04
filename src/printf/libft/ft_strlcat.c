/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:09:46 by erigonza          #+#    #+#             */
/*   Updated: 2024/03/10 16:14:29 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen2(dst);
	j = 0;
	len = i;
	while (src[j] && dstsize > i + 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (ft_strlen2(dst) < dstsize)
		return (len + ft_strlen2(src));
	else
		return (ft_strlen2(src) + dstsize);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	printf("%zu\n", ft_strlcat(argv[1], argv[2], (size_t)argv[3]));
	return 0;
}*/
