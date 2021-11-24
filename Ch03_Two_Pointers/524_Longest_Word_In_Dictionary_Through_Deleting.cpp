/**
 * 3.6 基础练习3
 * 524. Longest Word in Dictionary through Deleting(Medium)
 * 
 * Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed 
 * by deleting some of the given string characters. 
 * 
 * If there is more than one possible result, return the longest word with the smallest lexicographical order. 
 * If there is no possible result, return the empty string.
 * 
 * Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * Output: "apple"
 * 
 * Input: s = "abpcplea", dictionary = ["a","b","c"]
 * Output: "a"

 * Constraints:
 *  * 1 <= s.length <= 1000
 *  * 1 <= dictionary.length <= 1000
 *  * 1 <= dictionary[i].length <= 1000
 *  * s and dictionary[i] consist of lowercase English letters.
 */

string findLongestWord(string s, vector<string>& dictionary) {
    int n = dictionary.size();
    string ans;
    for (auto cur : dictionary) {
        if (isSubsequence(s, cur)) {
            // Note: string.size() --> unsigned
            if (cur.size() > ans.size() || (cur.size() == ans.size() && cur < ans))
                ans = cur;
        }
    }
    return ans;
}

// a is example string, b is string in dictionary
bool isSubsequence(const string &a, const string &b) { 
    if (a.size() < b.size()) return false;
    int l = 0, r = 0, cnt = 0, n1 = a.size(), n2 = b.size();
    while (l < n1 && r < n2) {
        if (a[l] == b[r]) {
            ++l;
            ++r;
        } else {
            l++;
        }
    }
    return r == n2;
}
