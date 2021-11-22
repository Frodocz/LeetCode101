/**
 * 2.2 分配问题2
 * 135. Candy(Hard)
 * 
 * There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
 * You are giving candies to these children subjected to the following requirements:
 *  * Each child must have at least one candy.
 *  * Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to have to distribute the candies to the children.
 * 
 * Input: ratings = [1,0,2], Output: 5
 * Input: ratings = [1,2,2], Output: 4
 * 
 * Constraints:
 *  * n == ratings.length
 *  * 1 <= n <= 2 * 10^4
 *  * 0 <= ratings[i] <= 2 * 10^4
 */

#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings) {
    int size = ratings.size();
    if (size < 2) return size; // Only 0 or 1 child, return size;
    vector<int> num(size, 1); // initialize the number of suger for each child

    for (int i = 1; i < size; ++i) { // from left -> right, update the right child if right child's rating > left child's ratiing
        if (ratings[i] > ratings[i - 1]) 
            num[i] = num[i - 1] + 1;
    }

    for (int i = size - 1; i > 0; --i) { // from right -> left, update the left child if left child's rating > left child's ratiing
        if (ratings[i] < ratings[i - 1]) 
            num[i - 1] = max(num[i - 1], num[i] + 1);
    }

    return accumulate(num.begin(), num.end(), 0); // std::accumulate for sum of vector
}
