n, q = map(int, input().split())
list1 = list(range(n+1))  # 0 start
list2 = [0 for i in range(n+1)]  # 1 start
# print(list1)
# ans = int(1+n)*n//2
ans = 0
for i in range(q):
    a, b = map(int, input().split())
    a, b = min(a, b), max(a, b)
    cnt1 = 0
    cnt2 = 0
    list1[a], list1[b] = list1[b], list1[a]
    temp = list2[a]
    for j in range(a+1, b+1):
        if list1[a] > list1[j]:
            cnt1 += 1

        if j == b:
            continue
        if list1[j] > list1[b] and list1[j] > list1[a]:
            pass
        elif list1[j] < list1[b] and list1[j] < list1[a]:
            pass
        elif list1[j] > list1[b] and list1[j] < list1[a]:
            list2[j] += 1
            ans += 1
        elif list1[j] < list1[b] and list1[j] > list1[a]:
            list2[j] -= 1
            ans -= 1

        if list1[j] < list1[b]:
            cnt2 += 1

    list2[a] = list2[b] + cnt1  # first
    ans += cnt1
    if list1[a] < list1[b]:
        cnt2 += 1
    list2[b] = temp - cnt2
    ans -= cnt2
    # print(temp, cnt2)

    # print(list2[1:])
    print(ans)
    # print()
