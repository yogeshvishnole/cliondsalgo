#include<iostream>
using namespace std;

int main(){

    int k;
    cin>>k;
    string s;
    cin>>s;
    int q;
    cin>>q;

    int slength = s.length();
    int n = (1<<k);

    pair<int,char> arr[n+slength];
    int tal = n + slength;

    for(int i = slength;i<tal;i++){
        arr[i].first = 1;
    }

    int in = 0;
    for(int i = k-1;i>=0;i--){
        int si = (1<<i)-1;
        int it = (1<<i);
        while(it--){
            int lci = 2*si + 1;
            int rci = lci + 1;
            if(s[in] == '1'){
                arr[si].first  =  arr[rci].first;
            }else if(s[in] == '0'){
                arr[si].first  =  arr[lci].first;
            }else{
                arr[si].first  =  arr[lci].first + arr[rci].first;
            }
            arr[si].second = s[in];
            si++;
            in++;
        }
    }

    while(q--){

        int p;
        char c;
        cin>>p;
        cin>>c;

        int treeIndex;

        for(int i = k-1;i>=0;i--){
            int si = (1<<i);
            if(p<=si){
                treeIndex =  (si-1) + (p-1);
                break;
            }else{
                p-=(si);
            }
        }

        arr[treeIndex].second = c;

        while(treeIndex>=0){
            int lci = 2*treeIndex+1;
            int rci = lci + 1;

            if(arr[treeIndex].second == '1'){
                arr[treeIndex].first = arr[rci].first;
            }else if(arr[treeIndex].second == '0'){
                arr[treeIndex].first = arr[lci].first;
            }else{
                arr[treeIndex].first = arr[lci].first + arr[rci].first;
            }
            if(treeIndex>0){
                treeIndex = (treeIndex-1)/2;
            }else{
                treeIndex--;
            }

        }
        cout<<arr[0].first<<endl;

    }


}