from sys import stdin

N = int(stdin.readline())
arr = list(map(int, stdin.readline().rstrip().split()))

if N <= 2:
    print(N)
    exit()

current = 1
used = [0 for i in range(10)]
used[arr[0]] += 1

mx = 0
i, j = 0, 1

while j < N:
    if not used[arr[j]]:
        current += 1
    used[arr[j]] += 1

    while current > 2:
        used[arr[i]] -= 1
        if not used[arr[i]]:
            current -= 1
        i += 1
    mx = max(mx, j - i + 1)
    j += 1

print(mx)
