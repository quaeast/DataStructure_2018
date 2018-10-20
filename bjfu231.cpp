//bjfu231
#include <iostream>
using namespace std;

typedef struct Node{
    int elem;
    struct Node *next;
}Node,*List;

void getList(List &head, int n){
    head = new Node;
    head->next = NULL;
    Node *j=head;
    for (int i = 0; i < n; ++i) {
        Node *temp;
        temp = new Node;
        temp->next=NULL;
        cin>>temp->elem;
        j->next=temp;
        j=j->next;
    }
}

void showList(List head){
    Node *temp = head->next;
    while (temp){
        cout<<temp->elem;
        if (temp->next!=NULL){
            cout<<' ';
        }
        temp = temp->next;
    }
    cout<<endl;
}

void reserveList(List &lis){
    if (lis->next==NULL||lis->next->next==NULL) {
        return;
    }
    Node *pre=lis->next;
    Node *cur=pre->next;
    Node *temp=cur->next;
    while (cur->next) {
        cur->next=pre;
        pre=cur;
        cur=temp;
        temp=cur->next;
    }
    cur->next=pre;
    lis->next->next=NULL;
    lis->next=cur;
}



int main() {
    int n;
    while (cin>>n){
        if(n==0){
            break;
        }
       List lib;
       getList(lib, n);
       reserveList(lib);
       showList(lib);
    }
    return 0;
}