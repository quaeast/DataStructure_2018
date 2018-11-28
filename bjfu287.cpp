//bjfu287
//
#include <iostream>
using namespace std;

int Binary_Search(int *a, int low, int high, int tar){   //[]
    if(low>high){
        return 0;
    }
    int mid=(low+high)/2;
    if(a[mid]==tar){
        return 1;
    } else if(tar<a[mid]){
        return Binary_Search(a, low, mid-1, tar);
    } else{
        return Binary_Search(a, mid+1,high, tar);
    }
}

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        int a[200];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        int tar;
        cin>>tar;
        if (Binary_Search(a, 0, n-1, tar)){
            cout<<"YES"<<endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}