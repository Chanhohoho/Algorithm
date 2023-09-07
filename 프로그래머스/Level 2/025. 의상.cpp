#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> kind2clothes;
    
    for(int i=0; i<clothes.size(); i++) kind2clothes[clothes[i][1]] += 1;
    
    for(auto it = kind2clothes.begin(); it!=kind2clothes.end(); it++)   answer*=it->second+1;
        
    return answer-1;
}