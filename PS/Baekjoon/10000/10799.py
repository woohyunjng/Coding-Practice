from collections import deque

S = input()
st = deque([])

res = 0

for i in range(len(S)):
    if S[i] == "(":
        st.append(i)
    else:
        p = st.pop()
        if p == i - 1:
            res += len(st)
        else:
            res += 1

print(res)
