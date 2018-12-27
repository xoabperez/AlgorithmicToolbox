# Uses python3
#from collections import namedtuple
from operator import attrgetter
import random

#Segment = namedtuple('Segment', 'start end')

def optimal_points(starts,ends):
    points = []
    endind = 0
    startind = 0
    e = sorted(list(set(ends)))
    s = sorted(list(set(starts)))
    leftestright = e[0]
    points.append(leftestright)
    for a in s:
        if s[startind] <= leftestright:
            startind += 1
        else:
            endind += 1
            leftestright = e[endind]
            points.append(leftestright)
        if startind > len(s):
            break
    return points


# n, *data = map(int, input().split())
# starts = list(data[::2])
# ends = list(data[1::2])
#segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))

n = 100
segments = []
starts = []
ends = []
for i in range(100):
    x = random.sample(range(10**9),1)
    y = random.sample(range(x[0],10**9),1)
    starts.append(x[0])
    ends.append(y[0])
    
    
points = optimal_points(starts,ends)
print(len(points))
for p in points:
    print(p, end=' ')
