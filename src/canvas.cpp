#include "canvas.h"
#include <cassert>
#include "ppm_image.h"

using namespace std;
using namespace agl;

//questions: how to set a global "next color" instead of specific pixels bc thats what we need right? 
//how will begin know what the next vertex being called is ? i think im having issues understanding scope 

canvas::canvas(int w, int h) : _canvas(w, h)
{
	//enu 
	int height = h;
	int width = w;
	ppm_image(h, w);
	bool inlines = false;
	int lines[2] = { -1, -1 };
	bool intri = false;
	ppm_pixel currcolor;
	currcolor.b = 0;
	currcolor.g = 0;
	currcolor.r = 0;

}

canvas::~canvas()
{
	int height = 0;
	int width = 0;
	ppm_image(0, 0);

}

void canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
	if (type = LINES) {
		inlines = true;
	}

	if (type = TRIANGLES) {
		intri = true;
	}

}

void canvas::end()
{
	inlines = false;
	intri = false;

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
		if (lines[0] = -1) {
			lines[0] = x;
			lines[1] = y;
			return;
		}
		
		else {
			int x1 = lines[0];
			int y1 = lines[1];
			int dx = x1 - x;
			int dy = y1 - y;

			int v = 2 * dy - dx;
			//ppm_pixel col = ppm_pixel();
			//col.b = 0;
			//col.g = 0;
			//col.r = 0;
			while(x<x1){
				if (v >= 0) {
					_canvas.set(x, y, currcolor);
					y = y + 1;
					v = v + 1 * dy - 2 * dx;
				}
				else {
					_canvas.set(x, y, currcolor);
					v = v + 2 * dy;
				}
				x = x + 1;
			}
		}

		

	}

}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
	ppm_pixel col = ppm_pixel();
	col.b = b;
	col.g = g;
	col.r = r;
	//_canvas.set(1, 1, col);
	ppm_pixel currcolor = col;

}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
	ppm_pixel col = ppm_pixel();
	col.b = b;
	col.g = g;
	col.r = r;
	for (int i = 0; i < _canvas.height() - 1; i++) {
		for (int j = 0; j < _canvas.width() - 1; j++) {
			_canvas.set(i, j, col);
		}
	}
	//_canvas.set(1, 2, col);

}

