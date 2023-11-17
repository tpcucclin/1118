# 1118

Problem O

```
flowchart TD;
 A[開始] -->B[/讀入 硬幣數量, 期望金額 /]
 B --> C[/讀入 硬幣種類/]
 C --> D[/建立 dp list 大小為期望金額+1,<br> dp#91;i#93; 代表達成金額的方法數, 且dp#91;0#93;=1 /]
 D --> E(for 針對每種硬幣面額 <br> for 金額 0 to 期望金額)
 E --> 結束
 F -->|條件為真| H(dp#91;金額#93; +=  dp#91;金額 - coin#93;)
 E --> F{金額 - count >=0}
 F -->  |條件為否| E
 H --> E
```

```
# Problem O 硬幣 v1.T
# group,value=map(int,input().split())
# coins=list(map(int,input().split()))
group,value=3,10
coins=[2,3,5]
dp=[1]+[0]*value
for coin in coins:
    for start in range(1,value+1)):
        if start>=coin:
            dp[start]+=dp[start-coin]
print(dp[-1])
```
