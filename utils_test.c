/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:24:39 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/17 20:52:43 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void redirect_all_stdout(void)
{
	cr_redirect_stdout();
}

Test(get_hex_digit, zero_upper)
{
	char result = get_hex_digit(0, UPPERCASE);
	cr_assert(eq(chr, result, '0'));
}

Test(get_hex_digit, zero_lower)
{
	char result = get_hex_digit(0, UPPERCASE);
	cr_assert(eq(chr, result, '0'));
}

Test(get_hex_digit, f_upper)
{
	char result = get_hex_digit(15, UPPERCASE);
	cr_assert(eq(chr, result, 'F'));
}

Test(get_hex_digit, f_lower)
{
	char result = get_hex_digit(15, LOWERCASE);
	cr_assert(eq(chr, result, 'f'));
}

Test(putnbr_hex_ptr, zero, .init=redirect_all_stdout)
{
	putnbr_hex_ptr(0ULL);
	cr_assert_stdout_eq_str("0x0");
}

Test(putnbr_hex_ptr, one, .init=redirect_all_stdout)
{
	putnbr_hex_ptr(1ULL);
	cr_assert_stdout_eq_str("0x1");
}

Test(putnbr_hex_ptr, max_val, .init=redirect_all_stdout)
{
	putnbr_hex_ptr(0xffffffffffffffffULL);
	cr_assert_stdout_eq_str("0xffffffffffffffff");
}

Test(putnbr_hex_uint, zero_lower, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0x0U, LOWERCASE);
	cr_assert_stdout_eq_str("0");
}

Test(putnbr_hex_uint, zero_upper, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0x0U, UPPERCASE);
	cr_assert_stdout_eq_str("0");
}

Test(putnbr_hex_uint, one_lower, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0x1U, LOWERCASE);
	cr_assert_stdout_eq_str("1");
}

Test(putnbr_hex_uint, one_upper, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0x1U, UPPERCASE);
	cr_assert_stdout_eq_str("1");
}

Test(putnbr_hex_uint, max_val_lower, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0xffffffffU, LOWERCASE);
	cr_assert_stdout_eq_str("ffffffff");
}

Test(putnbr_hex_uint, max_val_upper, .init=redirect_all_stdout)
{
	putnbr_hex_uint(0xffffffffU, UPPERCASE);
	cr_assert_stdout_eq_str("FFFFFFFF");
}

Test(putnbr_dec_uint, zero, .init=redirect_all_stdout)
{
	putnbr_dec_uint(0);
	cr_assert_stdout_eq_str("0");
}

Test(putnbr_dec_uint, one, .init=redirect_all_stdout)
{
	putnbr_dec_uint(1);
	cr_assert_stdout_eq_str("1");
}

Test(putnbr_dec_uint, max_val, .init=redirect_all_stdout)
{
	putnbr_dec_uint(0xffffffffU);
	cr_assert_stdout_eq_str("4294967295");
}
