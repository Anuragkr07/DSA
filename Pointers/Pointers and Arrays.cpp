#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={10,20,30,40,50};
    
    cout<<" 4[arr] :   "<<4[arr]<<endl;    // same as arr[4]
    cout<<" *arr :     "<<*arr<<endl;
    cout<<" *arr + 1 : "<<*arr + 1<<endl;
    cout<<" *(arr)+2 : "<<*(arr)+2<<endl;
    cout<<" *(arr+2) : "<<*(arr+2)<<endl;
    cout<<endl;
    cout<<" &arr :     "<<&arr<<endl;
    cout<<" &arr[0] :  " <<&arr[0]<<endl;
    cout<<" arr :      "<<arr<<endl;
    
    
    /*
        *arr == *arr[0] == arr  i.e. the address of the first array element
    */
    
    cout<<endl;
    
    int *ptr=&arr[0];
    cout<<"sizeof(arr) : "<<sizeof(arr)<<endl;
    cout<<"sizeof(ptr) : "<<sizeof(ptr)<<endl;
    cout<<"sizeof(*ptr): "<<sizeof(*ptr)<<endl;
    
    cout<<endl;
    
    /* 
        ptr means the address of the first array element
       *ptr means the value present at that address which is a int.
       So the size comes out to be 4
    */
    
    cout<<"*ptr : "<<*ptr<<endl;
    cout<<" ptr : "<<ptr<<endl;
    cout<<"&ptr : "<<&ptr<<endl;
    
    cout<<endl;
    ptr=ptr+1;
    cout<<"after ptr+1 operation "<<endl;
    cout<<"*ptr : "<<*ptr;
    /*
        after ptr+1 operation, ptr stores the address of the next array element
    */
    return 0;
}