#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct info{
    string time="", inOut="";
    int sumTime=0;
};

struct node{
    string carNum;
    int fee;
};

bool cmp(node &front, node &back){
    return front.carNum<back.carNum;
}

int Time(string inTime, string outTime){
    int ans=0;
    
    int inHour = stoi(inTime.substr(0,2));
    int inMin = stoi(inTime.substr(3,2));
    int outHour = stoi(outTime.substr(0,2));
    int outMin = stoi(outTime.substr(3,2));
    
    if(outMin - inMin>=0) ans = (outHour - inHour)*60 + outMin - inMin;
    else ans = (outHour - inHour - 1)*60 + 60 + outMin - inMin;
    
    return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    unordered_map<string, info> fee;
    
    int len = records.size();
    for(int i=0; i<len; i++){
    
        string time = records[i].substr(0,5);
        string carNum = records[i].substr(6,4);
        string inOut = records[i].substr(11);
        
        if(inOut == "OUT"){
            info now = fee[carNum];
            now.sumTime+=Time(now.time,time);
            now.time = time;
            now.inOut = inOut;
            
            fee[carNum] = now;
        }
        else{
            info now = fee[carNum];
            now.time = time;
            now.inOut = inOut;
            
            fee[carNum] = now;
        }
    }
    
    vector<node> v;
    
    for(auto it=fee.begin(); it!=fee.end(); it++){
        if(it->second.inOut=="IN") it->second.sumTime+=Time(it->second.time,"23:59");
        
        int sum = it->second.sumTime;
        
        int nowFee = fees[1];
        if(sum>fees[0]){
            sum-=fees[0];
            if(sum%fees[2]==0) nowFee+=sum/fees[2]*fees[3];
            else nowFee+=(sum/fees[2]+1)*fees[3];  
        }
        
        node now = {it->first, nowFee};
        v.push_back(now);
    }
    
    sort(v.begin(), v.end(), cmp);
    len = v.size();
    for(int i=0; i<len; i++) answer.push_back(v[i].fee);
    
    return answer;
}