def round(n):
    if n - int(n) >= 0.5:
        return int(n) + 1
    else:
        return int(n)


n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

arr = list(sorted(arr))[round(n * 3 / 20) : n - round(n * 3 / 20)]

if n:
    print(round(sum(arr) / (n - round(n * 3 / 20) * 2)))
else:
    print(0)
