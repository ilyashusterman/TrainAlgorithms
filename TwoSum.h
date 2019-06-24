//
// Created by ilya on 6/24/19.
//

#ifndef TRAINLETTCODE_TWOSUM_H
#define TRAINLETTCODE_TWOSUM_H

#include <vector>
#include <iostream>
#include <stdio.h>

class TwoSum {

    public: int main() {
        std::cout << "Running, TwoSum" << std::endl;
        std::vector<int> array = { 1, 2,3,4};
        printArrayInt(this->twoSum(array, 7), array);
        return 0;
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
        std::cout << '\n';
    }
};


#endif //TRAINLETTCODE_TWOSUM_H
