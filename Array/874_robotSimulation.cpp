#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void getDirection(char &currDir, int num){
    //     if(currDir == 'N' && num == -1){
    //         currDir = 'E';
    //         return;
    //     }
    //      if(currDir == 'N' && num == -2){
    //         currDir = 'W';
    //         return;
    //     }
    //      if(currDir == 'S' && num == -1){
    //         currDir = 'W';
    //         return;
    //     }
    //      if(currDir == 'S' && num == -2){
    //         currDir = 'E';
    //         return;
    //     }
    //     if(currDir == 'E' && num == -1){
    //         currDir = 'S';
    //         return;
    //     }
    //     if(currDir == 'E' && num == -2){
    //         currDir = 'N';
    //         return;
    //     }
    //      if(currDir == 'W' && num == -1){
    //         currDir = 'N';
    //         return;
    //     }
    //      if(currDir == 'W' && num == -2){
    //         currDir = 'S';
    //         return;
    //     }
    // }


    string dirs = "NESW";
    int idx = 0;

    void getDirection(char &currDir, int num) {
        if (num == -1) idx = (idx + 1) % 4;
        if (num == -2) idx = (idx + 3) % 4;
        currDir = dirs[idx];
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char currDir = 'N';
        int NScount = 0;
        int EWcount = 0;
        int maxDist = 0;
        unordered_set<string>obs;
       for(auto x : obstacles){
        string key = to_string(x[0])+"_"+to_string(x[1]);
        obs.insert(key);
       }
       for(int i = 0; i<commands.size(); i++){
        if(commands[i] == -1 || commands[i] == -2){
            getDirection(currDir, commands[i]);   // getting the direction ACto commands 
        }else{
            for(int step = 0; step < commands[i]; step++){  // going throught every step
                int newNS = NScount;    
                int newEW = EWcount;
                switch(currDir){
                    case 'N': newNS++; break;
                    case 'S': newNS--; break;
                    case 'E': newEW++; break;
                    case 'W': newEW--; break;
                }
                string check = to_string(newEW)+"_"+to_string(newNS);

                if(obs.count(check)) break;  // if obstacle present then break before updation

                NScount = newNS;
                EWcount = newEW;

                maxDist = max(maxDist, NScount*NScount+EWcount*EWcount);
            }
        }
       }
        return maxDist;
    }
};

int main() {
    Solution sol;

    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};

    int result = sol.robotSim(commands, obstacles);

    cout << result << endl;

    return 0;
}