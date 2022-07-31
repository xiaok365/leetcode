#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:

    Solution() = default;

    static int maxOfTwo(int a, int b) {
        return a > b ? a : b;
    }

    static int maxSubArray(vector<int> &nums) {
        int pre = 0, now = 0, maxAnswer = -2147483647;
        for (int i = 0; i < nums.size(); i++) {

            if (pre > 0)
                now = pre + nums[i];
            else
                now = nums[i];
            maxAnswer = maxOfTwo(maxAnswer, now);
            pre = now;
        }
        return maxAnswer;
    }
};

int main() {

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int i = 0, n;
    vector<int> nums(10000, 0);

    while (cin >> n) {
        nums[i++] = n;
    }

    auto *solution = new Solution();
    cout << solution->maxSubArray(nums);

    return 0;
}