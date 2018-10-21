//bjfu234
//
#include <iostream>
using namespace std;

const int Max=500;

typedef struct{
    int *data;
    int length;
}SqList;

void initSq(SqList &L, int n){
    L.length=n;
    L.data=new int[Max];
    for (int i = 0; i < n; ++i) {
        cin>>L.data[i];
    }
};

void deleteN(SqList &L, int n){
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i]==n){
            --L.length;
            for (int j = i; j < L.length; ++j) {
                L.data[j]=L.data[j+1];
            }
            i--;
        }
    }
}

void showSq(SqList &L){
    for (int i = 0; i < L.length; ++i) {
        cout<<L.data[i];
        if(i<L.length-1){
            cout<<' ';
        }
    }
    cout<<endl;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        SqList lis;
        initSq(lis, n);
        int tar;
        cin>>tar;
        deleteN(lis, tar);
        showSq(lis);
    }
    return 0;
}