// File Name: 0008-STRING-TO-INT.CPP
// Author: Qiangua
// Email: caicailiushui@protonmail.com
// Copyright © 2021, Qiangua, all rights reserved.
// Created: 19 November 2021

#include "headers.h"
#include <gtest/gtest.h>

class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign=1,pre;
        string si,sn;
        s.erase(0,s.find_first_not_of(" "));
        map <string,int> table={
            {"-",0},
            {"+",0},
            {"0",0},
            {"1",1},
            {"2",2},
            {"3",3},
            {"4",4},
            {"5",5},
            {"6",6},
            {"7",7},
            {"8",8},
            {"9",9}
        };
        std::string a{s[0]};
        std::string b{s[1]};
        if (table.find(a) == table.end()){
            cout << "case00" << endl;
            return 0;
        }
        else if (a == "-") {
            sign = -1;
            pre = 0;
            // cout << "1:pre =" << pre << endl;
        }
        else if (a == "+"){
            sign = 1;
            pre = 0;
            // cout << "2:pre =" << pre << endl;
        }
        else {
            pre = table[a];
            // cout << "3:pre=" << pre << endl;
        }

        if ( ( a == "+" && b == "-" ) || ( a == "-" && b == "+") ) {
            cout << "case01" << endl;
            return 0;
        }

        for (i = 0; i < s.size()-1; ++i) {
            // cout << "i=" << i << endl;
            si = {s[i]};
            sn = {s[i+1]};
            if (table.find(si) != table.end()){
                if ( (pre > INT_MAX/10 && table.find(sn) != table.end()) || ( pre == INT_MAX/10 && table.find(sn)->second > 7 )) {
                    cout << "Case1" << endl;
                    return INT_MAX;
                }
                else if (pre < INT_MIN/10 && table.find(sn) != table.end()|| ( pre == INT_MIN/10 && table.find(sn)->second > 8 )) {
                    return INT_MIN;
                }
                else if ( table.find(sn) != table.end() && sn != "-" && sn != "+" ){
                    pre = pre * 10 + sign*table[sn] ;
                }

                if ( table.find(sn) == table.end() || sn == "-" || sn == "+"){
                    // cout << "case3" << endl;
                    return pre;
                }
            }

        }
        return pre;
    }

    int myAtoi2(string s) {
        int i=0,sign=1,pre=0;

        //trim leading whitespace
        s.erase(0,s.find_first_not_of(" "));
        //check s
        // cout << s << endl;

        // void
        if (s.size() == 0) {
            return 0;
        }

        if (s.size() == 1 && isdigit(s[0])) {
            return s[0] - '0';
        }

        if ( s[0] != '-' && s[0] != '+' && !isdigit(s[0])) {
            return 0;
        }
        else if ( s[0] == '-' ) {
            sign = -1;
            pre = 0;
        }
        else if ( s[0] == '+' ) {
            sign = 1;
            pre = 0;
        }
        else {
            pre = s[0] - '0';
        }

        // second char
		if ( isdigit(s[0]) && !isdigit(s[1])){
			cout << "c1" << endl;
			return pre;
		}
		else if ( !isdigit(s[0]) &&  !isdigit(s[1])) {
			cout << "c2" << endl;
			return 0;
		}
        while ( isdigit(s[i+1]) && i < s.size() - 1 ) {
            // cutoff if pre exceed Int32
            if ((pre > INT_MAX/10 && isdigit(s[i+1])) || (pre == INT_MAX/10 && (s[i+1]-'0') > 7)) {
                return INT_MAX;
            }
            else if ( (pre < INT_MIN/10 && isdigit(s[i+1])) || (pre == INT_MIN/10 && (s[i+1]-'0') > 8)) {
                return INT_MIN;
            }
            else {
                pre = pre*10 + sign*(s[i+1]-'0');
                i++;
            }
        }
        return pre;
    }

};

TEST(TTT, TTT) {
    Solution s;
    string s1 = " -1010023630o4" ;
    int expect = -1010023630,actual;
    actual = s.myAtoi2(s1);
    EXPECT_EQ(actual,expect);
}


int main(int argc, char **argv) {
    cout << "Problem: 0008-STRING-TO-INT.CPP" << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}