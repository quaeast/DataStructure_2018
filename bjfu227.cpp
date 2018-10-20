//bjfu227
//

#include <iostream>

using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void showList(List head){
    if(head->next==NULL){
        cout<<endl;
        return;
    }
    Node *cur=head->next;
    while (cur!=NULL){
        cout<<cur->datum;
        if(cur->next!=NULL){
            cout<<' ';
        }
        cur=cur->next;
    }
    cout<<endl;
}

void initList(List &head,int n) {
    head = new Node;
    head->next = NULL;
    Node *cur = head;
    for (int i = 0; i < n; ++i) {
        Node *temp = new Node;
        cin >> temp->datum;
        temp->next = NULL;
        cur->next = temp;
        cur = cur->next;
    }
}

void deleteList(List &head){
    Node *cur=head->next;
    Node *curPre=head;
    while (cur!=NULL){
        delete curPre;
        curPre=cur;
        cur=cur->next;
    }
}

List intersection(List &h1, List &h2){  //把t2和t1一样的插入到t2的前面
    Node *ins=new Node;
    ins->next=NULL;
    Node *t1=h1->next;
    Node *t2Pre=h2;
    while (t1){
        Node *w2Pre=t2Pre;
        Node *w2=t2Pre->next;
        while (w2){
            if(w2->datum==t1->datum){
                w2Pre->next=w2->next;
                w2->next=t2Pre->next;
                t2Pre->next=w2;
                t2Pre=t2Pre->next;
                break;
            }
            w2=w2->next;
            w2Pre=w2Pre->next;
        }
        t1=t1->next;
    }
    t2Pre->next=NULL;
    return h2;
}


int main() {
    int a,b;
    List l1,l2;
    while (cin>>a>>b){
        if(a==0&&b==0){
            break;
        }
        initList(l1, a);
        initList(l2, b);
        Node *c=intersection(l1, l2);
        //deWight(c);
        showList(c);
    }
    return 0;
}