from collections import deque
from math import gcd, ceil


def solution(edges, target):
    N = len(target)
    target = [0] + target
    arr = [[] for i in range(N + 1)]

    for i in edges:
        arr[i[0]].append(i[1])
        arr[i[1]].append(i[0])

    for i in range(1, N + 1):
        arr[i] = list(sorted(arr[i]))

    checked = [False for i in range(N + 1)]
    checked[1] = True
    dq = deque([1])

    child = [[] for i in range(N + 1)]
    rg = [(ceil(target[i] / 3), target[i]) for i in range(N + 1)]

    while len(dq):
        x = dq.popleft()
        for i in arr[x]:
            if checked[i]:
                continue
            checked[i] = True
            child[x].append(i)
            dq.append(i)

    leaf = list(filter(lambda x: not child[x], range(1, N + 1)))

    def dfs(x):
        if not child[x]:
            return [x]
        elif len(child) == 1:
            return dfs(child[x][0])
        else:
            cycle = 1
            child_dfs = []

            for i in child[x]:
                val = dfs(i)
                child_dfs.append(val)
                cycle = cycle * len(val) // gcd(cycle, len(val))

            res = []
            for i in range(cycle):
                for j in range(len(child[x])):
                    res.append(child_dfs[j][i % len(child_dfs[j])])
            return res

    res = dfs(1)
    cur = len(list(filter(lambda x: not target[x], leaf)))
    vst = [0 for i in range(N + 1)]

    k = 0
    while True:
        if cur == len(leaf):
            break

        j = res[k % len(res)]
        vst[j] += 1

        if vst[j] == rg[j][0]:
            cur += 1
        elif vst[j] == rg[j][1] + 1:
            return [-1]

        k += 1

    res_arr = [deque([]) for i in range(N + 1)]
    for i in leaf:
        while target[i] - 2 >= vst[i]:
            target[i] -= 3
            vst[i] -= 1
            res_arr[i].append(3)
        while target[i] - 1 >= vst[i]:
            target[i] -= 2
            vst[i] -= 1
            res_arr[i].appendleft(2)
        while vst[i]:
            vst[i] -= 1
            res_arr[i].appendleft(1)

    answer = []
    for i in range(k):
        j = res[i % len(res)]
        answer.append(res_arr[j].popleft())
    return answer
