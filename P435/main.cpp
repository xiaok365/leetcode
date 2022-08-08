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

        return (int) intervals.size() - ans;
    }

    static bool cmp(const vector<int> &u, const vector<int> &v) {
        return u[1] < v[1];
    }
};


int main() {

    freopen("../a.in", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    cout << Solution::eraseOverlapIntervals(a) << endl;

    return 0;
}
