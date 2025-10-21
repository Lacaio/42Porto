/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:05:03 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:46:43 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index);

int	ft_fibonacci(int index)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index < 0)
		return (-1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>
int main(void)
{
    int test_cases[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, -1};
    int expected_results[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 610, -1};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int i;

    printf("Testing ft_fibonacci function:\n\n");
    i = 0;
    while (i < num_tests)
    {
        int result = ft_fibonacci(test_cases[i]);
        printf("Index: %2d | Expected: %4d | Result: %4d | Status: %s\n",
               test_cases[i], expected_results[i], result,
               (result == expected_results[i]) ? "PASSED ✅" : "FAILED ❌");
        i++;
    }

    return (0);
}
*/
