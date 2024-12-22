n = 1571
mod = 16777216
ans = 0
for x in range(n):
    secret = int(input())
    
    for i in range(2000):
        temp = secret * 64
        temp = secret ^ temp
        temp = temp % mod
        secret = temp
        
        temp = temp // 32
        temp = secret ^ temp
        temp = temp % mod
        secret = temp
        
        temp = temp * 2048
        temp = secret ^ temp
        temp = temp % mod
        secret = temp
        
    ans += secret
    
print(ans)
