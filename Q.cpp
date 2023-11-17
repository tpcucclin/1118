#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> list1(n + 1);
    vector<int> list2(n + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        list1[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int s = a+b;
        a = min(a, b);
        b = s-a;
        
        int cnt1 = 0;
        int cnt2 = 0;
        int t= list1[a]+list1[b];
        list1[a] = list1[b];
        list1[b] = t-list1[a];

        int temp = list2[a];

        for (int j = a + 1; j <= b; ++j) {
            if (list1[a] > list1[j]) {
                cnt1 += 1;
            }

            if (j == b) continue;

            if (list1[j] > list1[b] && list1[j] > list1[a]) {
                // pass
            } else if (list1[j] < list1[b] && list1[j] < list1[a]) {
                // pass
            } else if (list1[j] > list1[b] && list1[j] < list1[a]) {
                list2[j] += 1;
                ans += 1;
            } else if (list1[j] < list1[b] && list1[j] > list1[a]) {
                list2[j] -= 1;
                ans -= 1;
            }

            if (list1[j] < list1[b]) {
                cnt2 += 1;
            }
        }

        list2[a] = list2[b] + cnt1;
        ans += cnt1;
        if (list1[a] < list1[b]) {
            cnt2 += 1;
        }
        list2[b] = temp - cnt2;
        ans -= cnt2;

        cout << ans << endl;
    }

    return 0;
}
