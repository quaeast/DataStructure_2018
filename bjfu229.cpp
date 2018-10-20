//bjfu229
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void initList(List &head, int n){
    head=new Node;
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

void showList(List &head){
    Node *temp=head->next;
    while (temp){
        cout<<temp->datum;
        if (temp->next!=NULL){
            cout<<' ';
        }
        temp=temp->next;
    }
    cout<<endl;
}

void divideList(List head, List &l1, List &l2){
    l2=new Node;
    l2->next=NULL;
    Node *pre=head;
    Node *cur=head->next;
    Node *t2=l2;
    while (cur){
        if (cur->datum>0){
            pre->next=cur->next;
            cur->next=NULL;
            t2->next=cur;
            t2=t2->next;
            cur=pre->next;
            continue;
        }
        cur=cur->next;
        pre=pre->next;
    }
    l1=head;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        List l1,l2;
        initList(lis, n);
        divideList(lis, l1, l2);
        showList(l1);
        showList(l2);
    }
    return 0;
}