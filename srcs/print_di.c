/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:32:22 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/15 19:32:18 by eunskim          ###   ########.fr       */
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
//	 		(blank)(sign)(prc-zero)(number)

// 3. right-justified && no .precision && width > length
// 			3-1. no zero-fill (blank)(sign)(number)
// 			3-2. zero-fill (sign)(wdt-zero)(number)

// 4. right-justified && no .precision && width < length
// 			(sign)(number)

#include "../ft_printf.h"

static	void	sequence_one(t_data options, int number, int *count);
static	void	sequence_two(t_data options, int number, int *count);
static	void	sequence_three(t_data options, int number, int *count);
static	void	sequence_four(t_data options, int number, int *count);

int	print_di(int number, t_data options)
{
	int	count;

	count = 0;
	if (options.dash == 1)
		sequence_one(options, number, count);
	if (options.dash == 0 && options.dot == 1)
		sequence_two(options, number, count);
	if (options.dash == 0 && options.dot == 0)
	{
		if (options.zero == 1)
			sequence_three(options, number, count);
		else
			sequence_four(options, number, count);
	}
	return (count);
}

static	void	sequence_one(t_data options, int number, int *count)
{
	*count += sign_print(options, number);
	*count += prc_print(options, number);
	*count += wdt_print(options, number, ' ');
}

static	void	sequence_two(t_data options, int number, int *count)
{
	*count += wdt_print(options, number, ' ');
	*count += sign_print(options, number);
	*count += prc_print(options, number);
}

static	void	sequence_three(t_data options, int number, int *count)
{
	*count += sign_print(options, number);
	*count += wdt_print(options, number, '0');
	*count += ft_putnbr(number);
}

static	void	sequence_four(t_data options, int number, int *count)
{
	*count += wdt_print(options, number, ' ');
	*count += sign_print(options, number);
	*count += ft_putnbr(number);
}
