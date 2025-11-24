#include "bmp.hpp"
#include <iostream>
#include <time.h>


#include <sstream>
#include <vector>

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


void parseArgs(
    int argc, char* argv[],
    int &num_of_rectangle,
    int &border_width,
    std::string &filename,
    int &r, int &g, int &b
) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--num" && i + 1 < argc) {
            num_of_rectangle = std::stoi(argv[++i]);
        }
        else if (arg == "--border" && i + 1 < argc) {
            border_width = std::stoi(argv[++i]);
        }
        else if (arg == "--file" && i + 1 < argc) {
            filename = argv[++i];
        }
        else if (arg == "--color" && i + 1 < argc) {
            std::string col = argv[++i];
            std::stringstream ss(col);
            std::string item;
            std::vector<int> rgb;

            while (std::getline(ss, item, ',')) {
                rgb.push_back(std::stoi(item));
            }
            if (rgb.size() == 3) {
                r = rgb[0];
                g = rgb[1];
                b = rgb[2];
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Defaults
    int num_of_rectangle = 10;
    int border_width = 2;
    std::string filename = "out.bmp";
    int r = 100, g = 100, b = 100;

    // Call our parsing function
    parseArgs(argc, argv, num_of_rectangle, border_width, filename, r, g, b);


    BMP bmp(500, 500); 

    srand(static_cast<unsigned int>(time(0)));
    color c(r,g,b);
    for(int i=0;i<num_of_rectangle;i++){
        uint8_t x=rand()%500;
        uint8_t y=rand()%500;
        uint8_t l=rand()%500;
        uint8_t h=rand()%500;
        
        draw_rectangle(bmp,x,y,l,h,border_width,c);
    }
    
    bmp.write(filename);
   
    return 0;
}
