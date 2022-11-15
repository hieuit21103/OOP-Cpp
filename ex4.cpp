#include <iostream>
using namespace std;
class Staff{
public:
	char name[50];
	int yob,salary,days;
	Staff(){}
	~Staff(){}
	void in(){
		cout<<"Name=";
		fflush(stdin);
		cin.get(name,50);
		cout<<"Year of Birth=";
		cin>>yob;
		cout<<"Basic salary=";
		cin>>salary;
		cout<<"Days=";
		cin>>days;
	}
	void out(){
		cout<<"Name="<<name<<" ";
		cout<<"Year of Birth="<<yob<<" ";
		cout<<"Basic salary="<<salary<<" ";
		cout<<"Days="<<days<<endl;
	}
	int calculate(){
		return salary*days;
	}
};
class Salary_Table{
	int n;
	Staff data[255];
public:
	Salary_Table(){
		n=0;
	}
	~Salary_Table(){
		delete[] data;
	}
	Salary_table(int size){
		n=size;
	}
	void in(){
		int i;
		for(i=0;i<n;i++){
			data[i].in();
		}
	}
	void out(){
		int i;
		for(i=0;i<n;i++){
			data[i].out();
		}
	}
	void statistic(){
		int i;
		for(i=0;i<n;i++){
			if
		}
	}
};
int main(){
	return 0;
}
