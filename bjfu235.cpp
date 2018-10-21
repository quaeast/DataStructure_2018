//bjfu235
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void initList(List &head, int n){
    head = new Node;
    head->next=NULL;
    Node *cur=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        temp->next=NULL;
        cin>>temp->datum;
        cur->next=temp;
        cur=cur->next;
    }
}

void showList(List head){
    Node *cur=head->next;
    while (cur){
        cout<<cur->datum;
        if (cur->next!=NULL){
            cout<<' ';
        }
        cur=cur->next;
    }
    cout<<endl;
}

int findN(List head, int n){
    Node *cur=head->next;
    for (int i = 0; i < n; ++i) {
        cur=cur->next;
    }
    return cur->datum;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        initList(lis, n);
        //showList(lis);
        int tar;
        cin>>tar;
        cout<<findN(lis, n-tar)<<endl;
    }
    return 0;
}