from collections import deque

S = input()
arr = []
st = deque([])

for i in range(len(S)):
    if S[i] == "(":
        st.append(i)
    elif S[i] == ")":
        arr.append((st.pop(), i))


def get_all(N):
    if N >= len(arr):
        return [[False for i in range(len(S))]]

    res = []
    new_arr = get_all(N + 1)
    for i in new_arr:
        a, b = i.copy(), i.copy()
        a[arr[N][0]] = True
        a[arr[N][1]] = True

        res.append(a)
        res.append(b)

    return res


ans = set()
for i in get_all(0):
    res = ""
    for j in range(len(S)):
        if i[j]:
            continue
        else:
            res += S[j]
    ans.add(res)

for i in sorted(list(ans)):
    if i == S:
        continue
    print(i)
