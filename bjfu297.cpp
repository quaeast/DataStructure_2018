//bjfu297
//
#include <iostream>
using namespace std;

void sort(int *a, int len){
    int j=0;
    for (int i = 0; i < len; ++i) {
        if(a[i]<0){
            int t=a[j];
            a[j]=a[i];
            a[i]=t;
            j++;
        }
    }
}
int main() {
    int n;
    while (cin>>n){
        if(n==0){
            break;
        }
        int a[200];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a, n);
        for (int i = 0; i < n-1; ++i) {
            cout<<a[i]<<' ';
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}