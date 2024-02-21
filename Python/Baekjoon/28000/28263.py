from itertools import combinations

A = 1  # Any numbers
primes = []  # {p - 1 | A이고 p ∤ A인 소수 p}

for i in combinations(primes, 11):
    n = 1
    for j in i:
        n = n * j % A
    n %= A
    if n == 1:
        print(*i, sep=" ")
        break
