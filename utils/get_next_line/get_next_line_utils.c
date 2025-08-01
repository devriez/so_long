/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:41:50 by amoiseik          #+#    #+#             */
/*   Updated: 2025/08/01 17:13:20 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s ++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_res;
	size_t	len_s;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (len == 0)
		return (NULL);
	len_s = ft_strlen(s);
	if ((size_t)start >= len_s)
		return (ft_strdup(""));
	if ((size_t)start + len > len_s)
		reslen = len_s - (size_t)start;
	else
		reslen = len;
	s_res = malloc(sizeof(char) * (reslen + 1));
	if (!s_res)
		return (NULL);
	ft_strlcpy(s_res, s + (size_t)start, reslen + 1);
	return (s_res);
}

size_t	find_end_of_line(const char *s, size_t *full_len)
{
	size_t	i;
	size_t	len_without_cr_vt;

	i = 0;
	while (s[i] != '\n')
		i++;
	*full_len = i + 1;
	len_without_cr_vt = i;
	while (len_without_cr_vt > 0 && \
		(s[len_without_cr_vt - 1] == '\r' || s[len_without_cr_vt - 1] == '\v'))
		len_without_cr_vt--;
	return (len_without_cr_vt);
}
