# Uses python3
# Find the last digit of the nth fibonacci number.
# This is done without using large amounts of memory 
# by simply keeping track of the last digit.
def get_fibonacci_last_digit(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    #Add the fibonacci numbers and keep the last digit
    for i in range(n - 1):
        previous, current = current, (previous + current)%10

    return current 

n = int(input())
print(get_fibonacci_last_digit(n))
