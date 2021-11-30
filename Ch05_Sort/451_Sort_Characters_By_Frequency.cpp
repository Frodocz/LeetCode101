/**
 * 5.4 Basic Practice
 * 451. Sort Characters By Frequency(Medium)
 * 
 * Given a string s, sort it in decreasing order based on the frequency of the characters.
 * The frequency of a character is the number of times it appears in the string.
 * 
 * Return the sorted string. If there are multiple answers, return any of them.
 * 
 * 
 * Input: s = "tree", Output: "eert"
 * Explanation: 'e' appears twice while 'r' and 't' both appear once. So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * 
 * Input: s = "cccaaa", Output: "aaaccc"
 * Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers. 
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * Input: s = "Aabb", Output: "bbAa"
 * Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * Constraints:
 *  * 1 <= s.length <= 10^5
 *  * s consists of uppercase and lowercase English letters and digits.
 * 
 */
string frequencySort(string s) {
    unordered_map<char, int> counts;
    int max_count = 0;
    for (const char & c : s) {
        max_count = max(max_count, ++counts[c]);
    }
    vector<vector<int>> buckets(max_count + 1);
    for (const auto & p : counts) {
        // can use vector of set for ordered string
        buckets[p.second].push_back(p.first);
    }
    string ans;
    for (int i = max_count; i >= 0; --i) {
        for (const char & c : buckets[i]) {
            ans += string(i, c);
        }
    }
    return ans;
}
