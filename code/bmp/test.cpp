#include "bmp.hpp"
#include <iostream>
#include <time.h>
void draw_rectangle(BMP &bmp,int x, int y, int l, int h, int b, color c ){
    for(int i=0;i<=l;i++){
        for(int ii=0;ii<=b;ii++){
        bmp.set_pixel(i+x, y+ii, c.r,c.g,c.b);
        bmp.set_pixel(i+x, y+h-ii, c.r, c.g,c.b);
        }
    }
    for(int j=0;j<=h;j++){
        for(int ii=0;ii<=b;ii++){
            bmp.set_pixel(x+ii, y+j, c.r,c.g,c.b);
            bmp.set_pixel(x+l-ii, y+j,c.r, c.g,c.b);
        }
    }
}

int main() {
    
    BMP bmp(500, 500); 
     srand(static_cast<unsigned int>(time(0)));
    color c(0,255,0);
    for(int i=0;i<5;i++){
        uint8_t x=rand()%500;
        uint8_t y=rand()%500;
        uint8_t l=rand()%500;
        uint8_t h=rand()%500;
        
        draw_rectangle(bmp,x,y,l,h,rand()%10,c);

    }
    
     draw_rectangle(bmp,1,1,500,500,10,color{255,0,0});

    bmp.write("rect.bmp"); // Save the image to a file

    return 0;
}
