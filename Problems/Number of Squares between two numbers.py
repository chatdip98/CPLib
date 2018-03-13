import sys
import math

t = int(input().strip())
for _ in range(t):
    x, y = tuple(map(int, input().strip().split(' ')))
    print(math.floor((math.sqrt(y))) - math.ceil((math.sqrt(x))) + 1)
