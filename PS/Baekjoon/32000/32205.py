N = int(input())
checked = [False for i in range(1000001)]
res = False

for i in range(N):
    A, B, C = map(int, input().split())
    res = res or checked[A] or checked[B] or checked[C]
    checked[A], checked[B], checked[C] = True, True, True
print(1 if res else 0)
