#include <string>
#include <vector>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    int DAT[1000001]={0};
    
    int len = elements.size();
    for(int i=0; i<len; i++)    elements.push_back(elements[i]);
    
    for(int i=1; i<=len; i++){
        for(int st=0; st<len; st++){        // 연속 부분 수열의 시작점
            int sum=0;
            for(int now=0; now<i; now++){   // 연속 부분 수열의 합
                sum+=elements[st+now];
            }
            if(DAT[sum]==0) {
                DAT[sum]=1;
                answer++;
            }
        }
    }
    
    return answer;
}