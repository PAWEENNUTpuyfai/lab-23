#include<iostream>
#include<cstdlib>
using namespace std;
int main(int argc,char* argv[]){
    int sum=0,a;
    if(argc == 1){
        cout << "Please input numbers to find average."<< endl;
    }else{
        for(int i =1;i < argc;i++){
            a = atoi(argv[i]);
            sum += a;
        }
        cout << "---------------------------------" << endl ;
        cout << "Average of " << argc-1 <<" numbers = " << sum/(argc-1) << endl;
        cout << "---------------------------------"  ;
    }
   
}
