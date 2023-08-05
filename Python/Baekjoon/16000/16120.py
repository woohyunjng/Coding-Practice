from collections import deque

S = input()
st = deque([])

for i in S:
    st.append(i)
    while len(st) >= 4:
        ppap = ["P", "A", "P", "P"]
        for j in range(4, 0, -1):
            if ppap[j - 1] != st[len(st) - j]:
                break
        else:
            for j in range(4):
                st.pop()
            st.append("P")
            continue
        break

if len(st) == 1 and st[0] == "P":
    print("PPAP")
else:
    print("NP")
