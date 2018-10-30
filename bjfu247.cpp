//bjfu247
//
#include <iostream>
using namespace std;

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        for (int i = 0; i < n-1; ++i) {
            int t;
            cin>>t;
            cout<<t<<' ';
        }
        int t;
        cin>>t;
        cout<<t<<endl;
    }
    return 0;
}