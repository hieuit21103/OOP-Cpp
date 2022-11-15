#include <iostream>
using namespace std;
class Vector{
	int n;
	float data[255];
public:
	Vector(){
		n=0;
	}
	Vector(int size){
		n=size;
	}
	~Vector(){
	}
	void in(){
		for(int i=0;i<n;i++){
			cout<<"data["<<i<<"]=";
			cin>>data[i];
		}
	}
	void out(){
		for(int i=0;i<n;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	Vector summary(Vector v2){
		Vector v3(n);
		for(int i=0;i<n;i++){
			v3.data[i]=data[i]+v2.data[i];
		}
		return v3;
	}
	Vector multiple(Vector v2){
		Vector v3(n);
		for(int i=0;i<n;i++){
			v3.data[i]=data[i]*v2.data[i];
		}
		return v3;
	}
	int pos(float number){
		for (int i = 0; i < n; ++i)
		{
			if (data[i]==number)
			{
				return i;
			}
		}
	}
};
int main(){
	Vector v1(2),v2(2);
	v1.in();
	v1.out();
	v2.in();
	v2.out();
	v1.summary(v2).out();
	v1.multiple(v2).out();
	return 0;
}
