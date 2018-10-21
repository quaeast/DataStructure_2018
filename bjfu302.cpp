//bjfu302
//
#include <iostream>
using namespace std;

typedef struct {
    int *data;
    int length;
}SqList;

const int Hash=1000;

void initSqList(SqList &l, int n){
    l.data=new int[200];
    for (int i = 0; i < n; ++i) {
        cin>>l.data[i];
    }
    l.length=n;
}

void showList(SqList &l){
    for (int i = 0; i < l.length-1; ++i) {
        cout<<l.data[i]<<' ';
    }
    cout<<l.data[l.length-1]<<endl;
}

int findMain(SqList &l){
    int a[Hash];
    for (int i = 0; i < Hash; ++i) {
        a[i]=0;
    }
    for (int i = 0; i < l.length; ++i) {
        ++a[l.data[i]];
    }
    int max=a[0];
    int temp=0;
    for (int i = 1; i < Hash; ++i) {
        if(a[i]>max){
            max=a[i];
            temp=i;
        }
    }
    return max>(l.length/2)?temp:-1;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        SqList l;
        initSqList(l, n);
        //showList(l);
        cout<<findMain(l)<<endl;
    }
    return 0;
}