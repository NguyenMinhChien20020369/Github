#include <iostream>

using namespace std;

int main()
{
    char c='g';
    int a[]={2,6,47};
    char b[]={'c','u','e'};
    char d='d';
    cout<<(int*)&c<<" "<<(int*)&d<<endl;
    // Địa chỉ của c lớn hơn tất cả các địa chỉ của các biến khác.
    // Địa chỉ của d nhỏ hơn tất cả các địa chỉ của các biến khác.
    for(int i=0;i<3;i++){
        cout<<(int*)&a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<(void*)&b[i]<<" ";
    }
    //Địa chỉ của các phần tử liên tiếp nhau

    return 0;
}
