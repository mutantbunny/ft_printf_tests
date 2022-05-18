/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:19:57 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:51:15 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int call_one_arg(int (*f)(va_list vl), ...)
{
	va_list	args;
	int		result;

	va_start(args, f);
	result = f(args);
	va_end(args);
	return (result);
}

int call_two_args(int (*f)(va_list vl, unsigned int fl), unsigned int flags, ...)
{
	va_list	args;
	int		result;

	va_start(args, flags);
	result = f(args, flags);
	va_end(args);
	return (result);
}

int call_two_args_str(int (*f)(const char *str, va_list args), const char *str, ...)
{
	va_list	args;
	int		result;

	va_start(args, str);
	result = f(str, args);
	va_end(args);
	return (result);
}

void	redirect_all_stdout(void)
{
	cr_redirect_stdout();
}
