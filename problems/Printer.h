//
// Created by ilya on 6/24/19.
//

#ifndef TRAINLETTCODE_PRINTER_H
#define TRAINLETTCODE_PRINTER_H
#include <vector>
#include <iostream>
#include <stdio.h>

class Printer {

public:
    void printArray(std::vector<int>& array) const {
        printf(" [");
        for (int i=0; i<array.size() ;i++) {
            int num = array[i];
            if (i == array.size()-1){
                printf("%d", num);
            }
            else {
                printf("%d, ", num);
            }
        }
        printf("]");
    }
};


#endif //TRAINLETTCODE_PRINTER_H
