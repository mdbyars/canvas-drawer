#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   canvas art = canvas(640, 380);
   art.background(225, 100, 0);
   art.save("new.ppm");

   // test line interpolation
   canvas drawer = canvas(640, 380);
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.color(255, 0, 255);
   drawer.vertex(0, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(100, 100);
   drawer.end();
   drawer.save("line-color-interpolation.ppm");
}

