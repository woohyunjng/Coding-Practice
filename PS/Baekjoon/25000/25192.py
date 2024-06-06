N = int(input())
res = 0
arr = set([])

for i in range(N):
    a = input()
    if a == "ENTER":
        res += len(arr)
        arr = set([])
    else:
        arr.add(a)

res += len(arr)
print(res)
