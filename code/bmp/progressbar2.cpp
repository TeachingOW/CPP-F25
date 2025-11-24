#include <iostream>
#include <iomanip>
#include <iostream>
#include <iomanip>

void showProgressBar(size_t current, size_t total, size_t barWidth = 50) {
    if (total == 0) return;  // avoid division by zero

    float progress = static_cast<float>(current) / total;
    size_t pos = static_cast<size_t>(barWidth * progress);

    std::cout << "[";
    for (size_t i = 0; i < barWidth; ++i) {
        if (i < pos)        std::cout << "=";
        else if (i == pos)  std::cout << ">";
        else                std::cout << " ";
    }

    std::cout << "] " << std::setw(3) << int(progress * 100) << "%\r";
    std::cout.flush();
}


int main(){

long long  max= 100000000;
long long step=1000000;
long l=0;
for(long long i=0;i<max+1;i++){
    
    for(int j=0;j<50;j++){
        l=l*l;
    }
    if (i%step==0){
        showProgressBar(i,max);
    }
}

return l;

}