#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int arr[100]={0};
    for(int i=0; i<skill.size(); i++) arr[skill[i]]++;
    
    for(int i=0; i<skill_trees.size(); i++){
        string now ="";
        for(int j=0; j<skill_trees[i].size(); j++) if(arr[skill_trees[i][j]]==1) now+=skill_trees[i][j];
        if(skill.find(now)==0) answer++;
    }
    
    return answer;
}