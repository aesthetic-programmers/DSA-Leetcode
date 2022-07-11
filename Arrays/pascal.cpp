/*Brute Force Solution*/


#include <iostream>
using namespace std;

int main(){
  int N;
  cout<<"Enter the number of rows: ";
  cin>>N;

  for(int rows=1; rows<=N; rows++){
    int val=1;
    for(int spaces = N-rows; spaces>0; spaces--){
      cout<<" ";
    }
    for(int cols = 1; cols<=rows; cols++){
      cout<<val<<" ";
      val = val * (rows-cols)/cols;
    }
    cout<<endl;
  }
}

/*Leetcode Solution*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int temp=0;
        int val = 1;

        vector<vector<int>> v(numRows);

        v[0].push_back(1);
        if(numRows == 1){
            return v;
        }
        v[1].push_back(1);
        v[1].push_back(1);
        if(numRows == 2){
            return v;
        }

        for(int i=2; i<numRows; i++){
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    v[i].push_back(1);
                }
                else{
                    temp = v[i-1][j-1] + v[i-1][j];
                    v[i].push_back(temp);
                }
            }
        }
        return v;
    }
};
