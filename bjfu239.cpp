//bjfu239
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void CirList(List &head, int n){
    head = new Node;
    head->next=NULL;
    Node *cur=head;
    head->datum=1;
    for (int i = 1; i < n; ++i) {
        Node *temp=new Node;
        if(i==n-1){
            temp->next=head;
        } else{
            temp->next=NULL;
        }
        temp->datum=i+1;
        cur->next=temp;
        cur=cur->next;
    }
}

void showList(List head){
    Node *cur=head;
    while (cur->next!=head){
        cout<<cur->datum<<' ';
        cur=cur->next;
    }
    cout<<cur->datum<<endl;
}

Node* findPre(List head){
    Node *cur=head;
    while (cur->next!=head){
        cur=cur->next;
    }
    return cur;
}

void findKing(List head, int n){
    Node *cur=head;
    while (cur->next!=cur){
        for (int i = 0; i < n-1; ++i) {
            cur=cur->next;
        }
        Node *pre;
        pre=findPre(cur);
        cout<<cur->datum<<' ';
        pre->next=cur->next;
        //delete cur;
        cur=pre->next;
    }
    cout<<cur->datum<<endl;
}

int main() {
    int n,s;
    while (cin>>n>>s){
        if (n==0&&s==0){
            break;
        }
        List lis;
        CirList(lis, n);
        //showList(lis);
        findKing(lis, s);
    }
    return 0;
}