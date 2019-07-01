//
// Created by ilya on 7/1/19.
//

#ifndef TRAINLETTCODE_MEDIANTWOSORTEDARRAYS_H
#define TRAINLETTCODE_MEDIANTWOSORTEDARRAYS_H

/*
 *
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */
#include "Printer.h"


class MedianTwoSortedArrays {
public:
    public:
    void solve() {
        printf("Running, MedianTwoSortedArrays \n");
        float median = findMedianSortedArrays({1, 3}, {2});
        printf("The median is %f \n", median);
        median = findMedianSortedArrays({1, 2}, {3,4});
        printf("The median is %f \n", median);
    }

    float findMedianSortedArrays(std::vector<int> nums1, std::vector<int> nums2) {
        std::vector<int> sorted = setCombinedSorted(nums1, nums2);
        int length = sorted.size();
        if (length % 2 !=0){
            return sorted[int(length/2)] *1.0;
        }else{
            int half_length = int(length/2) -1;
            int a = sorted[half_length];
            int b = sorted[half_length +1];
            return (a+b)/2.0;
        }
    }

    std::vector<int> setCombinedSorted(std::vector<int> nums1, std::vector<int> nums2) {
        std::vector<int> sorted;
            int count = 0;
            int index_1 = 0;
            int index_2 = 0;
            while (count < (nums1.size() + nums2.size())) {
                int a = nums1[index_1];
                int b = nums2[index_2];
                printf("a=%d\n", a);
                printf("b=%d\n", b);
                if (index_1<nums1.size() && index_2 == nums2.size()-1){
                    sorted.push_back(a);
                    index_1++;
                }
                else if (index_2<nums2.size() && index_1 == nums1.size()-1) {
                    sorted.push_back(b);
                    index_2++;
                }
                else {
                    if (a < b) {
                        printf("a in! \n");
                        sorted.push_back(a);
                        index_1++;
                    } else if (b <= a) {
                        printf("b in! \n");
                        sorted.push_back(b);
                        index_2++;
                    }
                }
//                else if(index_1 < nums1.size()-1)
                count++;
            }

        return sorted;
    }


};


#endif //TRAINLETTCODE_MEDIANTWOSORTEDARRAYS_H
