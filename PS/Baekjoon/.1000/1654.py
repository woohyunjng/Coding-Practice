K, N = map(int, input().split())
arr = []

for i in range(K):
    arr.append(int(input()))

st, ed = 1, max(arr)
md = (st + ed) // 2
res = md

while st <= ed:
    md = (st + ed) // 2
    x = 0
    for i in arr:
        x += i // md
    if x >= N:
        st = md + 1
        res = md
    elif x < N:
        ed = md - 1

print(res)
