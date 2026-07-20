class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];
            int pos = -1;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == target) {
                    pos = j;
                    break;
                }
            }

            int nextGreater = -1;
            for (int j = pos + 1; j < nums2.size(); j++) {
                if (nums2[j] > target) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};