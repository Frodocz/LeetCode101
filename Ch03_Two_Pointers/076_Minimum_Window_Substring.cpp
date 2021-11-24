/**
 * 3.5 Sliding Window
 * 76. Minimum Window Substring(Hard)
 * 
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s 
 * such that every character in t (including duplicates) is included in the window. 
 * If there is no such substring, return the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC", Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
 * 
 * Input: s = "a", t = "a", Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * Input: s = "a", t = "aa", Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * Constraints:
 *  * m == s.length
 *  * n == t.length
 *  * 1 <= m, n <= 10^5
 *  * s and t consist of uppercase and lowercase English letters.
 * 
 * Could you find an algorithm that runs in O(m + n) time?
 */

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) { 
    vector<int> chars(128, 0); vector<bool> flag(128, false);
    // 先统计T中的字符情况
    for (auto c : t) { 
        flag[c] = true; 
        ++chars[c];
    }
    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, r = 0, min_l = 0, n = s.size(), min_size = n + 1;
    for (int r = 0; r < n; ++r) {
        char c = s[r];
        if (flag[c]) {
            if (--chars[c] >= 0) ++cnt;
            // 若目前滑动窗口已包含T中全部字符，
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (cnt == t.size()) {
                if (r - l + 1 < min_size) {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[s[l]] && ++chars[s[l]] > 0) {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size > s.size()? "": s.substr(min_l, min_size); 
}
