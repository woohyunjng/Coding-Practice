S = input()
ln = len(S.split(":")) - 1

if S.startswith(":") or S.endswith(":"):
    ln -= 1

if ln < 8:
    S = S.replace("::", ":".join([""] + ["0000" for i in range(8 - ln)] + [""]))
    if S.startswith(":"):
        S = S[1:]
    if S.endswith(":"):
        S = S[:-1]

arr = S.split(":")
res = []

for i in arr:
    res.append(i.zfill(4))

print(":".join(res))
