/*
Problem: Reverse Integer
- Link: https://leetcode.com/problems/reverse-integer/

Approach:
- Iteratively extract digits using modulo (%) and rebuild the number in reverse order
- Multiply the current result by 10 and add the next digit
- Use a larger data type (long) to detect overflow before returning
- If the reversed value exceeds 32-bit signed integer bounds, return 0

Time Complexity: O(n)
- n = number of digits in the integer (log10(x))

Space Complexity: O(1)
- Constant extra space used

Key Concepts:
- Number manipulation
- Digit extraction and reconstruction using modulo and division
- Overflow detection and boundary checking
- Handling signed integers

Edge Cases Considered:
- Negative numbers (sign preserved automatically through math)
- Input = 0
- Overflow beyond 32-bit signed integer range
- Trailing zeros (e.g., 120 → 21)

Real-World Relevance:
- Common in low-level systems where numeric data is processed digit-by-digit
- Relevant in:
     - Data serialization/deserialization
     - Embedded systems with constrained integer sizes
     - Parsing numeric streams or reversing encoded values
*/

class Solution
{
public:
    int reverse(int x)
    {
        long res = 0, check = 0;
        int iter = 0, place = 0;

        while (x != 0)
        {
            printf("i = %d\n", iter);
            res = (x % 10) + (res * 10);
            printf("r = %d\n", res);

            x = x / 10;
            printf("x = %d\n\n", x);
            iter++;
        }

        if (res >= (pow(2, 31) - 1) || res <= pow(-2, 31))
        {
            return 0;
        }

        return res;
    }
};
