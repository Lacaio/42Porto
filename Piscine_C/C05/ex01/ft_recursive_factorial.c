/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:54:15 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:37:07 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb);

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>
int	main(void)
{
int test_cases[] = {0, 1, 2, 3, 4, 5, 10, -5};
int expected_results[] = {1, 1, 2, 6, 24, 120, 3628800, 0};
int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
int i;

i = 0;
while (i < num_tests)
{
int result = ft_recursive_factorial(test_cases[i]);
printf("Factorial of %d: %d (Expected: %d) -> %s\n",
       test_cases[i], result, expected_results[i],
       (result == expected_results[i]) ? "PASSED" : "FAILED");
i++;
}

return 0;
}
*/
