/**
 * 3.6 进阶练习1
 * 340. Longest Substring with At Most K Distinct Characters(Hard)
 * 
 * Given a string, find the length of the longest substring T that contains at most k distinct characters.
 * 
 * Input: s = "eceba", k = 2, Output: 3
 * Explanation: T is "ece" which its length is 3.
 * 
 * Input: s = "aa", k = 1, Output: 2
 * Explanation: T is "aa" which its length is 2.
 */


// 1. keep tracking the size char hashtable d, if oversized, pull the least index value from it and delete the entry, update the low index.
// 2. each step compare the current min with (i - low + 1)
int lengthOfLongestSubstringKDistinct(string s, int k) {
	vector<int> map(128);
	int slow = 0, fast = 0, cnt = 0, d = 0;
	while (fast < s.size()) {
		if (map[s[fast++]]++ == 0) { // cur char not in map
			++cnt;
		}
		while (cnt == k + 1) {
			if (map[s[slow++]]-- == 1) --cnt; // or cnt > k
		}
		d = max(d, fast - slow);
	}
	return d;
}
