/**
 * 2.2 分配问题1
 * 455. Assign Cookies (Easy)
 * 
 * Assume you are an awesome parent and want to give your children some cookies. 
 * But, you should give each child at most one cookie.
 * Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
 * and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
 * Your goal is to maximize the number of your content children and output the maximum number.
 * 
 * Input: g = [1,2,3], s = [1,1], Output: 1
 * Input: g = [1,2], s = [1,2,3], Output: 2
 * 
 * Constraints:
 *  * 1 <= g.length <= 3 * 10^4
 *  * 0 <= s.length <= 3 * 10^4
 *  * 1 <= g[i], s[j] <= 2^31 - 1
 */

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &children, vector<int> &cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (children[child] <= cookies[cookie]) ++child;
        ++cookie;
    }
    return child;
}
