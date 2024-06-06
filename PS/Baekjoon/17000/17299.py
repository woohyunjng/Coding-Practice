from collections import deque, defaultdict

N = int(input())
arr = list(reversed(list(map(int, input().split()))))

counter = defaultdict(int)
for i in arr:
    counter[i] += 1

for i in range(N):
    arr[i] = [arr[i], counter[arr[i]]]

stack = deque([])
res = []

for i in arr:
    while len(stack):
        if stack[-1][1] <= i[1]:
            stack.pop()
        else:
            break

    if len(stack):
        res.append(stack[-1][0])
    else:
        res.append(-1)
    stack.append(i)

print(" ".join(reversed(list(map(str, res)))))
