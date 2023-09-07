#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int r1 = arr1.size();
    int c1 = arr1[0].size();
    int r2 = arr2.size();
    int c2 = arr2[0].size();
    
    for(int i=0; i<r1; i++){
        vector<int> vec(c2,0);   
        answer.push_back(vec);
    }
    
    for(int i=0; i<r1; i++) for(int j=0; j<c2; j++) for(int c=0; c<c1; c++) answer[i][j]+=arr1[i][c]*arr2[c][j];

    return answer;
}