#Uses python3


def max_dot_product(a, b):
    #write your code here
    res = 0
    sorta = sorted(a)
    sortb = sorted(b)
    for i in range(len(a)):
        res += sorta[i] * sortb[i]
    return res


data = list(map(int, input().split()))
n = data[0]
a = data[1:(n + 1)]
b = data[(n + 1):]
print(max_dot_product(a, b))

    
