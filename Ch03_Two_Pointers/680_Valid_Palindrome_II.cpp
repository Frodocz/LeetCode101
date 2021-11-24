/**
 * 3.6 基础练习2
 * 680. Valid Palindrome II(Easy)
 * 
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * 
 * The testcases will be generated such that the answer is unique.
 * A substring is a contiguous sequence of characters within the string.
 * 
 * Input: s = "aba", Output: true
 * Input: s = "abca", Output: true, Explanation: You could delete the character 'c'.
 * Input: s = "abc", Output: false
 * 
 * Constraints:
 *  * 1 <= s.length <= 10^5
 *  * s consists of lowercase English letters.
 */

bool isp(string s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

bool validPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            ++l;
            --r;
        } else {
            return isp(s, l + 1, r) || isp(s, l, r - 1);
        }
    }
    return true;
}

// Another Iterative Way
bool validPalindrome(string s) {
    if(s == null || s.size() == 0) return false;
        
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) { i++; j--; }
    if (i >= j) return true;
        
    int i1 = i, j1 = j - 1;
    while (i1 < j1 && s[i1] == s[j1]) { i1++; j1--; }
    if(i1 >= j1) return true;
        
    int i2 = i + 1, j2 = j;
    while(i2 < j2 && s[i2] == s[j2]) { i2++; j2--; }
    return i2 >= j2;
}