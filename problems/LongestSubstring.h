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
#include <map>

class LongestSubstring {


public:
    public: static int main() {
        std::cout << "Running, LongestSubstring" << std::endl;
        std:: string const testStrings[] = {"abcabcbb", "bbbbb", "pwwkew", "pppppppppppacbacbacbab"};
        std:: string s_string;
        int length = 0;
        for(int i = 0; i < testStrings->length(); i++) {
            s_string = testStrings[i];
            length = lengthOfLongestSubstring(s_string);
            printf("length of %d in %s \n", length, s_string.c_str());

//            exit(0);
        }
        return 0;
    }
    static int lengthOfLongestSubstring(std::string s_string) {
        std::string longestSubstring = getLongestSubstring(s_string);
        printf("string_s of  %s \n", longestSubstring.c_str());
        return longestSubstring.size();
    }
    static std:: string getLongestSubstring(std:: string s_string){
        /*
         * First Find substrings
         * Second put max value for length size
         */
        std:: string tempSubString;
        std:: string prevCharacter;
        std:: string tempCurrentCharacter;
        std:: string maxSubString;
        int maxSize=0;
        std::string::size_type lastSubstringIndex=0;
        for(std::string::size_type i = 0; i < s_string.size(); ++i) {
            tempCurrentCharacter = s_string[i];
            if (tempCurrentCharacter != prevCharacter) {
                // yes
                // is character in the substring?
                if (tempSubString.find(tempCurrentCharacter) != std::string::npos) {
                    //yes
                    tempSubString = tempCurrentCharacter;
                    lastSubstringIndex = i;
                } else {
                    int index = i-1;
                    if (i==0){
                        index = i+1;
                    }
                    tempSubString = s_string.substr(lastSubstringIndex, index);
                }
                // is the new substring size the longest?
                if (tempSubString.size()> maxSize){
                    maxSize = tempSubString.size();
                    maxSubString = tempSubString;
                }

            }
            else{
                lastSubstringIndex = i;
            }
            prevCharacter = tempCurrentCharacter;
        }
        return  maxSubString;
    }
};


#endif //TRAINLETTCODE_LONGESTSUBSTRING_H
