//bjfu266
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

void width(BiTree &root, int layer, int *ans){
    if(root==NULL){
        return;
    }
    ans[layer]++;
    layer++;
    width(root->R, layer, ans);
    width(root->L, layer, ans);
}


int main() {
    while (1){
        BiTree t;
        if(!init(t)){
            break;
        }
        int h=height(t);
        int ans[100];
        for (int i = 0; i < 100; ++i) {
            ans[i]=0;
        }
        width(t, 0, ans);
        int max = 0;
        for (int i = 0; i < h; ++i) {
            if(max<ans[i]){
                max = ans[i];
            }
        }
        cout<<max<<endl;
    }

    return 0;
}