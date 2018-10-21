//bjfu301
//
#include <iostream>
using namespace std;
const int Max=200;

typedef struct{
    int *data;
    int length;
}SqList;

void initSqList(SqList &l, int n){
    l.length=n;
    l.data=new int[Max];
    for (int i = 0; i < n; ++i) {
        cin>>l.data[i];
    }
}

void showSqList(SqList &l){
    for (int i = 0; i < l.length-1; ++i) {
        cout<<l.data[i]<<' ';
    }
    cout<<l.data[l.length-1]<<endl;
}

void leftShift(SqList &l){
    int t=l.data[0];
    for (int i = 0; i < l.length-1; ++i) {
        l.data[i]=l.data[i+1];
    }
    l.data[l.length-1]=t;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        SqList lis;
        initSqList(lis, n);
        int index;
        cin>>index;
        for (int i = 0; i < index; ++i) {
            leftShift(lis);
        }
        showSqList(lis);
    }
    return 0;
}