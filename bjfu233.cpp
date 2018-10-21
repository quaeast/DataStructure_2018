//bjfu233
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
    struct Node *pre;
}Node,*List;

void initList(List &head, int n){
    head=new Node;
    head->next=NULL;
    head->pre=NULL;
    Node *cur=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        temp->next=NULL;
        temp->pre=cur;
        cin>>temp->datum;
        cur->next=temp;
        cur=cur->next;
    }
}

void transfer(List head, int n){  //transfer n and his next
    Node *pre=head;
    for (int j = 0; j < n+1; ++j) {
        pre=pre->next;
    }
    //cout<<pre->datum<<endl;
    Node *cur=pre->next;
    cur->pre=pre->pre;
    pre->pre->next=cur;
    pre->next=cur->next;
    cur->next=pre;
    pre->pre=cur;
}

void showList(List head){
    Node *cur=head->next;
    while (cur->next){
        cout<<cur->datum<<' ';
        cur=cur->next;
    }
    cout<<cur->datum<<endl;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        initList(lis, n);
        int pos;
        cin>>pos;
        transfer(lis, pos-2);
        showList(lis);
    }
    return 0;
}