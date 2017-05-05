/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 15:19:28 by qdurot            #+#    #+#             */
/*   Updated: 2017/05/02 20:56:13 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	while (n-- % 8)
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	while (n-- % 8)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	return (dst);
}
