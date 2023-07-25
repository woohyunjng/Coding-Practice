from collections import deque

S = input()
st = deque([])

for i in S:
    if i.isalpha():
        print(i, end="")
    elif i == "(":
        st.append("(")
    elif i == ")":
        while len(st) and st[-1] != "(":
            print(st.pop(), end="")
        st.pop()
    elif i in ["*", "/"]:
        while len(st) and st[-1] in ["*", "/"]:
            print(st.pop(), end="")
        st.append(i)
    elif i in ["+", "-"]:
        while len(st) and st[-1] != "(":
            print(st.pop(), end="")
        st.append(i)

while len(st):
    print(st.pop(), end="")
