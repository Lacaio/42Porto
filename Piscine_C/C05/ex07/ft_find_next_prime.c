/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:55:40 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:49:57 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

int	find_prime(int n);

int	find_prime(int n)
{
	long int	i;

	i = 2;
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (find_prime(nb))
			return (nb);
		nb++;
	}
}
/*
#include <stdio.h>
int main(void)
{
    // Test cases: {input, expected_result}
    int test_cases[][2] = {
        {0, 2},
        {1, 2},
        {2, 2},
        {3, 3},
        {4, 5},
        {7, 7},
        {8, 11},
        {10, 11},
        {13, 13},
        {20, 23},
        {100, 101},
        {-5, 2}
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int i = 0;

    printf("Testing ft_find_next_prime function:\n\n");
    while (i < num_tests)
    {
        int result = ft_find_next_prime(test_cases[i][0]);
        printf("Input: %3d | Expected: %3d | Result: %3d | Status: %s\n",
               test_cases[i][0], test_cases[i][1], result,
               (result == test_cases[i][1]) ? "PASSED ✅" : "FAILED ❌");
        i++;
    }

    return 0;
}
*/
