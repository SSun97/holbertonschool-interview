#!/usr/bin/python3
""" calculates the fewest number of operations needed to
result in exactly n H characters in the file. """


def minOperations(n):
    number = 0
    div = 2

    while n > 1:
        if n % div == 0:
            n = n / div
            number = number + div
        else:
            div += 1
    return number