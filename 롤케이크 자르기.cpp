#include <string>
#include <vector>

using namespace std;
int arr1[10001]={0};
int arr2[10001]={0};
int cnt1=0, cnt2=0;

int solution(vector<int> topping) {
    int answer = 0;
    
    int len = topping.size();
    for(int i=0; i<len; i++){
        if(arr2[topping[i]]==0) cnt2++;
        arr2[topping[i]]++;
    }    
    for(int i=0; i<len; i++){
        arr2[topping[i]]--;
        if(arr2[topping[i]]==0) cnt2--;
        if(arr1[topping[i]]==0) cnt1++;
        arr1[topping[i]]++;
        
        if(cnt1==cnt2) answer++;
    }
    
    
    return answer;
}