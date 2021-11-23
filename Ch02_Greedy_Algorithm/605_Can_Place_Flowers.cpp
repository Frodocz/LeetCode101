/**
 * 2.4 基础练习1
 * 605. Can Place Flowers(Easy)
 * 
 * You have a long flowerbed in which some of the plots are planted, and some are not. 
 * However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
 * and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 1, Output: true
 * Input: flowerbed = [1,0,0,0,1], n = 2, Output: false
 * 
 * Constraints:
 *  * 1 <= flowerbed.length <= 2 * 10^4
 *  * flowerbed[i] is 0 or 1.
 *  * There are no two adjacent flowers in flowerbed.
 *  * 0 <= n <= flowerbed.length
 */

#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0, cnt = 0, size = flowerbed.size();

    while (i < size) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            ++cnt;
        }
        if (cnt >= n) return true;
    }
    return false;
}
