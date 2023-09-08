#include <string>
#include <vector>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    if(arr.size()==1) return arr[0];
    
    int last = arr[0];
    int big, small;
 
    for(int i=1; i<arr.size(); i++){    //  2개씩 비교하여 최소공배수를 찾아냄
    
        if(last<arr[i]) {
            big=arr[i];
            small=last;   
        }
        else {
            big=last;
            small=arr[i];
        }
        
        for(int j=small; j>0; j--){
            if(small%j==0 && big%j==0){
                last = big*small/j;
                break;
            }
        }
    }
    
    return last;
}