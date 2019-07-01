#include "problems/TwoSum.h"
#include "problems/LongestSubstring.h"
#include "problems/MedianTwoSortedArrays.h"
#include <iostream>

int main() {
    TwoSum twoSum = TwoSum();
    twoSum.solve();
    LongestSubstring longestSubstring = LongestSubstring();
    longestSubstring.solve();
    MedianTwoSortedArrays twoSortedArraysMedian = MedianTwoSortedArrays();
    twoSortedArraysMedian.solve();
    return 0;
}