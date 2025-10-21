/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:37:58 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:48:19 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_is_prime(int nb)
{
	long int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
    // Test cases: {input, expected_result}
    int test_cases[][2] = {
        {-5, 0},
        {0, 0},
        {1, 0},
        {2, 1},
        {3, 1},
        {4, 0},
        {5, 1},
        {7, 1},
        {9, 0},
        {11, 1},
        {13, 1},
        {16, 0},
        {25, 0},
        {29, 1},
        {47, 1},
        {101, 1},
        {100, 0},
        {99, 0},
        {2147483647, 1} // Largest possible prime in a signed int
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int i = 0;

    printf("Testing ft_is_prime function:\n\n");
    while (i < num_tests)
    {
        int result = ft_is_prime(test_cases[i][0]);
        printf("Input: %11d | Expected: %d | Result: %d | Status: %s\n",
               test_cases[i][0], test_cases[i][1], result,
               (result == test_cases[i][1]) ? "PASSED ✅" : "FAILED ❌");
        i++;
    }

    return (0);
}
*/
