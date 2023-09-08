#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.rbegin(), people.rend());   // 내림차순으로 정렬
    
    for(int i=0, j=people.size()-1; i<=j; i++){
        if(people[i] + people[j] <= limit) j--;
        answer++;
    }
    
    return answer;
}
