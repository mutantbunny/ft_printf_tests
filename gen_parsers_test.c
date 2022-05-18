/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_parsers_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:02:07 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:23:11 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

Test(parse_char, printable, .init = redirect_all_stdout)
{
	unsigned char ch;
	char *expected = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	int copied = 0;
	for (ch = 32; ch < 127; ch++)
		copied += call_one_arg(parse_char, ch);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_char,lower_non_printable, .init = redirect_all_stdout)
{
	unsigned char ch;
	char expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};
	int copied = 0;
	for (ch = 1; ch < 32; ch++)
		copied += call_one_arg(parse_char, ch);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_char,upper_non_printable, .init = redirect_all_stdout)
{
	unsigned char ch;
	char expected[] =	{127, 128, 129, 130, 131, 132, 133, 134, 135, 136,
						 137, 138, 139, 140, 141, 142, 143, 144, 145, 146,
						 147, 148, 149, 150, 151, 152, 153, 154, 155, 156,
						 157, 158, 159, 160, 161, 162, 163, 164, 165, 166,
						 167, 168, 169, 170, 171, 172, 173, 174, 175, 176,
						 177, 178, 179, 180, 181, 182, 183, 184, 185, 186,
						 187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
						 197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
						 207, 208, 209, 210, 211, 212, 213, 214, 215, 216,
						 217, 218, 219, 220, 221, 222, 223, 224, 225, 226,
						 227, 228, 229, 230, 231, 232, 233, 234, 235, 236,
						 237, 238, 239, 240, 241, 242, 243, 244, 245, 246,
						 247, 248, 249, 250, 251, 252, 253, 254, 255, 0};
	int copied = 0;
	for (ch = 127; ch < 255; ch++)
		copied += call_one_arg(parse_char, ch);
	ch = 255;
	copied += call_one_arg(parse_char, ch);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_pointer, null_ptr, .init = redirect_all_stdout)
{
	void *ptr = NULL;
	char *expected = "(nil)";

	int copied = call_one_arg(parse_pointer, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_pointer, ptr_equal_one, .init = redirect_all_stdout)
{
	void *ptr = (void *)0x1;
	char *expected = "0x1";

	int copied = call_one_arg(parse_pointer, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_pointer, ptr_equal_0xf, .init = redirect_all_stdout)
{
	void *ptr = (void *)0xf;
	char *expected = "0xf";

	int copied = call_one_arg(parse_pointer, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_pointer, ptr_equal_0xffffffffffffffff, .init = redirect_all_stdout)
{
	void *ptr = (void *)0xffffffffffffffff;
	char *expected = "0xffffffffffffffff";

	int copied = call_one_arg(parse_pointer, ptr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_string, empty_str, .init = redirect_all_stdout)
{
	char *str = "";
	char *expected = "";

	int copied = call_one_arg(parse_string, str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_string, null_str, .init = redirect_all_stdout)
{
	char *str = NULL;
	char *expected = "(null)";

	int copied = call_one_arg(parse_string, str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_string, str_len_one, .init = redirect_all_stdout)
{
	char *str = "a";
	char *expected = "a";

	int copied = call_one_arg(parse_string, str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_string, str_len_five, .init = redirect_all_stdout)
{
	char *str = "abcde";
	char *expected = "abcde";

	int copied = call_one_arg(parse_string, str);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}
