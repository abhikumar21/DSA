 #include<bits/stdc++.h> 

 using namespace std; 
int c = 3;

void func(int *ptr) {
    cout<<*ptr<<endl;
 }

 int main() {
    // int c = 5;
    // cout<<::c<<endl; // :: scope resolution operator (use global variable)
    
    // cout<<sizeof(34.4)<<endl;
    // cout<<sizeof(34.4f)<<endl;
    // cout<<sizeof(34.4F)<<endl;
    // cout<<sizeof(34.4l)<<endl;
    // cout<<sizeof(34.4L)<<endl;


    // ///////////////////////reference variable 
    // int x = 45;
    // int &y = x;
    // cout<<x<<endl;
    // cout<<y<<endl;


    ///////////////////////type casting
    // double b = 2.3;
    // cout<<a<<endl;

    // int a = static_cast<int> (b);  // compile time casting


    /////// dynamic_cast
    // it can be only used on class pointers or references
    //runtime (if casting fails, it returns a NULL value)


    ///// reinterpret_cast
    // to convert : pointer of one data type -> to pointer of another data type


    //////////const_cast
    //used to change the const behaviour of source pointer
    const int num1 = 34;
    const int *num2 = &num1;
    int *newVal = const_cast<int*> (num2);
    func(newVal);

    return 0;
 }

