/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:23:01 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/02 14:23:02 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strjoin(int size, char **strs, char *sep);
int				ft_strlen(char *str);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		sep_len;
	int		i;
	char	*result;

	sep_len = ft_strlen(sep);
	i = -1;
	total_length = 1;
	while (++i < size)
		total_length += ft_strlen(strs[i]) + (i != size -1) * sep_len;
	result = malloc(total_length);
	result[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strlcat(result, strs[i], total_length);
		if (i < size - 1)
			ft_strlcat(result, sep, total_length);
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] && dest_length < size)
		dest_length++;
	while (src[src_length])
		src_length++;
	i = 0;
	if (dest_length < size)
	{
		while (src[i] != '\0' && dest_length + i + 1 < size)
		{
			dest[dest_length + i] = src[i];
			i++;
		}
		dest[dest_length + i] = '\0';
	}
	return (dest_length + src_length);
}

/*
#include <stdio.h>

int	main(void)
{
	char *src[3] = {"hello", "world", "howdy"};
	char *str = ft_strjoin(0, src, ", ");
	if (str)
		printf("%s\n", str);
	free(str);
}
*/