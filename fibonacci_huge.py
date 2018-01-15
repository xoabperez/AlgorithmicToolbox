# Uses python3
# Compute F(n) modulo m, where F(n) is the nth number
# of the Fibonacci sequence, and n may be very large.

# Solution: note that F(i)mod(m) for varying i and fixed m
# produces a periodic sequence that begins with 0 1 ...
# So once the length of this period is found, F(n)mod(m)
# is not far off

def get_fibonacci_huge(n, m):
    if n <= 1:
        return n
    #First step is to find the length of the Pisano period
    previous = 0
    current  = 1
    index = 0
    while True:
        previous,current = current,(previous+current)%m
        index += 1
        if((previous%m == 0) and (current%m ==1)):
            break
    #Now instead of F(n)mod(m) we can take F(n%period)mod(m).
    #The values for F(i)mod(m) could have been stored for quicker
    #access
    index = n%index
    for _ in range(index-1):
        previous, current = current, (previous + current)%m

    return current

a, b = [int(i) for i in input().split()]
print(get_fibonacci_huge(a,b))
