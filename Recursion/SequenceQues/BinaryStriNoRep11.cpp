// Question -> 
/*
Generate Binary Strings Without Consecutive 1s
Subscribe to TUF+

Hints
Company
Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.



A binary string is a string consisting only of characters '0' and '1'.


Example 1

Input: n = 3

Output: ["000", "001", "010", "100", "101"]

Explanation: All strings are of length 3 and do not contain consecutive 1s.

Example 2

Input: n = 2

Output: ["00", "01", "10"]

Constraints

1 <= n <= 20
*/


#include <bits/stdc++.h>
using namespace std;

void generate(int n, string current, vector<string>& ans) {
    
    if(current.size() == n) {
        ans.push_back(current);
        return;
    }

    //  always adding '0'
    generate(n, current + '0', ans);             // first going deep till 000 then 001

   //  add '1' only if this condition is true
    if(current.empty() || current.back() != '1') {
        generate(n, current + '1', ans);
    }
}

int main() {
    int n = 3;
    vector<string> ans;

    generate(n, "", ans);

    for(auto &s : ans) cout << s << endl;
}

/*
Output -> 
000
001
010
100
101

                          ""                               // this is how the tree looks
                     /          \
                  "0"            "1"
                /     \          /
            "00"     "01"     "10"
           /   \      /        /   \
       "000" "001" "010"   "100" "101"



*/