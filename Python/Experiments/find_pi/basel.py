import time

import math

start_time = time.time()

test_case = 10**8
val = 0

for i in range(1, test_case):
    val += 1 / i**2

end_time = time.time()

pi = (6 * val) ** 0.5

print(f"PI value : {pi} (error percentage {abs(math.pi - pi) / math.pi * 100}%)")
print(f"Executed {test_case} test cases in {end_time - start_time}s")
