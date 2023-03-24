/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parthur- <parthur-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:07:42 by parthur-          #+#    #+#             */
/*   Updated: 2023/03/22 22:16:09 by parthur-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char	*ft_strcat(char *dest, char *src);

void	set_str(char *src, char *dest)
{
	int	pos = 0;

	while (src[pos] != '\0')
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
}

bool	same_str(char *expected, char *output, int len)
{
	int pos;
	int res;

	res = 1;
	pos = 0;
	while (pos < len)
	{
		char e = expected[pos];
		char o = output[pos];
		if (e != o)
		{
			printf("in pos %d, expected: %d and got: %d\n",
					pos, e, o);
			res = 0;
		}
		pos++;
	}
	if (!res)
		printf("'%s' : '%s' \n", expected, output);
	return res;
}

void reset_strs(char *a, char *b, char *value)
{
	set_str(value, a);
	set_str(value, b);
}

int main() {
	char *s2 = "aaaaa";
	char s1[100] = "";
	char std_s1[100] = "";

	s2 = "xyz";
	reset_strs(std_s1, s1, "aaaa");
	char *res = ft_strcat(s1, s2);
	char *std_res = strcat(std_s1, s2);
	printf("same string: yours: '%s', std: '%s', %i\n", res, std_res, same_str(std_s1, s1, 10));

	s2 = "";
	reset_strs(std_s1, s1, "aaaa");
	res = ft_strcat(s1, s2);
	std_res = strcat(std_s1, s2);
	printf("same string: yours: '%s', std: '%s': %i\n", res, std_res, same_str(std_res, res, 10));
}
