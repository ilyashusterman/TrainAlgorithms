//
// Created by ilya on 6/24/19.
//

#ifndef TRAINLETTCODE_LONGESTSUBSTRING_H
#define TRAINLETTCODE_LONGESTSUBSTRING_H

/*
 * Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <string>
#include <stdio.h>
#include <iostream>

class LongestSubstring {


public:
    public: void solve() {
        printf("Running, LongestSubstring \n");
        std:: string const testStrings[] = { "ppppppppppppppppppabcabcbb", "abcabcbb", "bbbbb", "pwwkew", "abcabcgabcgf"};
        int length = 0;
        for(const std::string& string_s : testStrings) {
            lengthOfLongestSubstring(string_s);
        }
    }
    void lengthOfLongestSubstring(std::string s_string) {
        std::string longestSubstring = getLongestSubstring(s_string);
        int length = longestSubstring.size();
        printf("Example: \nInput: '%s' \n", s_string.c_str());
        printf("Output: %d \n", length);
        printf("Explanation: The answer is \"%s\", with the length of %d. \n\n", longestSubstring.c_str(), length);
    }
    std:: string getLongestSubstring(std:: string s_string){
        std:: string tempSubString;
        std:: string tempCurrentCharacter;
        std:: string maxSubString;
        for(char i : s_string) {
            // get current character
            tempCurrentCharacter = i;
            // is this character duplicated ? (already in the substring)
            if (tempSubString.find(tempCurrentCharacter) != std::string::npos) {
                //yes we found this character already exist in substring resetting substring...
                tempSubString = tempCurrentCharacter;
            } else {
                //current character was not found , updating substring...
               tempSubString +=tempCurrentCharacter;
            }
            // is the new substring size the longest?
            // if so save it
            if (tempSubString.size()> maxSubString.size()){
                maxSubString = tempSubString;
            }

        }
        return  maxSubString;
    }
};


#endif //TRAINLETTCODE_LONGESTSUBSTRING_H
