using namespace std;

int solution(int n)
{
    int ans = 0;
    
    if(n==1) return 1;
    
    while(1){
        if(n%2==0) n/=2;
        else{
            while(n%2!=0){
                n--;
                ans++;
                if(n==1) break;
            }
        }
        if(n==1) break;
    }

    return ans+1;
}
