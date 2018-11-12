//bjfu267
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
    root=new Node;
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

int height(BiTree &root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->L),height(root->R))+1;
}

int flag;

void PreAll(BiTree &root, char *out, int len, int max){
    if(root==NULL){
        return;
    }
    out[len]=root->datum;
    len++;
    out[len]=0;
    if(root->L==NULL&&root->R==NULL&&len==max&&flag==0){
        cout<<out<<endl;
        flag=1;
        return;
    }
    PreAll(root->L, out, len, max);
    PreAll(root->R, out, len, max);
}

int main() {
    while (1){
        BiTree tree;
        if(!init(tree)){
            break;
        }
        int max = height(tree);
        char a[100];
        cout<<max<<endl;
        flag=0;
        PreAll(tree, a, 0, max);
    }
}