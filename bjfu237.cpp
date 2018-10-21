//bjfu237
//
#include <iostream>
using namespace std;

typedef struct {
    int *data;
    int length;
}SqList;

void initSqList(SqList &l, int n){
    l.data=new int[200];
    l.length=n;
    for (int i = 0; i < n; ++i) {
        cin>>l.data[i];
    }
}

void showSqList(SqList &l){
    for (int i= 0; i < l.length-1; ++i) {
        cout<<l.data[i]<<' ';
    }
    cout<<l.data[l.length-1]<<endl;
}

int FindMid(SqList &l1, SqList &l2){
    int i=0,j=0;
    int temp;
    while (1){
        if (l1.data[i]<l2.data[j]){
            temp=l1.data[i];
            i++;
        } else{
            temp=l2.data[j];
            j++;
        }
        if(i+j==l1.length){
            //int nextTemp=min(l1.data[i],l2.data[j]);
            return temp;
        }
    }
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        SqList l1,l2;
        initSqList(l1, n);
        initSqList(l2, n);
        cout<<FindMid(l1, l2)<<endl;
    }
    return 0;
}