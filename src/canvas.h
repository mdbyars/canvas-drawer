#ifndef canvas_H_
#define canvas_H_

#include <string>
#include <vector>
#include "ppm_image.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::max

namespace agl
{
    //use this for bool instead primitave type myType 
    //mytype = lines... etc 
   enum PrimitiveType {UNDEFINED, LINES, TRIANGLES};
   class canvas
   {
   public:
      canvas(int w, int h);
      virtual ~canvas();

      // Save to file
      void save(const std::string& filename);

      // Draw primitives with a given type (either LINES or TRIANGLES)
      // For example, the following draws a red line followed by a green line
      // begin(LINES);
      //    color(255,0,0);
      //    vertex(0,0);
      //    vertex(100,0);
      //    color(0,255,0);
      //    vertex(0, 0);
      //    vertex(0,100);
      // end();
      void begin(PrimitiveType type);
      void end();

      // Specifiy a vertex at raster position (x,y)
      // x corresponds to the column; y to the row
      void vertex(int x, int y);

      // Specify a color. Color components are in range [0,255]
      void color(unsigned char r, unsigned char g, unsigned char b);

      // Fill the canvas with the given background color
      void background(unsigned char r, unsigned char g, unsigned char b);

      float getArea(int x1, int y1, int x2, int y2, int x3, int y3);

      bool insideTri(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y);

   private:
      ppm_image _canvas;
      int height;
      int width;
      //ppm_image(h, w);
      bool inlines = false;
      //lines<int, int>;
      bool intri = false;
      int lines[2] = { -1, -1 };
      ppm_pixel currcolor;
      int triangles[6] = { -1, -1, -1, -1, -1, -1 };


   };
}

#endif


