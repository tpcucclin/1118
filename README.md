# 1118

## Problem O 硬幣 

```mermaid
flowchart TD;
 A[開始] -->B[/讀入 硬幣數量, 期望金額 /]
 B --> C[/讀入 硬幣種類/]
 C --> D[/"建立 dp list 大小為期望金額+1,<br> dp[i] 代表達成金額的方法數, 且dp[0]=1"/]
 D --> E("for 針對每種硬幣面額 <br> for 金額 從 1 到 期望金額")
 E --> 結束
 F --> |條件為真| H("dp[金額] +=  dp[金額 - coin]")
 E --> F{金額 - count >=0}
 F -->  |條件為否| E
 H --> E
```

```
flowchart TD;
 A[開始] -->B[/讀入 硬幣數量, 期望金額 /]
 B --> C[/讀入 硬幣種類/]
 C --> D[/"建立 dp list 大小為期望金額+1,<br> dp[i] 代表達成金額的方法數, 且dp[0]=1"/]
 D --> E("for 針對每種硬幣面額 <br> for 金額 從 1 到 期望金額")
 E --> 結束
 F --> |條件為真| H("dp[金額] +=  dp[金額 - coin]")
 E --> F{金額 - count >=0}
 F -->  |條件為否| E
 H --> E
```

```
# Problem O 硬幣 v1.T
# n,amount=map(int,input().split())
# coins=list(map(int,input().split()))
n,amount=3,9  # 硬幣數量,期望金額
coins=[2,3,5]
dp=[1]+[0]*amount # 建立0到期望金額的列表 代表金額達到的組合數
for coin in coins: # 取出 每個硬幣
    for m in range(1,amount+1): #
        if m>=coin:
            dp[m]+=dp[m-coin] # 達到金額的次數

print(dp[-1]) # 達到期望金額的組合數

#Input
#3 9
#2 3 5
#Output
#3

#Input
#3 10
#2 3 5
#Output
#4

```

## Problem N 進步獎

```
# Problem N 進步獎 v1.a
# 今年資訊月第5題剛好是一樣的題目
n=int(input())
s=list(map(int,input().split()))
dp=[1]*n
for i in range(1,n):
    for j in range(i):
        if s[i]>s[j]:
            dp[i]=max(dp[i],dp[j]+1) # 這裡的 dp[i] 代表的是以 i 為結尾的最長遞增子序列
print(max(dp))

#Input
#11
#20 40 32 67 40 20 89 300 404 13 13
#Output
#6

```
