# Uses python3
# Find the greatest common denominator using Euclid's Algorithm
def gcd(a, b):
    tempa = max(a,b) #Take the larger of the two
    tempb = min(a,b) #And smaller
    while tempb != 0: 
        a = tempa%tempb #Find remainder
        tempa = tempb #Make tempb the larger number
        tempb = a #Make the remainder the smaller number
    return tempa

a, b = [int(i) for i in input().split()] #Take two numbers
print(gcd(a, b))
