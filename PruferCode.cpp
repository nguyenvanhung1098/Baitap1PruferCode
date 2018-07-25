#include <iostream>
using namespace std;
#define max 100000

void Prufercode(int n,int prufer[2][max]){
    int i;
    int sumcon[max+1]={0}; //mang luu so con cua cac dinh theo thu tu dinh tang dan
    for(i=0;i<n;i++){
        sumcon[prufer[0][i]]++; //tinh so con cua cac dinh theo thu tu dinh tang dan
        sumcon[prufer[1][i]]++;
    }

    int conMin;
    int khoa[max]={0};// danh dau hang da in ra
    for(int j=0;j<n-1;j++){
        
        for(i=1;i<=n;i++){
            if(sumcon[i]==1){      //tim la bac 1 nho nhat;
                conMin=i;
                break;
            }
        }
        
        for(i=0;i<n;i++){
            if(khoa[i]==0){
                if(prufer[0][i]==conMin){
                    sumcon[prufer[0][i]]--;
                    sumcon[prufer[1][i]]--;	
                    cout<<prufer[1][i];
                    cout<<" ";
                    khoa[i]=1;
                    break;
            }
                if(prufer[1][i]==conMin){
                    sumcon[prufer[0][i]]--;	
                    sumcon[prufer[1][i]]--;
                    cout<<prufer[0][i];
                    cout<<" ";
                    khoa[i]=1;
                    break;
                }
            }
        }
    }
}

int main()
{
    int n;  // so canh cua cay
    int prufer[2][max];// mang luu canh cua cay
    
    cout << "Nhap so canh cua cay "<< endl;
    cin >>n;
    while(n<0){
        cout<<"Nhap lai n>0:";
        cin>> n;
    }
    
    int i;
    for (i=0;i<n;i++){
        cout <<"Nhap cap canh thu "<<i+1<<endl; // nhap canh cua cay
        cin >> prufer[0][i];
        cin>> prufer[1][i];
    }
    Prufercode(n,prufer);
    return 0;
}
