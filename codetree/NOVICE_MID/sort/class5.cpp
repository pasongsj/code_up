#include <iostream>
#include <string>
using namespace std;

class Product{
    public:
        string name;
        int code;
        Product(string name = " ", int code = 0){
            this->name = name;
            this->code = code;
        }
};


int main(){
    Product prod1 = Product("codetree", 50);
    Product prod2;
    cin >> prod2.name >> prod2.code;

    cout << "product "<<prod1.code<<" is "<<prod1.name<<endl;
    cout << "product "<<prod2.code<<" is "<<prod2.name<<endl;
    return 0;
}
