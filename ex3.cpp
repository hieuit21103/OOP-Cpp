#include <iostream>
#include <cstring>
using namespace std;
class Med
{
public:
	int id,amount,price;
	char name[50];
	Med(){
		id=0;
		amount=0;
		price=0;
		strcopy(name,"");
	}
	~Med(){}
	void in(){
		cout<<"ID=";
		cin>>id;
		cout<<"Name=";
		fflush(stdin);
		cin.get(name,50);
		cout<<"Amount=";
		cin>>amount;
		cout<<"Price=";
		cin>>price;
	}
	void out(){
		cout<<"ID="<<id<<" ";
		cout<<"Name="<<name<<" ";
		cout<<"Amount="<<amount<<" ";
		cout<<"Price="<<price<<" ";
		cout<<endl;
	}
};
void swap(Med a,Med b){
	Med mid=a;
	a=b;
	b=mid;
}
void sort(Med data[],int n){
	for (int i=n-1; i >=0; i--)
	{
		for(int j=1;j<=i;j++){
			if(strcmp(data[j-1].name,data[j].name) > 0){
				swap(data[j-1],data[j]);
			}else if(strcmp(data[j-1].name,data[j].name) == 0){
				if(data[j-1].id > data[j].id){
					swap(data[j-1],data[j]);
				}
			}
		}
	}
}
int main(){
	Med data[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		data[i].in();
	}
	for (int i = 0; i < n; ++i)
	{
		data[i].out();
	}
	sort(data,n);
	for (int i = 0; i < n; ++i)
	{
		data[i].out();
	}
	return 0;
}
