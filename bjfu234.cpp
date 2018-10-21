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
    int deleteCount=0;
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i]==n){
            deleteCount++;
        } else{
            L.data[i-deleteCount]=L.data[i];
        }
    }
    L.length-=deleteCount;
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
