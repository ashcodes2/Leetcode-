class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size()) {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                right = mid - 1; // Try to find an earlier day
            } else {
                left = mid + 1; // Need more days for flowers to bloom
            }
        }

        return ans;
    }

private:
    bool canMake(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int count = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }
};