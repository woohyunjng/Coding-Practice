from math import ceil

mn, mx = map(int, input().split())
prime = [True for i in range(int(mx**0.5) + 1)]
prime[0] = prime[1] = False

for i in range(2, int(mx**0.25) + 1):
    if not prime[i]:
        continue
    for j in range(i * 2, int(mx**0.5) + 1, i):
        prime[j] = False

primes = []
checked = [False for i in range(mx - mn + 1)]
res = mx - mn + 1

for i in range(2, int(mx**0.5) + 1):
    if not prime[i]:
        continue
    for j in range(i**2 * ceil(mn / (i**2)), mx + 1, i**2):
        if checked[j - mn]:
            continue
        checked[j - mn] = True
        res -= 1

print(res)
