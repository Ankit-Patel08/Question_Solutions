
/*
Approach -> greedy algorithm
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        int len = tasks.size();
        for(int i = 0; i < len; i++){
            freq[tasks[i]-'A']++;
        }
        auto maxFreq = *max_element(freq.begin(), freq.end());  // this * because this funct
                                                              // gives the address * will 
                                                              // gives the value at that adrs
        int uniqElem = 0;                                                     
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) uniqElem++;
        }                                                    
        int maxFreqElemntCount = 0;  // how many are equal to maxFreq element
                                                  
        for(int i = 0; i<26; i++){
            if(freq[i] == maxFreq) maxFreqElemntCount++;
        }   

    //   if(n >= uniqElem){
    //       return ((n+1)*(maxFreq-1)) + maxFreqElemntCount;
    //   }else{
    //     return ((uniqElem)*(maxFreq-1)) + maxFreqElemntCount;
    //   }

       int part = (maxFreq - 1) * (n + 1) + maxFreqElemntCount;

        return max((int)tasks.size(), part);

    }                           
};

int main(){
    Solution obj;
    vector<char>tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout<<obj.leastInterval(tasks,n);
    return 0;
}