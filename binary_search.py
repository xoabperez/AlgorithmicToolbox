# Uses python3
# Implement the binary search algorithm that allows searching
# sorted lists. 
#
# Input: an integer n followed by sequence of n sorted numbers
#   The following line contains an integer k and k integers to 
#   be searched for
# Output: A sequence with the index of the kth integer in the list,
#   if found, and -1 otherwise

#Bsearch takes the sequence to be searched in, the value x to be 
#searched for, and the left and right ends. Depending on the size of 
#x compared to the central value of the list, the search continues in the
#left or right half of the list.
def bsearch(a,x,l,r):
    if (r-l) == 1:
        return -1
    mid = (l+r)//2
    if x == a[mid]:
        return mid
    elif x < a[mid]:
        return bsearch(a,x,l,mid)
    else:
        return bsearch(a,x,mid,r)

#Binary search looks for the value x in the first and last 
#positions of x, and then submits to bsearch if not found       
def binary_search(a, x):
    right = len(a)
    if x == a[0]:
        return 0
    if x == a[-1]:
        return (len(a)-1)
    return bsearch(a,x,0,right-1)

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

data = list(map(int, input().split()))
n = data[0]
m = data[n + 1]
a = data[1 : n + 1]
for x in data[n + 2:]:
    print(binary_search(a, x), end = ' ')    
