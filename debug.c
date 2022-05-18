/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:33:24 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/17 20:12:14 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

int call_two_args(int (*f)(va_list vl, unsigned int fl), unsigned int flags, ...)
{
	va_list	args;
	int		result;

	va_start(args, flags);
	result = f(args, flags);
	va_end(args);
	return (result);
}

int main(void)
{
	char			*expected = "FFFFFFFF";
	unsigned int	nbr = 0xFFFFFFFF;

	printf("Expected: %s, result: ", expected);
	fflush(stdout);
	int	copied = call_two_args(parse_hex, UPPERCASE, nbr);
	printf(", copied: %d\n", copied);
}
