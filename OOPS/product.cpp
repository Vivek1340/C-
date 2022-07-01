#include<iostream>
#include<cstring>
using namespace std;

//Product (Shopping Cart)
class Product{
    int id;
    char name[100];
    int mrp;
    int selling_price;
    public:
    //constructor
    Product(){
        cout<<"inside constructor";
    }
    Product(int id,char *n,int mrp,int selling_price){

        this->id = id;
        this->mrp = mrp;
        this->selling_price = selling_price;
        strcpy(name , n);
    }
    Product(Product &x){
        id = x.id;
        strcpy(name,x.name);
        mrp = x.mrp;
        selling_price = x.selling_price;

    }
    //setters
    void setMrp(int price){
        if(price>0){
        mrp = price;
        }
    }
    void setSellingprice(int price){
         if(price>mrp){
            selling_price = mrp;
        }
        else {
            selling_price = price;
        }
    }

    //getters
    int getMrp(){
        return mrp;
    }
    int getSellingprice(){
        return selling_price;
    }

    void showDetails(){
        cout<<"Name : "<<name<<endl;
        cout<<"Id : "<<id<<endl;
        cout<<"Seling Price : " <<selling_price<<endl;
        cout<<"Mrp : "<<mrp<<endl;
        cout<<"--------------------"<<endl;
    }

};

int main(){
    Product camera(101 , "GoProHero9" , 28000 , 26000);
    Product webcam(camera);
    Product handycam = camera;

    camera.showDetails();
    webcam.showDetails();
    handycam.showDetails();

    //cout<<"MRP is : "<<camera.getMrp()<<endl;
    //cout<<"Selling Price is : "<<camera.getSellingprice()<<endl;

    return 0;
}