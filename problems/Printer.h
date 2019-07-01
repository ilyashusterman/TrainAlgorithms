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
        for (int & it : array) {
            printf("%d,", it);
        }
        printf("]");
    }
};


#endif //TRAINLETTCODE_PRINTER_H
