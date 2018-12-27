# Uses python3
import sys

def optimal_summands(n):
    summands = []
    index = 1
    while(True):
        if n <= (2*index):
            summands.append(n)
            break
        else:
            summands.append(index)
            n -= index
            index += 1
    #write your code here
    return summands


n = int(input())
summands = optimal_summands(n)
print(len(summands))
for x in summands:
    print(x, end=' ')
