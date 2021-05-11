#include "canvas.h"
#include <cassert>
#include "ppm_image.h"
#include <algorithm>    // std::max
#include <iostream>     // std::cout


using namespace std;
using namespace agl;

//questions: how to set a global "next color" instead of specific pixels bc thats what we need right? 
//how will begin know what the next vertex being called is ? i think im having issues understanding scope 

canvas::canvas(int w, int h) : _canvas(w, h)
{
	//enu 
	int height = h;
	int width = w;
	ppm_image _canvas(h, w);
	bool inlines = false;
	int lines[2];
	lines[0] = -1;
	lines[1] = -1;
	int triangles[6] = { -1, -1, -1, -1, -1, -1 };
	bool intri = false;
	ppm_pixel currcolor;
	currcolor.b = 0;
	currcolor.g = 0;
	currcolor.r = 0;
	//cout << lines[1];

}

canvas::~canvas()
{
	int height = 0;
	int width = 0;
	ppm_image _canvas(0, 0);
	bool inlines = false;
	int lines[2] = { -1, -1 };
	//lines[0] = -1;
	//lines[1] = -1;
	int triangles[6] = { -1, -1, -1, -1, -1, -1 };
	bool intri = false;
	ppm_pixel currcolor;
	currcolor.b = 0;
	currcolor.g = 0;
	currcolor.r = 0;
	//cout << lines[1];
}

void canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
	if (type == LINES) {
		inlines = true;
	}

	if (type == TRIANGLES) {
		intri = true;
	}

}

void canvas::end()
{
	inlines = false;
	intri = false;
	lines[0] = -1;
	lines[1] = -1;
	//cout << lines[0];

	int triangles[6] = { -1, -1, -1, -1, -1, -1 };


}

void canvas::vertex(int x, int y)
{
	/*For assignment 2: I recommend using std::vector to store point information when the use calls vertex().Below is an example :
#include <vector>
	using namespace std;
	....
		int main(int argc, char** argv)
	{
		vector<int> values;
		values.push_back(1);
		values.push_back(10);
		for (inti = 0; i < values.size(); i++)
		{
			cout << values[i] << endl;
		}
		values[1] = 20;
		values.clear();

	}
	*/
	if (inlines) {
		//cout << lines[0];
		//if there has been no previous vertex, store this one 
		if (lines[0] == -1) {
			lines[0] = x;
			lines[1] = y;
			
			return;
		}
		else {
		//	cout << lines[0];
			//a place to store the given value to put it back in lines later 
			int tempx = x;
			int tempy = y;
			int x1 = x;
			int y1 = y;
			//get the previous vertex 
			int x0 = lines[0];
			int y0 = lines[1];
			//swap(x1, x);
			//swap(y1, y);
			//cout << tempx;
			int dx = x1 - x0;
			int dy = y1 - y0;
			cout << dy; 
			cout << dx;
			//checking if too steep 
			if (dy > dx) {

				swap(x1, y1);
				swap(x0, y0);
				dx = x1 - x0;
				dy = y1 - y0;
			}

			int v = 2 * dy - dx;
			//ppm_pixel col = ppm_pixel();
			//col.b = 225;
			//col.g = 225;
			//col.r = 225;

			while (x0 < x1) {
				if (v >= 0) {
				//	cout << currcolor.r;
					//cout << currcolor.g;
					_canvas.set(x0, y0, currcolor);
					y0 = y0 + 1;
					v = v + 2 * dy - 2 * dx;
				}
				else {
					_canvas.set(x0, y0, currcolor);
					v = v + 2 * dy;
				}
				x0 = x0 + 1;


			}

			lines[0] = tempx;
			lines[1] = tempy;
		}





	}


	if (intri) {
		if (triangles[0] == -1) {
			triangles[0] = x;
			triangles[1] = y;
			return;
		}
		else if (triangles[2] == -1) {
			triangles[2] = x;
			triangles[3] = y;
			return;
		}
		else if (triangles[4] == -1) {
			triangles[4] = x;
			triangles[5] = y;
			int x1 = triangles[0];
			int y1 = triangles[1];
			int x2 = triangles[2];
			int y2 = triangles[3];
			int x3 = triangles[4];
			int y3 = triangles[5];

			for (int i = 0; i < _canvas.height(); i++) {
				for (int j = 0; j < _canvas.width(); j++) {
					if (insideTri(x1, y1, x2, y2, x3, y3, i, j)) {
						cout << i << x1 ;
						_canvas.set(i, j, currcolor);
					}
				}
			}
			/*
			int maxx = std::max(x1, x2);
			maxx = std::max(maxx, x);
			int minx = std::min(x1, x2);
			minx = std::min(minx, x);

			int maxy = std::max(y1, y2);
			maxy = std::max(maxy, y);
			int miny = std::min(y1, y2);
			miny = std::min(miny, y);

			int v1x = x1 - x;
			int v1y = y1 - y;
			int v2x = x2 - x;
			int v2y = y2 - y;

			for (int i = minx; i <= maxx; i++) {
				for (int j = miny; y <= maxy; y++) {
					// i - x, j-y
					float currx = i - x;
					float curry = j - y;
					//float s = cross product of (currx, curry) x (v2x, v2y) / (v1x, v1y)x(v2x, v2y);
					//float t = (v1x, v1y) x (currx, curry) / (v1x, v1y)x(v2x, v2y);
					//check to see if we are in the triangle
					//if()
					int crossx;
				}
			}
			*/

		}

	}

}

float canvas::getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool canvas::insideTri(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	float a= getArea(x1, y1, x2, y2, x3, y3);
	float a1 = getArea(x, y, x2, y2, x3, y3);
	float a2 = getArea(x1, y1, x, y, x3, y3);
	float a3 = getArea(x1, y1, x2, y2, x, y);
	return (a == a1 + a2 + a3);
}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
	ppm_pixel colo = ppm_pixel();
	colo.b = b;
	colo.g = g;
	colo.r = r;
	//_canvas.set(1, 1, col);
	ppm_pixel currcolor = colo;

}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
	ppm_pixel colo = ppm_pixel();
	colo.b = b;
	colo.g = g;
	colo.r = r;
	for (int i = 0; i < _canvas.height() ; i++) {
		for (int j = 0; j < _canvas.width() ; j++) {
			_canvas.set(i, j, colo);
		}
	}
	//_canvas.set(1, 2, col);

}

