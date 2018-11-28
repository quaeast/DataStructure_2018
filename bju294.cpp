//bju294
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (1){
        vector<int> a;
        cin>>n;
        if (!n){
            break;
        }
        for (int i = 0; i < n; ++i) {
            int t;
            cin>>t;
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n-1; ++i) {
            cout<<a[i]<<' ';
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}