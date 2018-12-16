//quickSort
//
#include <iostream>
using namespace std;

const int len=5;

template <typename T, int N>
int classify(T (&array)[N], int big, int end){         //[]
    if(big==end){
        return big;
    }
    T t=array[big];
    while (big!=end){
        while (big!=end){
            if(array[end]<t){
                array[big]=array[end];
                break;
            }
            end--;
        }
        while (big!=end){
            if(array[big]>t){
                array[end]=array[big];
                break;
            }
            big++;
        }
    }
    array[end]=t;
    return end;
}



template <typename T, int N>
void quickSort(T (&array)[N], int big, int end){    //[]
    if(big>=end){
        return;
    }
    int min=classify(array, big, end);
    quickSort(array, big, min);
    quickSort(array, min+1, end);
}



int main() {
    int num;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        long n;
        cin>>n;
        long a[110];
        for (int j = 0; j < n; ++j) {
            cin>>a[j];
        }
        quickSort(a, 0, n-1);
        for (int j = 0; j < n; ++j) {
            cout<<a[j]<<endl;
        }
    }
    return 0;
}