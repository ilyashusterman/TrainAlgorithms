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
#include <iomanip>
#include "Printer.h"
#include <tgmath.h>

class MedianTwoSortedArrays {
public:
    public:
    void solve() {
        printf("Running, MedianTwoSortedArrays \n");
        //TODO need  to refactor
        Printer printer = Printer();
        std::vector<int> nums1 = {1, 3};
        std::vector<int> nums2 = {2};
        float median;
        float medianCheck = 2.0;
        median = solve_arrays(printer, nums1, nums2);
        assertFloatEqual(median, medianCheck);
        nums1 = {1, 2};
        nums2 = {3, 4};
        medianCheck = 2.50;
        assertFloatEqual(median, medianCheck);
        solve_arrays(printer, nums1, nums2);
        nums1 = {1, 2, 4};
        nums2 = {3, 4};
        medianCheck = 3.0;
        solve_arrays(printer, nums1, nums2);
        assertFloatEqual(median, medianCheck);
    }

    float solve_arrays(const Printer &printer, std::vector<int> &nums1,
                      std::vector<int> &nums2) {
        printf("Example:\n");
        printf("nums1 = ");
        printer.printArray(nums1);
        printf("\nnums2 = ");
        printer.printArray(nums2);
        printf("\n");
        float median = findMedianSortedArrays(nums1, nums2);
        printf("The median is %f \n\n", median);
        return median;
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
                int num_1 = nums1[index_1];
                int num_2 = nums2[index_2];
                if (index_1<nums1.size() && index_2 == nums2.size()){
                    sorted.push_back(num_1);
                    index_1++;
                }
                else if (index_2<nums2.size() && index_1 == nums1.size()) {
                    sorted.push_back(num_2);
                    index_2++;
                }
                else {
                    if (num_1 < num_2) {
                        sorted.push_back(num_1);
                        index_1++;
                    } else if (num_2 <= num_1) {
                        sorted.push_back(num_2);
                        index_2++;
                    }
                }
                count++;
            }

        return sorted;
    }

    void assertFloatEqual(float median, float check) {

        if (median > check && check < median){
                throw 0;
        }
    }


};


#endif //TRAINLETTCODE_MEDIANTWOSORTEDARRAYS_H
