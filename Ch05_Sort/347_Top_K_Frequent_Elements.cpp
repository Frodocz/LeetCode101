/**
 * 5.3 Bucket Sort
 * 347. Top K Frequent Elements(Medium)
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2, Output: [1,2]
 * 
 * Input: nums = [1], k = 1, Output: [1]
 * 
 * Input: s = "a", t = "aa", Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * Constraints:
 *  * 1 <= nums.length <= 10^5
 *  * k is in the range [1, the number of unique elements in the array]
 *  * It is guaranteed that the answer is unique.
 * 
 */
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    int maxCnt = 0;

    for (const int &num : nums) {
        maxCnt = max(maxCnt, ++counts[num]);
    }

    vector<vector<int>>buckets(maxCnt + 1);
    for (const auto &p : counts) {
        buckets[p.second].push_back(p.first);
    }

    vector<int> ans;
    for (int i = maxCnt; i >= 0 && ans.size() < k; --i) {
        for (const int &num : buckets[i]) {
            ans.push_back(num);
            if (ans.size() == k) break;
        }
    }
    return ans;
}
