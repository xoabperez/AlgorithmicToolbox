# Uses python3
# Find the last digit of a sum of the first n Fibonacci
# numbers. Playing around with small values of n shows that
# the nth sum is equal to F(n+2)-1, and we previously solved how
# to calculate the last digit of F(m) 

def fibonacci_sum(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n+1):
        previous, current = current, (previous + current)%10

    return (current-1)

n = int(input())
print(fibonacci_sum(n))
