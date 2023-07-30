N = int(input())
a, b, c = 0, 0, 0
d, e, f = 0, 0, 0

for i in range(N):
    arr = list(map(int, input().split()))
    if not i:
        a, b, c = arr
        d, e, f = arr
        continue

    a, b, c = max(a, b) + arr[0], max(a, b, c) + arr[1], max(b, c) + arr[2]
    d, e, f = min(d, e) + arr[0], min(d, e, f) + arr[1], min(e, f) + arr[2]

print(max(a, b, c), min(d, e, f))
