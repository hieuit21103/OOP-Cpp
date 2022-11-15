#include <iostream>
using namespace std;
class Matrix{
public:
    int data[2][2];
    Matrix(){}
    ~Matrix(){}
    void in(){
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                cout<<"data["<<i<<"]["<<j<<"]=";
                cin>>data[i][j];
            }
        }
    }
    void out(){
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    int calculate(){
        int i,j,result;
        return result=data[0][0]*data[1][1]-data[0][1]*data[1][0];
    }
    Matrix operator+(Matrix mt2){
        Matrix mt3;
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                mt3.data[i][j]=data[i][j]+mt2.data[i][j];
            }
        }
        mt3.out();
        return mt3;
    }
    void pos(int num){
        int i,j,x,y;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                if (data[i][j]==num)
                {
                    /* code */
                    x=i;
                    y=j;
                }
            }
        }
        cout<<"Position="<<x<<":"<<y<<endl;
    }
};
int main(){
    Matrix mt1,mt2;
    mt1.in();
    mt1.out();
    mt2.in();
    mt2.out();
    mt1+mt2;
    return 0;
}