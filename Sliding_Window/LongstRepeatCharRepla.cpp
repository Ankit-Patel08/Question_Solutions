// 424. Longest Repeating Character Replacement

// done by sliding window and two pointer approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // int count = 0;
        // int maxi = 0;
        // int n = s.length();
        // int approaching = 0;
        // char presentChar = s[0];
        // for(int i = 0; i<n; i++){
        //     if(s[i] == presentChar){
        //         count++;
        //         maxi = max(maxi,count);     // if all the char are same
        //     }else{ 
        //         if(k != 0){
        //         approaching++;
        //         if(approaching <= k){
        //             count++;
        //             maxi = max(maxi,count);
        //         }else{
        //             presentChar = s[i];
        //             count = 0;
        //             approaching = 0;
        //         }
        //         }else{
        //             presentChar = s[i];
        //         }
        //     }
        // }
        // return maxi;

        int count = 0;
        int maxCount = 0;

        vector<int>freq(26,0);

        int left = 0;
        int right = 0;
        int n = s.length();
        for(right = 0; right<n; right++){
            freq[s[right]-'A']++;
            maxCount = max(maxCount,freq[s[right]-'A']);

            if(right-left+1 - maxCount > k){
                freq[s[left]-'A']--;
                left++;
            }
        }
        return n-left;
    }
};