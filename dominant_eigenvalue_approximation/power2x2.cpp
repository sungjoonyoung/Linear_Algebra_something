#include<iostream>
#include<cmath>
using namespace std;
double A[2][2];
double X[2];
double eigenval=0;
int e=0;
void start(void);
double norm_cal(double x, double y){
    return sqrt(x*x+y*y);
}
void mat_cal(int op){
    // double tmp[2][2];
    // for(int i=0;i<2;i++)for(int j=0;j<2;j++){
    //     for(int k=0;k<2;k++){
    //         tmp[i][j]=A[i][k]*x[k];
    //     }
    // }
    // for(int i=0;i<2;i++)for(int j=0;j<2;j++)A[i][j]=tmp[i][j];
    double tmp[2]={0,0};
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            tmp[j]+=A[j][k]*X[k];
        }
    }
    
    eigenval=X[0]*tmp[0]+X[1]*tmp[1];
    double norm=norm_cal(tmp[0],tmp[1]);
    // cout<<"A"<<norm<<"\n";
    for(int i=0;i<2;i++)X[i]=tmp[i]/norm;
}
int main(void){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    while(1){
        start();
        for(int i=0;i<e;i++){
            mat_cal((i==e-1));
        }
        cout<<"eigen vector : ";
        cout<<X[0]<<", "<<X[1]<<"\n";
        cout<<"eigen value : ";
        cout<<eigenval<<"\n";
        bool op=1;
        cout<<"exit?(1 or 0) : ";
        cin>>op;
        if(op)return 0;
    }
}
void start(void){
    cout<<"only 2*2 matrix.\n";
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        cout<<"A_"<<i+1<<" "<<j+1<<"? : ";
        cin>>A[i][j];
    }
    for(int i=0;i<2;i++){
        cout<<"X_"<<i+1<<"? : ";
        cin>>X[i];
    }
    cout<<"how many iterate? : ";
    cin>>e;
    cout<<"your mat\n";
    for(int i=0;i<2;i++){
        cout<<"| ";
        for(int j=0;j<2;j++){    
            cout<<A[i][j]<<" ";
        }    
        cout<<"|";
        cout<<"\n";
    }
    cout<<"\n\nX is \n";
    for(int i=0;i<2;i++){
        cout<<X[i]<<", ";
    }
    cout<<"it will be "<<e<<"times.\n";
    cout<<"\n\nrunning..\n\n\n";
}