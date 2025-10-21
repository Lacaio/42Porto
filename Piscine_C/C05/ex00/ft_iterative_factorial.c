/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:12:45 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/15 18:53:28 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	res = 1;
	i = 2;
	if (nb == 0 || nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	while (i <= nb)
	{
		res = res * i;
		i++;
	}
	return (res);
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
int result = ft_iterative_factorial(test_cases[i]);
printf("Factorial of %d: %d (Expected: %d) -> %s\n",
       test_cases[i], result, expected_results[i],
       (result == expected_results[i]) ? "PASSED" : "FAILED");
i++;
}

return 0;
}
*/
