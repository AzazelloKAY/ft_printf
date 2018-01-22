/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:07:01 by akokoshk          #+#    #+#             */
/*   Updated: 2017/10/28 17:07:01 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = 0;
	len += (s1 != NULL) ? ft_strlen(s1) : 0;
	len += (s2 != NULL) ? ft_strlen(s2) : 0;
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (s1 != NULL)
		ft_strcat(res, s1);
	if (s2 != NULL)
		ft_strcat(res, s2);
	return (res);
}
