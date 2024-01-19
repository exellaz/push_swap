/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:36:53 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/01/18 15:43:50 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_hex_len(unsigned int n);
int		ft_uint_len(unsigned int n);
int		ft_ptr_len(unsigned long n);
int		ft_print_char(int c);
int		ft_print_str(char *str);
void	ft_print_adr(unsigned long n);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_hex(unsigned int n, const char format);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_format(va_list args, const char format);
int		ft_printf(const char *str, ...);

#endif
