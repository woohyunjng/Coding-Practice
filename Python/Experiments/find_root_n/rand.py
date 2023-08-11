import random


def find_root(n, test_case=10**8):
    under_one = 1
    if n > 1:
        under_one = n
        n = 1 / n

    success = 0
    for _ in range(test_case):
        p = random.random()
        if p**2 <= n:
            success += 1

    return under_one * (success / test_case)
