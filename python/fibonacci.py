# Uses python3
from timeit import default_timer as timer

#Find the nth number in the Fibonacci sequence. Only
#the fast algorithm was coded here.
start = timer()
def calc_fib(n):
    #Create a vector of Fibonacci numbers
    nums = [0]
    if n>0:
        nums.append(1)
    if n>1:
        for i in range(2,n+1):
            nums.append(nums[i-1]+nums[i-2])
    return nums[n]
end = timer()

n = int(input())
print(calc_fib(n))
print("Time taken: ",end-start)

