#include <iostream>
#include <cstring>
using namespace std;
class Product{
public:
	int id,iprice,price,amount;
	char name[50];
	Product(){
		id=0;
		iprice=0;
		price=0;
		amount=0
		strcopy(name,"");
	}
	~Product(){
	}
	void in(){
		cout<<"ID=";
		cin>>id;
		cout<<"Name=";
		fflush(stdin);
		cin.get(name,50);
		cout<<"Import Price=";
		cin>>iprice;
		cout<<"Saleprice=";
		cin>>price;
		cout<<"Amount=";
		cin>>amount;
	}
	void out(){
		cout<<"ID="<<id<<" ";		
		cout<<"Name="<<name<<" ";		
		cout<<"Import Price="<<iprice<<" ";		
		cout<<"Saleprice="<<price<<" ";		
		cout<<"Amount="<<amount<<" ";
		cout<<endl;
	}
	int profit(){
		return (price-iprice)*amount;
	}
	
};
void check(Product data[],int n){
	Product data1[100],mid;
	int x=0,i;
	for(i=0;i<n;i++){
		if(data[i].amount>5){
			data1[x]=data[i];
			x++;
		}
	}
	if(x==0) return;
	for(i=0;i<=x;++i){
		if(data[x].profit()<data[x+1].profit()){
			mid=data[x];
			data[x]=data[x+1];
			data[x+1]=mid;
		}
	}
	if(x<10){
		data[0].out();
	}else{
		float j=(float)x/10;
		for(i=0;i<j;i++){
			data[i].out();
		}
	}
}
int main(){
	Product data[100];
	int i,n,profit=0;
	cin>>n;
	for(i=0;i<n;i++){
		data[i].in();
	}
	for(i=0;i<n;i++){
		data[i].out();
		profit+=data[i].profit();
	}
	cout<<"Total Profit="<<profit<<endl;
	check(data,n);
	return 0;
}
