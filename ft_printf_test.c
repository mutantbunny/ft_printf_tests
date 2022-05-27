/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:18:23 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 20:57:25 by gmachado         ###   ########.fr       */
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

Test(ft_printf, no_format_len_1, .init = redirect_all_stdout)
{
	char *str = "a";
	char *expected = "a";

	int copied = ft_printf(str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, no_format_len_44, .init = redirect_all_stdout)
{
	char *str = "The quick brown fox jumps over the lazy dog.";
	char *expected = "The quick brown fox jumps over the lazy dog.";

	int copied = ft_printf(str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, empty_string, .init = redirect_all_stdout)
{
	char *str = "";
	char *expected = "";

	int copied = ft_printf(str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_c_only, .init = redirect_all_stdout)
{
	char *str = "%c";
	char *expected = "a";

	int copied = ft_printf(str, 'a');
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_s_only, .init = redirect_all_stdout)
{
	char *str = "%s";
	char *expected = "abc\ndef\tg\n";

	int copied = ft_printf(str, "abc\ndef\tg\n");
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_null_s_only, .init = redirect_all_stdout)
{
	char *str = "%s";
	char *expected = "(null)";

	int copied = ft_printf(str, NULL);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_p_only, .init = redirect_all_stdout)
{
	char *str = "%p";
	void *ptr = (void *)0xFF;
	char *expected = "0xff";

	int copied = ft_printf(str, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_null_p_only, .init = redirect_all_stdout)
{
	char *str = "%p";
	void *ptr = NULL;
	char *expected = "(nil)";

	int copied = ft_printf(str, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_d_only, .init = redirect_all_stdout)
{
	char *str = "%d";
	int nbr = -2147483648;
	char *expected = "-2147483648";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_i_only, .init = redirect_all_stdout)
{
	char *str = "%i";
	int nbr = -2147483648;
	char *expected = "-2147483648";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_u_only, .init = redirect_all_stdout)
{
	char *str = "%u";
	int nbr = 4294967295;
	char *expected = "4294967295";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_x_only, .init = redirect_all_stdout)
{
	char *str = "%x";
	int nbr = 0xFFFFFFFF;
	char *expected = "ffffffff";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_X_only, .init = redirect_all_stdout)
{
	char *str = "%X";
	int nbr = 0xFFFFFFFF;
	char *expected = "FFFFFFFF";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_percent_only, .init = redirect_all_stdout)
{
	char *str = "%%";
	int nbr = 0xFFFFFFFF;
	char *expected = "%";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(ft_printf, format_percent_unbalanced, .init = redirect_all_stdout)
{
	char *str = "%";
	int nbr = 0xFFFFFFFF;
	char *expected = "";

	int copied = ft_printf(str, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, -1));
}
