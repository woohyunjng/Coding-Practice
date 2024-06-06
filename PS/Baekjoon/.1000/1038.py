from itertools import combinations

N = int(input())
arr = []

for i in range(1, 11):
    for j in combinations(range(10), i):
        arr.append(int("".join(map(str, sorted(j, reverse=True)))))

arr = list(sorted(arr))
if N >= 1023:
    print(-1)
else:
    print(arr[N])
