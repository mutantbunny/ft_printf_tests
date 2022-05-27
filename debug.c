/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:33:24 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/19 00:15:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

int main(void)
{
	char *str = "aaa%";
	//char *expected = "a";

	int copied = ft_printf(str);
	printf("\nCopied: %d\n", copied);
}
