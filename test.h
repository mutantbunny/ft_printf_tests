/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:24:45 by gmachado          #+#    #+#             */
/*   Updated: 2022/05/18 01:52:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../ft_printf.h"
# include <criterion/criterion.h>
# include <criterion/new/assert.h>
# include <criterion/redirect.h>

void	redirect_all_stdout(void);
int		call_one_arg(int (*f)(va_list vl), ...);
int		call_two_args(int (*f)(va_list vl, unsigned int fl), unsigned int flags, ...);
int		call_two_args_str(int (*f)(const char *str, va_list args), const char *str, ...);

#endif