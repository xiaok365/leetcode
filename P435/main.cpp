#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> a(100, vector<int>(2, 0));

class Solution {
public:
    static int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int ans = 1, right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= right) {
                right = intervals[i][1];
                ans++;
            }
        }

        return intervals.size() - ans;
    }

    static bool cmp(const vector<int> &u, const vector<int> &v) {
        return u[1] < v[1];
    }
};


int main() {

    freopen("../a.in", "r", stdin);
//    freopen("../a.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

//    a.resize(n);
//    sort(a.begin(), a.end(), cmp);
//
//    int ans = 1, right = a[0][1];
//    for (int i = 1; i < n; ++i) {
//        if (a[i][0] >= right) {
//            right = a[i][1];
//            ans++;
//        }
//    }

    cout << Solution::eraseOverlapIntervals(a) << endl;

//    for (int i = 0; i < n; ++i) {
//        cout << a[i][0] << " " << a[i][1] << endl;
//    }

    return 0;
}
