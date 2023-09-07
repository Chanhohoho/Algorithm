#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (string a, string b){
    if (a[0]>b[0]) return true;
    if (a[0]==b[0] && (a[0]>=b[1] && a[1]=='\n') || (a[1] > b[1])) return true;
    
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    
    for(int i=0; i<numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
        // cout<<v[i]<<endl;
        // cout<<to_string(numbers[i])<<endl;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++) answer=answer+v[i];
    
    return answer;
}