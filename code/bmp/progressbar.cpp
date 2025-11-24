#include <iostream>
#include <iomanip>
int main(){
std::cout << " 0";
long long  max= 100000000;
long long step=1000000;
long l=0;
for(long long i=0;i<max+1;i++){
    
    for(int j=0;j<10;j++){
        l=l*l;
    }
    if (i%step==0){
        std::cout << "\b\b";
        std::cout << std::setprecision(2) << i*100/max ;
        std::cout.flush();
    }
}

return l;

}