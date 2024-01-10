#include <iostream>
using namespace std;
int main(){
    int x , y;
    cout << "Enter number of lines : ";
    cin >> x;
    cout << "Enter number of columns : ";
    cin >> y;
    int table[x][y];
    for(int i = 1 ; i <= x*2  + 1; i++){
        cout << endl;   

        if(i%2 != 1){

        
     
        for(int j = 1 ; j <= y*2 + 1 ; j++){
            if(j%2 == 1){
                if(j==1){
                cout << "|  ";
                }
                else{
                cout << "  |  ";
                }
            }
            else{
                cout << 0;
            }
        }
        // cout<<"\n";
        }
        else{
            for(int j = 1 ; j <= y*6 + 1 ; j++){
                cout << "-";

            } 
            // cout<<"\n";
        }

    }

}