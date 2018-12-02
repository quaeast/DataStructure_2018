//bjfu292
//
#include <iostream>
using namespace std;

const int MaxSize=100;
const int len=13;

typedef struct Node{
    int datum;
    struct Node *next=NULL;
}Node,*Np;

typedef struct HushList{
    Np list[MaxSize];
    int key_num;
}HushList;

int H(int key){
    return key%13;
}

void BInsert(Np &head, int tar){
    Np t=head;
    while (t->next!=NULL){
        t=t->next;
    }
    Np temp=new Node;
    temp->datum=tar;
    t->next=temp;
}

void showList(Np &head){
    Np t=head;
    while (t->next!=NULL){
        cout<<' '<<t->next->datum;
        t=t->next;
    }
    cout<<endl;
}

int initHushList(HushList &list){
    cin>>list.key_num;
    if(list.key_num==0){
        return 0;
    }
    for (int i = 0; i < MaxSize; ++i) {
        list.list[i]=new Node;
    }
    for (int i = 0; i < list.key_num; ++i) {
        int t;
        cin>>t;
        BInsert(list.list[H(t)], t);
    }
    return 1;
}

void insertHush(HushList &l, int key){
    BInsert(l.list[H(key)],key);
}

void showHush(HushList &l){
    for (int i = 0; i < len; ++i) {
        cout<<i;
        showList(l.list[i]);
    }
}

int main() {
    while (1){
        HushList l;
        if(!initHushList(l)){
            break;
        }
        int key;
        cin>>key;
        insertHush(l,key);
        showHush(l);
    }
    return 0;
}