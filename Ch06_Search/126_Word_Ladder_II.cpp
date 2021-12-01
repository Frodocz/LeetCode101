/**
 * 6.4 Breadth-First Search 2(BFS)
 * 126. Word Ladder II(Hard)
 * 
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 *  * Every adjacent pair of words differs by a single letter.
 *  * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 *  * s_k == endWord
 * 
 * Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, 
 * or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 * 
 * 
 * Constraints:
 *  * 1 <= beginWord.length <= 5
 *  * endWord.length == beginWord.length
 *  * 1 <= wordList.length <= 1000
 *  * wordList[i].length == beginWord.length
 *  * beginWord, endWord, and wordList[i] consist of lowercase English letters.
 *  * beginWord != endWord
 *  * All the words in wordList are unique.
 * 
 */
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> dict (wordList.begin(), wordList.end());
    unordered_set<string> visited;
    // q contains paths, now only 1 path {beginWord} at the beginning
    queue<vector<string>> q;
    q.push({beginWord});
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            // process current path
            vector<string> curPath = q.front();
            q.pop();
            // find the last string in the current path
            string last = curPath.back();
            // change each element of the last word from 'a' to 'z'
            for (int i = 0; i < last.size(); i++) {
                // keep a temp copy of last
                string tmp = last;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    // modify ith char of last word's copy
                    tmp[i] = ch;
                    // new neighbour of last word found in wordList
                    if (dict.find(tmp) != dict.end()) {
                        auto newPath = curPath;
                        newPath.push_back(tmp);
                        visited.insert(tmp);
                        if (tmp == endWord) {
                            ans.push_back(newPath);
                        } else {
                            q.push(newPath);
                        }
                    }
                }
            }
        }
        for (auto& str : visited) {
            dict.erase(str);
        }
    }
    return ans;
}

// Faster
// 主函数
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) { 
    vector<vector<string>> ans; 
    // for (const auto &w: wordList) dict.insert(w); // can just use the constructor with iterators
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord)) return ans;

    dict.erase(beginWord);
    dict.erase(endWord);

    unordered_set<string> q1{beginWord}, q2{endWord}; // BFS from two ends
    
    unordered_map<string, vector<string>> next;
    bool reversed = false, found = false;

    while (!q1.empty()) {
        unordered_set<string> q; 
        for (const auto &w: q1) {
            string s = w;
            for (int i = 0; i < s.size(); ++i) {
                char ch = s[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    s[i] = c;
                    if (q2.count(s)) {
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        found = true;
                    }
                    if (dict.count(s)) {
                        reversed? next[s].push_back(w): next[w].push_back(s);
                        q.insert(s);
                    }
                }
                s[i] = ch;
            }
        }
        if (found) break;
        for (const auto &w : q) dict.erase(w);

        if (q.size() <= q2.size()) { 
            q1 = q;
        } else {
            reversed = !reversed;
            q1 = q2;
            q2 = q;
        } 
    }
    if (found) {
        vector<string> path = {beginWord};
        backtracking(beginWord, endWord, next, path, ans);
    }
    return ans;
}

// 辅函数
void backtracking(const string &src, const string &dst, unordered_map<string,
    vector<string>> &next, vector<string> &path, vector<vector<string>> &ans) {
    if (src == dst) {
        ans.push_back(path);
        return; 
    }
    for (const auto &s: next[src]) { 
        path.push_back(s);
        backtracking(s, dst, next, path, ans); 
        path.pop_back();
    } 
}