#include<iostream>
using namespace std; 
class Item{
private:
    static int count;
public:
    Item(){
        count++;
    }
    int getCount(){
        return count;
    }
    int* getCountAddress(){
        int* p=&count;
        return p;
    }

    ~Item() {  //same name as class, no return type, no input parameter
        cout<<"destruct"<<endl;
    }
};

int Item::count=0;

int main(){

    // Item b;
    Item *a = new Item(); //destructor is called manually
    delete a;

    // const int i = 8;
    
    int j = 4;
    const int* idx = &j;
    cout<<*(idx+2)<<endl;

    // Item objItem1;
    // Item objItem2;
    // cout<<objItem1.getCount()<<' ';
    // cout<<objItem2.getCount()<<' ';
}
