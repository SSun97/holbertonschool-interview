#include "palindrome.h"

/**
 * is_palindrome - checks if a passed number
 * is a palindrome
 * @n: input number
 * Return: 0 if not a palindrome | 1 if it is.
 */
int is_palindrome(unsigned long n)
{
    unsigned long rev_n = 0, temp_n = n, last_digit;

    while (temp_n)
    {
        last_digit = temp_n % 10;
        rev_n = (rev_n * 10) + last_digit;
        temp_n = temp_n / 10;
    }

    return (rev_n == n);
}
