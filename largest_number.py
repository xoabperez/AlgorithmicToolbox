#Uses python3
import random

def checkgreater(x,maxd):
    big = max(x,maxd)
    lil = min(x,maxd)
    bstr = str(big)
    lstr = str(lil)
    blen = len(bstr)
    llen = len(lstr)
    llast = lil%10
    for i in range(llen):
        if int(bstr[i]) > int(lstr[i]):
            return big
        elif int(bstr[i]) < int(lstr[i]):
            return lil
        else:
            continue
    for i in range(llen,blen):
        if int(bstr[i]) <= llast:
            return lil
    return big
    
    
def largest_number(a):
    res = ""
    while a != []:
        maxd = 0
        for x in a:
            maxd = checkgreater(x,maxd)
            print(maxd)
        res += str(maxd)
        a.remove(maxd)
    
    return res

# data = list(map(int, input().split()))
n = 10; 
data = random.sample(range(1,100),n)
print(largest_number(data))
    
