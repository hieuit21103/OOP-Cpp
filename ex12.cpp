#include <iostream>
using namespace std;
#define car "O to nhap khau "
#define houseware "Do gia dung nhap khau "
#define machine "May moc nhap khau "
class Product{
protected:
    char name[50];
    int id;
    float nhap,xuat,thue;
    int categories;
public:
    Product(){
        id=0;
        nhap=0;
        xuat=0;
    }
    ~Product(){}
    void setCategory(int num){
        this->categories=num;
    }
    float calculate_fee(){
        switch (this->categories)
        {
        case 1:
            this->thue=0.1;
            break;
        case 2:
            this->thue=0.3;
            break;
        case 3:
            this->thue=0.12;
            break;
        default:
            cout<<"Error";
            break;
        }
        return this->nhap*this->thue;
    }
    float calculate_profit(){
        return this->xuat-(this->nhap+this->calculate_fee());
    }
    void in(){
        cout<<"Ma san pham:"; cin>>id;
        cout<<"Ten san pham:"; fflush(stdin); cin.get(name,50);
        cout<<"Gia nhap:"; cin>>nhap;
        cout<<"Gia ban:"; cin>>xuat;
    }
    void out(){
        cout<<"Ma san pham:"<<id<<" "<<"Ten san pham:"<<name<<" "<<"Gia nhap:"<<nhap<<" "<<"Gia ban:"<<xuat<<" "<<"Tax:"<<this->calculate_fee()<<endl;
    }
};
int main(){
    int i,n,response,pos;
    float max=0;
    Product *list;
    cout<<"Nhap so luong san pham:";
    cin>>n;
    list = new Product[n];
    for(i=0;i<n;i++){
        cout<<"Chon loai mat hang: 1-"<<houseware<<"2-"<<car<<"3-"<<machine<<":";
        cin>>response;
        list[i].setCategory(response);
        list[i].in();
    }
    for(i=0;i<n;i++){
        list[i].out();
    }
    for(i=0;i<n;i++){
        if(list[i].calculate_profit()>max){
            max=list[i].calculate_profit();
            pos=i;
        }
    }
    list[pos].out();
    cout<<"Tien lai: "<<list[pos].calculate_profit();
    return 0;
}
