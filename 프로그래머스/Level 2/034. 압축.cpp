#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    unordered_map<string, int> list;
    
    int cnt=27;
    
    for(int i=0; i<26; i++){
        string s = "";
        s += (65+i);
        list[s]=i+1;
    }
    
    // list["A"]=1;
    // list["B"]=2;
    // list["C"]=3;
    // list["D"]=4;
    // list["E"]=5;
    // list["F"]=6;
    // list["G"]=7;
    // list["H"]=8;
    // list["I"]=9;
    // list["J"]=10;
    // list["K"]=11;
    // list["L"]=12;
    // list["M"]=13;
    // list["N"]=14;
    // list["O"]=15;
    // list["P"]=16;
    // list["Q"]=17;
    // list["R"]=18;
    // list["S"]=19;
    // list["T"]=20;
    // list["U"]=21;
    // list["V"]=22;
    // list["W"]=23;
    // list["X"]=24;
    // list["Y"]=25;
    // list["Z"]=26;
    
    string now="";
    for(int i=0; i<msg.size(); i++){
        if(list.find(now+msg[i])!=list.end()){
            now+=msg[i];
        }            
        else{
            list[now+msg[i]]=cnt++;
            answer.push_back(list[now]);
            now="";
            i--;
        }
    }
    answer.push_back(list[now]);
    
    return answer;
}