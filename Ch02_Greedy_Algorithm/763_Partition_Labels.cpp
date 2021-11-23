/**
 * 2.4 基础练习3
 * 763. Partition Labels(Medium)
 * 
 * You are given a string s. We want to partition the string into as many parts as possible so that 
 * each letter appears in at most one part.
 * 
 * Return a list of integers representing the size of these parts.
 * 
 * Input: s = "ababcbacadefegdehijhklij", Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
 * 
 * Input: s = "eccbbbbdec", Output: [10]
 * 
 * Constraints:
 *  * 1 <= s.length <= 500
 *  * s consists of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    // last[char] -> index of s where char occurs last
    vector<int> last(26);
    for (int i = 0; i < s.size(); ++i) {
        last[s[i] - 'a'] = i;
    }

    int j = 0, anchor = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i) {
        j = max(j, last[s[i] - 'a']);
        if (i == j) {
            ans.push_back(i - anchor + 1);
            anchor = i + 1;
        }
    }
    return ans;
}
