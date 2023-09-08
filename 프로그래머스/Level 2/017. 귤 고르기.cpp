#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int front, int back){
    return front>back;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    vector<int> DAT(10000001, 0);   // 메모리 할당
    
    for(int i=0; i<tangerine.size(); i++)   DAT[tangerine[i]]++;
    
    sort(DAT.begin(), DAT.end(), compare);
        
    while(k>0)  k-=DAT[answer++];
        
    return answer;
}