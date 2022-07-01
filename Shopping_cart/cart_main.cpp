#include <iostream>
#include<vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProduct = {
    Product(1,"apple",26),
    Product(3,"mango",16),
    Product(2,"guava",36),
    Product(5,"banana",56),
    Product(4,"strawberry",29),
    Product(6,"pineapple",20),
};

Product* chooseProduct(){

    //Display the list of products
     string productList;
     cout<<" Available Products: "<<endl;

     for(auto product: allProduct){
        productList.append(product.getDisplayName());
     }
     cout<< productList <<endl;
     cout<<"--------------------------"<<endl;

     string choice;
     cin>>choice;


    for(int i=0 ; i<allProduct.size(); i++){
        if(allProduct[i].getShortName() == choice){
            return &allProduct[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}
bool checkout( Cart &cart){
if(cart.isEmpty()){
    return false;
}

int total = cart.getTotal();
cout<<" Pay in Cash "<<endl;

int paid;
cin>>paid;

if(paid>=total){
    cout<<"Change -> Rs. "<<paid - total <<endl;
    cout<<"Thank you for shopping";
    return true;
}
else{
    cout<<"Not enough Cash!";
    return false;
}

}

int main()
{
    char action;
    Cart cart;

    while(true){
        cout<<"Select an item -  (a)dd item, (v)iew cart, (c)heckout "<<endl;
        cin>>action;
        if(action== 'a'){
            //add to cart
            //view all products + choose product  + add to cart
            Product* product = chooseProduct();
            if(product != NULL){
                cout<<"Added to the cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }

        }
        else if(action == 'v'){
            //View the cart
     cout<<"--------------------------"<<endl;
     cout<<cart.viewCart();
     cout<<"--------------------------"<<endl;

        }
        else{
            //checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }


   return 0;
}