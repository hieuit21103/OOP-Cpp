#include <iostream>
#include <math.h>
using namespace std;
class Circle{
    int x,y;
    float radius;
public:
    Circle(){
        x=0;
        y=0;
        radius=0;
    }
    void in(){
        cout<<"Pos (x,y)=";
        cin>>x>>y;
        cout<<"Radius=";
        cin>>radius;
    }
    void out(){
        cout<<"Pos: ("<<x<<","<<y<<") ";
        cout<<"Radius="<<radius<<endl;
    }
    float area(){
        return M_PI*pow(radius,2);
    }
    bool check(int pos1,int pos2){
        if (x+radius < pos1+radius && y+radius < pos2+radius)
        {
            /* code */
            return true;
        }else{
            return false;
        }  
    }
};
void swap(Circle a, Circle b){
    Circle mid=a;
    a=b;
    b=mid;
}
int main(){
    int i,j,n,x,y;
    Circle *data;
    cin>>n;
    data = new Circle[n];
    for ( i = 0; i < n; i++)
    {   
        /* code */
        cout<<"Hinh tron thu "<<i<<endl;
        data[i].in();
    }
    for ( i = 0; i < n; i++)
    {
        /* code */
        cout<<"Hinh tron thu "<<i<<endl;
        data[i].out();
    }
    for ( i = n-1; i >= 0; i--)
    {  
        for ( j = 1; j <= i; j++)
        {
            if (data[j-1].area() < data[j].area())
            {
                /* code */
                swap(data[j-1],data[j]);    
            }
            
        }
    }
    cin>>x>>y;
    if(n <= 20){
        for(i=0;i<n;i++){
            if (data[i].check(x,y) == true)
            {
                /* code */
                data[i].out();
            }
        }
    }else{
        for ( i = 0; i < float(n/10); i++)
        {
            /* code */
            for(i=0;i<n;i++){
            if (data[i].check(x,y) == true)
            {
                /* code */
                data[i].out();
            }
        }
        }
        
    }
    return 0;
}