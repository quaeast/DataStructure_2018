//bjfu270
//
#include <iostream>
using namespace std;

typedef struct Node{
    char datum;
    struct Node *L;
    struct Node *R;
}Node,*BiTree;

int init(BiTree &root){
    char t;
    cin>>t;
    if(t=='0'){
        root=NULL;
        return 0;
    }
    root = new Node;
    root->datum=t;
    init(root->L);
    init(root->R);
    return 1;
}

void Pre(BiTree &root){
    if(root==NULL){
        return;
    }
    cout<<root->datum;
    Pre(root->L);
    Pre(root->R);
}

int One(BiTree &root){
    if(root==NULL){
        return 0;
    }
    return One(root->L)+One(root->R)+(root->L==NULL ^ root->R==NULL);
}

int Two(BiTree &root){
    if(root==NULL){
        return 0;
    }
    return Two(root->L)+Two(root->R)+(root->L!=NULL&&root->R!=NULL);
}

int Zero(BiTree &root){
    if(root==NULL){
        return 0;
    }
    return Zero(root->L)+Zero(root->R)+(root->L==NULL&&root->R==NULL);
}

int main() {
    while (1){
        BiTree root;
        if(init(root)==0){
            break;
        }
        cout<<Zero(root)<<' '<<One(root)<<' '<<Two(root)<<endl;
    }
    return 0;
}