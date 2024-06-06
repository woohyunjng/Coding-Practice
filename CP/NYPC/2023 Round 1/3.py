# 100 / 100

N = int(input())
arr = set([])

for i in range(N):
    arr.add(input())

K = int(input())
al_arr = []

for i in range(K):
    arr = arr - set([input()])

arr = sorted(arr)
print(len(arr))
for i in arr:
    print(i)
