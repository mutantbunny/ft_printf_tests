/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsers_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:24:39 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:23:28 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

Test(parse_int, zero, .init = redirect_all_stdout)
{
	char	*expected = "0";
	int		nbr = 0;

	int		copied = call_one_arg(parse_int, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_int, int_min, .init = redirect_all_stdout)
{
	char	*expected = "-2147483648";
	int		nbr = -2147483648;

	int		copied = call_one_arg(parse_int, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_int, int_max, .init = redirect_all_stdout)
{
	char	*expected = "2147483647";
	int		nbr = 2147483647;

	int		copied = call_one_arg(parse_int, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_uint, zero, .init = redirect_all_stdout)
{
	char	*expected = "0";
	int		nbr = 0;

	int		copied = call_one_arg(parse_uint, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_uint, uint_max, .init = redirect_all_stdout)
{
	char	*expected = "4294967295";
	unsigned int	nbr = 4294967295;

	int		copied = call_one_arg(parse_uint, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_hex, zero_lower, .init = redirect_all_stdout)
{
	char	*expected = "0";
	unsigned int	nbr = 0;

	unsigned int	copied = call_two_args(parse_hex, LOWERCASE, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_hex, zero_upper, .init = redirect_all_stdout)
{
	char	*expected = "0";
	unsigned int	nbr = 0;

	int		copied = call_two_args(parse_hex, UPPERCASE, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_hex, uint_max_lower, .init = redirect_all_stdout)
{
	char	*expected = "ffffffff";
	unsigned int	nbr = 0xFFFFFFFF;

	int		copied = call_two_args(parse_hex, LOWERCASE, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}

Test(parse_hex, uint_max_upper, .init = redirect_all_stdout)
{
	char			*expected = "FFFFFFFF";
	unsigned int	nbr = 0xFFFFFFFF;

	int		copied = call_two_args(parse_hex, UPPERCASE, nbr);
	cr_assert_stdout_eq_str(expected);
	cr_assert(eq(int, copied, ft_strlen(expected)));
}