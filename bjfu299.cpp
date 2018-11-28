//bjfu299
//
#include <iostream>
using namespace std;
void count_sort(int *a, int len){
    int *b;
    b = new int[100];
    for (int i = 0; i < len; ++i) {
        int p=0;
        for (int j = 0; j < len; ++j) {
            if(a[j]<a[i]){
                p++;
            }
        }
        b[p]=a[i];
    }
    for (int i = 0; i < len-1; ++i) {
        cout<<b[i]<<' ';
    }
    cout<<b[len-1]<<endl;
}

int main() {
    int n;
    while (1){
        cin>>n;
        if (n==0){
            break;
        }
        int a[100];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        count_sort(a, n);
    }
    return 0;
}