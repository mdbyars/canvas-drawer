#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   //canvas art = canvas(640, 380);
  // art.background(225, 100, 0);
 //  art.save("new.ppm");

   // test line interpolation
   canvas drawer = canvas(100, 100);
   drawer.background(225, 0, 100);
  // cout << "were here ~~~~~~~~~~~~~~~~";
   drawer.begin(TRIANGLES);
   drawer.color(0, 225, 0);
   drawer.vertex(2, 2);
  // drawer.color(0, 255, 255);
   drawer.vertex(10, 40);
   drawer.vertex(90, 90);
   drawer.begin(LINES);
   drawer.color(225, 0, 0);
   drawer.vertex(10, 10);
   drawer.vertex(100, 100);
   drawer.end();
   drawer.save("debug.ppm");
}

