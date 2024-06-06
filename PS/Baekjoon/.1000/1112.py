x, b = map(int, input().split())
res = ""

if x < 0 and b > 0:
    new_x = -x
else:
    new_x = x

while new_x:
    md = abs(new_x % abs(b))
    res += str(md)
    new_x = (new_x - md) // b

res = "".join(reversed(res))
if x < 0 and b > 0:
    res = f"-{res}"

print(res if res else "0")
