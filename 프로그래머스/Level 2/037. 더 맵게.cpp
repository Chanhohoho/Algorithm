#include <string>
#include <vector>
using namespace std;

vector<int> dat(100000001, 0);

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int len = scoville.size();
    for(int i=0; i<len; i++) dat[scoville[i]]++;
    
    int fir=0;
    int sec=0;
    while(1){
        
        while(dat[fir]==0) fir++;
        if(fir>=K) break;
        long long first = fir;
        dat[fir]--;
        while(dat[sec]==0) sec++;
        long long second = sec;
        dat[sec]--;
        
        long long sum = first + 2*second;
        dat[sum]++;
        
        answer++;
        len--;
        
        if(len==1) {
            if(sum>=K) return answer;
            else return -1;
        }
        
    }
    
    return answer;
}