//
// Created by ilya on 6/24/19.
//

#ifndef TRAINLETTCODE_TWOSUM_H
#define TRAINLETTCODE_TWOSUM_H

#include <vector>
#include <iostream>
#include <stdio.h>

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

class TwoSum {

    public: int main() {
        std::cout << "Running, TwoSum" << std::endl;
        std::vector<int> array = { 1, 2,3,4};
        int target = 7;
        calculateAndPrint(array, target);
        array = { 2,7,11,15, 16, 1, 2, 3, 5, 7, 9};
        target = 8;
        calculateAndPrint(array, target);
        array = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        target=2;
        calculateAndPrint(array, target);
        return 0;
    }

    void calculateAndPrint(const std::vector<int> &array, int target) {
        std::vector<int> sum_indexes = twoSum(array, target);
        printArrayInt(sum_indexes, array);
        printTarget(target);
    }

public: std::vector<int> twoSum(std::vector<int> nums, int target) {
        int tempNumber = 0;
        int secondTempNumber = 0;
            for(int i = 0; i < nums.size(); ++i) {
                tempNumber = nums[i];
                if (tempNumber <= target){
                    for(int j = i+1; j<nums.size(); j++){
                        secondTempNumber = nums[j];
                        if(secondTempNumber<= target && secondTempNumber+tempNumber == target){
                            return {i, j};
                        }
                    }
                }
            }

    }

    void printArrayInt(std::vector<int>  indexes, std::vector<int>  array) const {
        std::cout << "The indexes of array are:";
        for (std::vector<int>::iterator it = indexes.begin();
             it != indexes.end(); ++it) {
             printf ("array[%d]=%d ", *it,  array[*it]);
        }
        printf (" [");
        for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it){
            printf ("%d,", *it);
        }
        printf ("]");
    }

    void printTarget(int target) const {
        printf(" for target %d", target);
        std::cout << '\n';
    }
};


#endif //TRAINLETTCODE_TWOSUM_H
