#include<iostream>
#include<cmath>
using namespace std;
int N;
double A[100][100];
double L[100][100];
double U[100][100];
void start(void);
void mat_cal(void){
    
}
int main(void){
    while(1){
        start();
        mat_cal();


        bool op=1;
        cout<<"exit?(1 or 0) : ";
        cin>>op;
        if(op)return 0;
    }
}
void start(void){
    while(1){
        cout<<"N*N matrix(N<=50)\n";
        cout<<"N ? : ";
        cin>>N;
        if(N<=50)break;
    }
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        cout<<"A_"<<i+1<<" "<<j+1<<"? : ";
        cin>>A[i][j];
    }
    
    cout<<"your mat\n";
    for(int i=0;i<N;i++){
        cout<<"| ";
        for(int j=0;j<N;j++){    
            cout<<A[i][j]<<" ";
        }    
        cout<<"|";
        cout<<"\n";
    }
    cout<<"\n\nrunning..\n\n\n";
}