#!/usr/bin/python3

def makeChange(coins, total):
    """
    Function for making change
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    memo = {0: 0}

    for i in range(1, total + 1):
        memo[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            memo[i] = min(memo[current] + 1, memo[i])

    if memo[total] == total + 1:
        return -1

    return memo[total]
    