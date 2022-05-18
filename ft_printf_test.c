/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:18:23 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 02:03:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

Test(parse_code, parse_c, .init = redirect_all_stdout)
{
	char *format = "c";
	char *expected = "a";

	int copied = call_two_args_str(parse_code, format, 'a');
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_s, .init = redirect_all_stdout)
{
	char *format = "s";
	char *expected = "abc";

	int copied = call_two_args_str(parse_code, format, "abc");
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_p, .init = redirect_all_stdout)
{
	char *format = "p";
	char *expected = "0xffffffffffffffff";

	int copied = call_two_args_str(parse_code, format, 0xffffffffffffffff);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_d, .init = redirect_all_stdout)
{
	char *format = "d";
	char *expected = "-2147483648";

	int copied = call_two_args_str(parse_code, format, -2147483648);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_i, .init = redirect_all_stdout)
{
	char *format = "i";
	char *expected = "-2147483648";

	int copied = call_two_args_str(parse_code, format, -2147483648);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_u, .init = redirect_all_stdout)
{
	char *format = "u";
	char *expected = "4294967295";

	int copied = call_two_args_str(parse_code, format, 4294967295);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_x, .init = redirect_all_stdout)
{
	char *format = "x";
	char *expected = "ffffffff";

	int copied = call_two_args_str(parse_code, format, 0xffffffff);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_X, .init = redirect_all_stdout)
{
	char *format = "X";
	char *expected = "FFFFFFFF";

	int copied = call_two_args_str(parse_code, format, 0xffffffff);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_percent, .init = redirect_all_stdout)
{
	char *format = "%";
	char *expected = "%";

	int copied = call_two_args_str(parse_code, format);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_code, parse_invalid, .init = redirect_all_stdout)
{
	char *format = "k";
	char *expected = "k";

	int copied = call_two_args_str(parse_code, format);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}
