# Uses python3
# Finds largest two numbers in a list
# See max_pairwise_product.cc for more info
def MaxPPFast(x):
    n = len(x)
    max_index1 = -1;
    for i in range(n):
        if((max_index1 == -1) or (x[i] > x[max_index1])):
            max_index1 = i;
        i += 1
        
    max_index2 = -1;
    for j in range(n):
        if((j != max_index1) and ((max_index2 == -1) or (x[j] > x[max_index2]))):
            max_index2 = j;
        j += 1
    return x[max_index1]*x[max_index2]

n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)

result = MaxPPFast(a)
print(result)
