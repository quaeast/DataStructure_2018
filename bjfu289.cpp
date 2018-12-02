//bjfu866
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    while (1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int t;
            cin>>t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        int p;
        cin>>p;
        for (int i = 0; i < a.size()-1; ++i) {
            if(a[i]>=p){
                cout<<a[i]<<' ';
            }
        }
        cout<<*(a.end()-1)<<endl;
    }
    return 0;
}