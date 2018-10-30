//bjfu261
//
#include <iostream>
using namespace std;

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        int a[200];
        //memset(a, 0, sizeof(int)*200);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        int pos[200];
        int nag[200];
        //memset(pos, 0, sizeof(int)*200);
        //memset(nag, 0, sizeof(int)*200);
        int posL=0;
        int nagL=0;
        for (int i=0; i < n; ++i) {
            if(a[i]>0){
                pos[posL]=a[i];
                posL++;
            } else{
                nag[nagL]=a[i];
                nagL++;
            }
        }
        for (int i = 0; i < posL; ++i) {
            cout<<pos[i];
            if(i<posL-1){
                cout<<' ';
            }
        }
        if(posL>0&&nagL>0){
            cout<<' ';
        }
        for (int i = 0; i < nagL; ++i) {
            cout<<nag[i];
            if(i<nagL-1){
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}