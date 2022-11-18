/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:32:22 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/18 17:33:22 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// For printing %d and %i :

// 1) Every option except flag # should be taken into account.
// 2) Every number in the range of integer should be normally printed.
// 3) Blank(s) printed, when the width is bigger than the length of the string.
// 4) When the width is smaller than the strlen,
//	the width and the left justification will be ignored.
// 5) 0(s) printed, when the precision is bigger than the strlen.
// 6) + and - and ' ' signs should be printed before 0(s).
// 7) When smaller than the strlen, the precision will be ignored.
// 	7-1) When the precision is 0 and the argument is 0, nothing will be printed.
// 	7-2) When there is a dot, flag 0 will be ignored.
// 8) There should be one extra place outside of the prc buffer for signs.
// 9) But the signs take one place within the wdt buffer.
// 10) Zero fills up blank(s) of the wdt buffer, when no precision is given.
// 11) When there's -, 0 will be ignored. (No zerofill, left-justified)
// 12) When there's +, ' ' will be ignored.

// 1. left-justified
//	 		(sign)(prc-zero)(number)(blank)

// 2. right-justified && .precision
//			2-1. width > length (blank)(sign)(prc-zero)(number)
//			2-2. width < length (sign)(number)

// 3. right-justified && no .precision && width > length
// 			3-1. no zero-fill (blank)(sign)(number)
// 			3-2. zero-fill (sign)(wdt-zero)(number)

#include "../ft_printf.h"

static int	sequence_one(t_data options, int number, int num_len, int longer);
static int	sequence_two(t_data options, int number, int num_len, int longer);
static int	sequence_three(t_data options, int number, int longer);
static int	sequence_four(t_data options, int number, int longer);

int	print_di(int number, t_data options)
{
	int	count;
	int	digit_number;
	int	longer;

	count = 0;
	digit_number = digit_number_check(number);
	get_sign(number, &options);
	longer = get_longer(options.prc, digit_number) + options.sign;
	if (number == 0 && options.dot == 1 && options.prc == 0)
		longer = longer - 1;
	if (options.dash == 1)
		count += sequence_one(options, number, digit_number, longer);
	if (options.dash == 0 && options.dot == 1)
		count += sequence_two(options, number, digit_number, longer);
	if (options.dash == 0 && options.dot == 0)
	{
		if (options.zero == 1)
			count += sequence_three(options, number, longer);
		else
			count += sequence_four(options, number, longer);
	}
	return (count);
}

static int	sequence_one(t_data options, int number, int num_len, int longer)
{
	int	count;

	count = 0;
	count += sign_print(options, number);
	count += prc_print(options, num_len);
	if (!(number == 0 && options.dot == 1 && options.prc == 0))
		ft_putnbr(number, &count);
	count += wdt_print(options, longer, ' ');
	return (count);
}

static int	sequence_two(t_data options, int number, int num_len, int longer)
{
	int	count;

	count = 0;
	count += wdt_print(options, longer, ' ');
	count += sign_print(options, number);
	count += prc_print(options, num_len);
	if (!(number == 0 && options.dot == 1 && options.prc == 0))
		ft_putnbr(number, &count);
	return (count);
}

static int	sequence_three(t_data options, int number, int longer)
{
	int	count;

	count = 0;
	count += sign_print(options, number);
	count += wdt_print(options, longer, '0');
	ft_putnbr(number, &count);
	return (count);
}

static int	sequence_four(t_data options, int number, int longer)
{
	int	count;

	count = 0;
	count += wdt_print(options, longer, ' ');
	count += sign_print(options, number);
	ft_putnbr(number, &count);
	return (count);
}
