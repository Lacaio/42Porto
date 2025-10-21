/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprado-l <lprado-l@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:11:19 by lprado-l          #+#    #+#             */
/*   Updated: 2025/09/17 18:41:26 by lprado-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
    // Test cases: {input, expected_result}
    int test_cases[][2] = {
        {4, 2},
        {9, 3},
        {16, 4},
        {1, 1},
        {0, 0},
        {2, 0},   // Not a perfect square
        {8, 0},   // Not a perfect square
        {25, 5},
        {100, 10},
        {144, 12},
        {-5, 0}    // Negative number
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int i;

    printf("Testing ft_sqrt function:\n\n");
    i = 0;
    while (i < num_tests)
    {
        int result = ft_sqrt(test_cases[i][0]);
        printf("Input: %3d | Expected: %2d | Result: %2d | Status: %s\n",
               test_cases[i][0], test_cases[i][1], result,
               (result == test_cases[i][1]) ? "PASSED ✅" : "FAILED ❌");
        i++;
    }

    return (0);
}
*/
