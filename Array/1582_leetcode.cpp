
// 1582. Special Positions in a Binary Matrix
// Approach: Brute Force
#include<iostream>
#include<vector>
using namespace std;

    int numSpecial(vector<vector<int>>& mat) {
        vector<pair<int,int>>Rindex;
        int m =  mat.size();
        for(int i = 0; i< m; i++){
            for(int j = 0; j< mat[i].size(); j++){
                if(mat[i][j] == 1){
                    Rindex.push_back({i,j});
                }
            }
        }
        int count = 0;
        for(auto x : Rindex){
            bool isPrsntRow = false;
            bool isPrsntCol = false;
            for(int i = 0; i<mat[x.first].size(); i++){
                if(mat[x.first][i] == 1 && i != x.second){
                    isPrsntRow = true;
                }
            }
            for(int j = 0; j<mat.size(); j++){
                if(mat[j][x.second] == 1 && j != x.first){
                    isPrsntCol = true;
                }
            }
            if(isPrsntRow || isPrsntCol){
                count = count;
            }else{
                count++;
            }
        }
        return count;
    }

    int main(){
        vector<vector<int>> mat = {{1,0,0},
                                   {0,0,1},
                                   {1,0,0}};
        cout<<numSpecial(mat);
    }





// methoed 2: count number of 1s in rows and columns and then check for special positions
    
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> row(m,0);
        vector<int> col(n,0);

        // count 1s in rows and columns
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int ans = 0;

        // check special positions
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
