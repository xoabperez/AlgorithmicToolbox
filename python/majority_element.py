# Uses python3
import sys

def get_majority_element(a, left, right):
    # if left == right:
        # return -1
    # if left + 1 == right:
        # return a[left]
    amts = {}
    for i in range(right):
        amts[a[i]] = amts.get(a[i],0)+1
    for i in range(right):
        if amts[a[i]] > (right//2):
            return a[i]
    return -1


n, *a = list(map(int, input().split()))
if get_majority_element(a, 0, n) != -1:
    print(1)
else:
    print(0)
