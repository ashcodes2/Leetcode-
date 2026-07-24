class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long hoursNeeded = 0;

            for (int pile : piles) {
                hoursNeeded += (pile + mid - 1) / mid; // Equivalent to ceil(pile / mid)
            }

            if (hoursNeeded <= h) {
                ans = mid;
                right = mid - 1; // Try finding a smaller eating speed
            } else {
                left = mid + 1; // Need a faster eating speed
            }
        }

        return ans;
    }
};