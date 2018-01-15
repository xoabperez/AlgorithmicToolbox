# Uses python3
# Finds the least common multiple of two numbers.
# For example, given 6 and 8, the LCM is 24. This is
# done by calculating the GCD of a and b, then taking
# a*b/GCD. 
def lcm(a, b):
    tempa = max(a,b)
    tempb = min(a,b)
    while tempb != 0:
        new_a = tempa%tempb
        tempa = tempb
        tempb = new_a

    lcm = (a*b/tempa)
    return lcm

a, b = [int(i) for i in input().split()]
print(lcm(a, b))


