#include "canvas.h"
#include <cassert>
#include "image.h"
#include <vector>

using namespace std;
using namespace agl;


std::vector<vertColor> myVerticies;

Canvas::Canvas(int w, int h) : _canvas(w, h){
	Image image(w, h);
	this->_canvas = image;
}

Canvas::~Canvas()
{

}

void Canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void Canvas::begin(PrimitiveType type)
{
	this->currentType = type;
	printf("here 2 \n");
	if (myVerticies.size() != 0) {
		myVerticies.clear();
	}
}

void Canvas::end()
{
	if (this->currentType == LINES) {
		while (myVerticies.size() % 2 == 0 && myVerticies.size() != 0) {
			drawLines();
		}
	}
	else if (this->currentType == TRIANGLES) {
		while (myVerticies.size() % 3 == 0 && myVerticies.size() != 0) {
			drawTriangles();
		}
	}
	else {
		myVerticies.clear();
	}
}

void Canvas::vertex(int x, int y)
{
	struct vertColor vtx = vertColor{x, y, currentColor};
	myVerticies.push_back(vtx);
}

void Canvas::drawLines() {
	
		vertColor a = myVerticies.back();
		myVerticies.pop_back();
		vertColor b = myVerticies.back();
		myVerticies.pop_back();
		int H = b.y - a.y;
		int W = b.x - b.x;
		
		if (H == 0) {
			if (b.x > a.x) {
				for (int i = a.x; i <= b.x; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x - i, 2) + pow(a.y, 2)) / sqrt(pow(b.x -i, 2) + pow(b.y, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(i, a.y, shift);
				}
			}
			else {
				for (int i = b.x; i <= a.x; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x - i, 2) + pow(a.y, 2)) / sqrt(pow(b.x - i, 2) + pow(b.y, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(i, a.y, shift);
				}
			}
		}
		else if (W == 0) {
			if (b.y > a.y) {
				for (int i = a.y; i <= b.y; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x, 2) + pow(b.y - i, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(b.x, i, shift);
				}
			}
			else {
				for (int i = b.x; i <= a.x; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x, 2) + pow(b.y - i, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(b.x, i, shift);
				}
			}
		}
		else if (abs(W) > abs(H)) {
			if (b.y > a.y) {
				int x = a.x;
				int incr;
				if (W > 0) {
					incr = 1;
				}
				else {
					incr = -1;
					W = abs(W);
				}
				
				int F = 2 * (W - H);

				for (int i = a.y; i <= b.y; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x - x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x - x, 2) + pow(b.y - i, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(x, i, shift);
					if (F > 0) {
						x += incr;
						F += 2 * (W - H);
					}
					else {
						F += 2 * W;
					}
				}
			}
			else{
				struct vertColor hold = { a.x, a.y, a.color };
				a = b;
				b = hold;
				
				int x = a.x;
				int incr;
				if (W > 0) {
					incr = 1;
				}
				else {
					incr = -1;
					W = abs(W);
				}

				int F = 2 * W - H;

				for (int i = a.y; i <= b.y; i++) {
					Pixel shift;
					float interp = sqrt(pow(a.x - x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x - x, 2) + pow(b.y - i, 2));
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(x, i, shift);
					if (F > 0) {
						x += incr;
						F += 2 * (W - H);
					}
					else {
						F += 2 * W;
					}
				}
			}
		}
		else if(abs(H) > abs(W)){
			if (b.x > a.x) {
				int y = a.y;
				int incr;
				if (H > 0) {
					incr = 1;
				}
				else {
					incr = -1;
					W = abs(W);
				}

				int F = 2 * H - W;

				for (int i = a.x; i <= b.x; i++) {
					float interp = sqrt(pow(a.y - y, 2) + pow(a.x - i, 2)) / sqrt(pow(b.x - i, 2) + pow(b.y - y, 2));
					Pixel shift;
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(i, y, shift);
					if (F > 0) {
						y += incr;
						F += 2 * (H - W);
					}
					else {
						F += 2 * H;
					}
				}
			}
			else {
				struct vertColor hold = { a.x, a.y, a.color };
				a = b;
				b = hold;

				int y = a.y;
				int incr;
				if (H > 0) {
					incr = 1;
				}
				else {
					incr = -1;
					W = abs(W);
				}

				int F = 2 * H - W;

				for (int i = a.x; i <= b.x; i++) {
					float interp = sqrt(pow(a.y - y, 2) + pow(a.x - i, 2)) / sqrt(pow(b.x - i, 2) + pow(b.y - y, 2));
					Pixel shift;
					shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
					shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
					shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
					_canvas.set(i, y, shift);
					if (F > 0) {
						y += incr;
						F += 2 * (H - W);
					}
					else {
						F += 2 * H;
					}
				}
			}
		}
}

void Canvas::drawTriangles() {
	vertColor c = myVerticies.back();
	printf("INSIDE\n");
	myVerticies.pop_back();
	vertColor b = myVerticies.back();
	myVerticies.pop_back();
	vertColor a = myVerticies.back();
	myVerticies.pop_back();
	int xmax = max(max(a.x, b.x), c.x);
	int xmin = min(min(a.x, b.x), c.x);
	int ymax = max(max(a.y, b.y), c.y);
	int ymin = min(min(a.y, b.y), c.y);
	for (int i = ymin; i <= ymax; i++) {
		for (int j = xmin; j <= xmax; j++) {
			printf("%d, %d\n", i, j);
			struct vertColor currvtx = {i, j, currentColor};
			float alpha = TriInterp(currvtx, b, c) / TriInterp(a, b, c);
			float beta = TriInterp(currvtx, c, a) / TriInterp(b, c, a);
			float gamma = TriInterp(currvtx, a, b) / TriInterp(c, a, b);
			if (alpha > 0 && beta > 0 && gamma > 0) {
				Pixel hold;
				hold.r = (a.color.r * alpha) + (b.color.r * beta) + (c.color.r * gamma);
				hold.g = (a.color.g * alpha) + (b.color.g * beta) + (c.color.g * gamma);
				hold.b = (b.color.b * alpha) + (b.color.b * beta) + (c.color.b * gamma);
				_canvas.set(j, i, hold);
			}
		}
	}
}

float Canvas::TriInterp(vertColor a, vertColor b, vertColor c) {
	int funct = ((b.y - c.y) * a.x) + ((c.x - b.x) * a.y) + (b.x * c.y) - (c.x * b.y);
	float final = (float)funct;
	return final;
}

void Canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
	struct Pixel newColor = Pixel{ r,g,b };
	currentColor = newColor;

}

void Canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
	struct Pixel toFill = Pixel{ r,g,b };
	_canvas.fill(toFill);
}

