/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:32:22 by eunskim           #+#    #+#             */
/*   Updated: 2022/11/14 20:07:18 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

For printing %d and %i :

1) Every option except flag # should be taken into account.
2) Every number in the range of integer (including 0) should be normally printed.
3) Blank(s) printed, when the width is bigger than the length of the string.
4) When the width is smaller than the strlen, the width and the left justification will be ignored.
5) 0(s) printed, when the precision is bigger than the length of the string.
6) + and - signs, ' ' as an invisible sign for positive numbers should be printed before 0(s).
7) When the precision is smaller than the strlen, the precision will be ignored.
	7-1) When the precision is 0 and the argument is 0, nothing will be printed.
	7-2) When there is a dot, flag 0 will be ignored.
8) For precision, there should be one extra place outside of the prc buffer for signs (' ', +, -).
9) For width, the signs (' ', +, -) take one place within the wdt buffer.
10) Zero padding fills up blank(s) of the wdt buffer for each case, when precision is not given.
11) When 0 and - come together, 0 will be ignored. (No zerofill, left-justified)
12) When + and ' ' come together, ' ' will be ignored. (+ will be printed for positive numbers.)

int	print_di(int number, t_data *options)
{
	int	count;
	int digit_number;

	count = 0;
	digit_number = digit_number_check(number);

1. left-justified

	(sign)(prc-zero)(number)(blank)

	if (options->dash == 1)
	{
		count += print_sign(number, &options);
		if (count > 0)
			options->sign = 1;
		if (options->prc > digit_number)
		{
			count += ft_putnchar('0', options->prc - digit_number);
			digit_number = option->prc;
		}
		count += ft_putnbr(number);
		if (options->wdt > digit_number + option->sign)
			count += ft_putnchar(' ', options->wdt - digit_number - option->sign);
	}

2. right-justified && .precision && width > precision

	(blank)(sign)(prc-zero)(number)

3. right-justified && no .precision && width > length

	3-1. no zero-fill (blank)(sign)(number)
	3-2. zero-fill (sign)(wdt-zero)(number)

4. right-justified && .precision && width < precision
	
	(sign)(prc-zero)(number)

5. right-justified && no .precision && width < length
	
	(sign)(number)
}

int	digit_number_check(int n)
{
	int	digit_number;

	digit_number = 0;
	if (n <= 0)
		digit_number = 1;
	while (n)
	{
		n = n / 10;
		digit_number++;
	}
	return (digit_number);
}

int	print_sign(int number, t_data *options)
{
	int	count;

	count = 0;
	
	if (number >= 0 && options->plus == 1)
	{
		count += ft_putchar('+');
		return (count);
	}
	else if (number >= 0 && options->space == 1)
		count += ft_putchar(' ');
	else if (number < 0)
		count += ft_putchar('-');
	return (count);
}