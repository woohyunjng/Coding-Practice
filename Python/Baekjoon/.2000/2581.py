M = int(input())
N = int(input())
primes, checked = [], [True for i in range(N + 1)]

for i in range(2, int(N**0.5) + 1):
    if not checked[i]:
        continue

    for j in range(i * 2, N + 1, i):
        checked[j] = False

sm, mn = 0, 1e9
for i in range(max(M, 2), N + 1):
    if not checked[i]:
        continue
    mn = min(mn, i)
    sm += i

if not sm:
    print(-1)
else:
    print(sm)
    print(mn)
