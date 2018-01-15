# Uses python3
# Find the last digit of a partial sum of Fibonacci numbers,
# F(m)+F(m+1)+...+F(n). We can find the last digit of the sum to
# F(n) and carefully subtract the last digit of the sum to F(m-1)
def fibonacci_partial_sum(from_, to):
    if to <= 1:
        return to
        
    previous = 0
    current  = 1

    for i in range(from_):
        previous, current = current, (current + previous)%10
    first = current
    for i in range((to-from_+1)):
        previous, current = current, (current+previous)%10

    return (current-first)%10


a,b = [int(i) for i in input().split()]
print(fibonacci_partial_sum(a,b))