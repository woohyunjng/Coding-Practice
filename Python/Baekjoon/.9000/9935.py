from collections import deque

S = input()
bmb = input()

st = deque()
for i in S:
    st.append(i)
    if len(st) >= len(bmb):
        for j in range(len(st) - len(bmb), len(st)):
            if st[j] != bmb[j - len(st) + len(bmb)]:
                break
        else:
            for j in range(len(bmb)):
                st.pop()

print("".join(st) if len(st) else "FRULA")
