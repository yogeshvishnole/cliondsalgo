#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s[4];
        for(int i = 0;i<4;i++){
            cin>>s[i];
        }
        int finalist1 = max(s[0],s[1]);
        int finalist2 = max(s[2],s[3]);

        int minFinalist = min(finalist1,finalist2);
        int maxFinalist = max(finalist1,finalist2);

        int i;
        for( i = 0;i<4;i++){
            if(s[i] > minFinalist && s[i]<maxFinalist ){
                cout<<"NO"<<"\n";
                break;
            }
        }

        if(i>=4){
            cout<<"YES"<<"\n";
        }

    }
}