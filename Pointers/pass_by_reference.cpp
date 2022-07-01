#include<iostream>
using namespace std;

//pass by value - here there is two seperate box income and money
// void applyTax(float money){
//     float tax = 0.10;
//     money = money - money*tax;

// }

//pass by reference using reference variable
//here money and income are the name of same box

void applyTax(float & money) {
    float tax = 0.10;
    money = money - money*tax;

}
int main(){

    float income;
    cin>>income;

    applyTax(income);
    cout<<income<<endl;
}