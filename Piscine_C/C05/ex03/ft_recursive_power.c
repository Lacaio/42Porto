/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:28:44 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:38:08 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdio.h>
int main(void)
{
    // Test cases: {base, power, expected_result}
    int test_cases[][3] = {
        {2, 3, 8},      // 2^3 = 8
        {5, 2, 25},     // 5^2 = 25
        {10, 0, 1},     // 10^0 = 1
        {4, 1, 4},      // 4^1 = 4
        {-3, 3, -27},   // (-3)^3 = -27
        {0, 5, 0},      // 0^5 = 0
        {7, -2, 0},     // Negative power should return 0
        {-2, 4, 16}     // (-2)^4 = 16
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int i;

    i = 0;
    while (i < num_tests)
    {
        int base = test_cases[i][0];
        int power = test_cases[i][1];
        int expected = test_cases[i][2];
        int result = ft_recursive_power(base, power);

        printf("Testing %d^%d:\n", base, power);
        printf("  Expected: %d\n", expected);
        printf("  Result:   %d\n", result);

        if (result == expected)
            printf("  -> PASSED ✅\n\n");
        else
            printf("  -> FAILED ❌\n\n");
        i++;
    }

    return (0);
}
*/
