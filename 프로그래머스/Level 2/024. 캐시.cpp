#include <string>
#include <vector>
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    string city;
};

struct List{
    Node head, tail;
    
    static void link(Node* front, Node* back){
        front->next = back;
        back->prev = front;
    }
    
    void initialize(){
        link(&head, &tail);
    }
    
    void insert(Node* node){
        link(tail.prev, node);
        link(node, &tail);
    }
    
    static void erase(Node* node){
        link(node->prev, node->next);
    }

};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    List list;
    list.initialize();
    Node node[100000];
    
    int len = cities.size();
    int cnt =0;
    
    for(int i=0; i<len; i++){
        node[i].city=cities[i];
        for(int j=0; j<node[i].city.size(); j++) if(node[i].city[j]>='A' && node[i].city[j]<='Z') node[i].city[j]+='a'-'A';
        int add=5;
        
        int flag=0; // 중복 검사
        Node* temp = &(list.tail);
        for(int j=0; j<cnt; j++) {
            temp = temp->prev;
            if(temp->city==node[i].city){
                List::erase(temp);
                add=1;
                flag=1;
                cnt--;
                break;
            }
        }
        if(!flag && cnt==cacheSize && cacheSize!=0) List::erase(list.head.next); 
        if(cnt<cacheSize) cnt++;
        answer+=add;
        list.insert(node+i);
    }
    
    return answer;
}