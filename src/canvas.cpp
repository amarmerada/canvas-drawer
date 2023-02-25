#include "canvas.h"
#include <cassert>
#include "image.h"
#include <vector>

using namespace std;
using namespace agl;


std::vector<vertColor> myVerticies;

Canvas::Canvas(int w, int h) : _canvas(w, h) {
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
	if (myVerticies.size() != 0) {
		myVerticies.clear();
	}
}

void Canvas::secondColor(unsigned char r, unsigned char g, unsigned char b){
	struct Pixel newColor = Pixel{ r,g,b };
	currentSecondary = newColor;
}

void Canvas::border(int b) {
	bwidth = b;
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
	else if (this->currentType == POLYGON) {
		drawPolygon(myVerticies.back());
		myVerticies.pop_back();
	}
	else if(this->currentType == CIRCLES){
		while (myVerticies.size() != 0) {
			drawCircles(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == CRESCENTR) {
		while (myVerticies.size() != 0) {
			drawCrescentR(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == PHASE) {
		while (myVerticies.size() != 0) {
			generatePhases(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == CRESCENTL) {
		while (myVerticies.size() != 0) {
			drawCrescentL(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == STAR) {
		while (myVerticies.size() != 0) {
			drawStar(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == SEMIR) {
		while (myVerticies.size() != 0) {
			drawSemiR(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == SEMIL) {
		while (myVerticies.size() != 0) {
			drawSemiL(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == GIBBOUSL) {
		while (myVerticies.size() != 0) {
			drawGibbousL(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else if (this->currentType == GIBBOUSR) {
		while (myVerticies.size() != 0) {
			drawGibbousR(myVerticies.back());
			myVerticies.pop_back();
		}
	}
	else {

		myVerticies.clear();
	}
}

void Canvas::vertex(int x, int y)
{
	struct vertColor vtx = vertColor{ x, y, currentColor };
	myVerticies.push_back(vtx);
}


void Canvas::drawCircles(vertColor a) {
	printf("in circles\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width()-1;
	}

	for (int i = xmin; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i-a.x, 2 ) + pow(j-a.y, 2));
			if (bwidth > 0) {
				if (dist < (rad - bwidth)) {
					_canvas.set(j, i, currentColor);

				}
				else if (dist <= rad) {
					_canvas.set(j, i, currentSecondary);

				}
			}
			else {
				if (dist <= rad) {
					_canvas.set(j, i, currentColor);
				}
			}
		}
	}
}

void Canvas::drawCrescentR(vertColor a) {
	printf("in cresc r\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}

	for (int i = xmin; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
			float dist2 = sqrt(pow(i - (a.x - (radius / 3)),2) + pow(j - (a.y ), 2));
				float constant = 1.02956;
				if ((dist <= rad) && (dist2 >= rad*constant)) {
					_canvas.set(j, i, currentColor);
				}
			
		}
	}
}

void Canvas::drawCrescentL(vertColor a) {
	printf("in cresc L\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}

	for (int i = xmin; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
			float dist2 = sqrt(pow(i - (a.x + (radius / 3)), 2) + pow(j - (a.y ), 2));
			float constant = 1.02956;
			if ((dist <= rad) && (dist2 >= rad * constant)) {
				_canvas.set(j, i, currentColor);
			}

		}
	}
}

void Canvas::drawGibbousL(vertColor a) {
	printf("in gibb L\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}

	for (int i = xmin; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
			float dist2 = sqrt(pow(i - (a.x - (radius / 3)), 2) + pow(j - (a.y ), 2));
			float constant = 1.02956;
			if ((dist <= rad) && (dist2 < rad * constant)) {
				_canvas.set(j, i, currentColor);
			}

		}
	}
}

void Canvas::drawGibbousR(vertColor a) {
	printf("in gibb L\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}
	for (int i = xmin; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
			float dist2 = sqrt(pow(i - (a.x + (radius / 3)), 2) + pow(j - (a.y ), 2));
			float constant = 1.02956;
			if ((dist <= rad) && (dist2 < rad * constant)) {
				_canvas.set(j, i, currentColor);
			}

		}
	}
}

void Canvas::drawSemiR(vertColor a) {
	printf("in semi R\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}

	for (int i = a.x; i < xmax; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
				if (dist < rad) {
					_canvas.set(j, i, currentColor);
				}
		}
	}
}

void Canvas::drawSemiL(vertColor a) {
	printf("in semi L\n");
	int rad = this->radius;
	int ymin = a.y - rad;
	if (ymin < 0) {
		ymin = 0;
	}
	int ymax = a.y + rad;
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int xmin = a.x - rad;
	if (xmin < 0) {
		xmin = 0;
	}
	int xmax = a.x + rad;
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}

	for (int i = xmin; i < a.x; i++) {
		for (int j = ymin; j < ymax; j++) {
			float dist = sqrt(pow(i - a.x, 2) + pow(j - a.y, 2));
			if (dist < rad) {
				_canvas.set(j, i, currentColor);
			}
		}
	}
}

void Canvas::generatePhases(vertColor a) {
	vertColor b = vertColor{  a.x - (6 * radius),a.y,  a.color };
	drawCrescentL(b);
	vertColor c = vertColor{ a.x - (4 * radius), a.y,  a.color };
	drawSemiL(c);
	vertColor d = vertColor{ a.x - (2 * radius), a.y,  a.color };
	drawGibbousL(d);
	drawCircles(a);
	vertColor e = vertColor{ a.x + (2 * radius), a.y,  a.color };
	drawGibbousR(e);
	vertColor f = vertColor{ a.x + (4 * radius), a.y,  a.color };
	drawSemiR(f);
	vertColor g = vertColor{ a.x + (6 * radius), a.y, a.color };
	drawCrescentR(g);

}

void Canvas::setRadius(int r) {
	this->radius = r;
}

void Canvas::drawLines() {

	vertColor a = myVerticies.back();
	myVerticies.pop_back();
	vertColor b = myVerticies.back();
	myVerticies.pop_back();
	int H = b.y - a.y;
	int W = b.x - a.x;
	printf("INITIAL: a.x: %d a.y: %d b.x: %d  b.y: %d  H: %d  W: %d\n", a.x, a.y, b.x, b.y, H, W);
	
	if (H == 0) {
		if (b.x > a.x) {
			for (int i = a.x; i <= b.x; i++) {
				Pixel shift;
				float interp = sqrt(pow(a.x - i, 2) + pow(a.y, 2)) / sqrt(pow(b.x - i, 2) + pow(b.y, 2));
				shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
				shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
				shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
				_canvas.set(a.y, i, shift);
			}
		}
		else {
			for (int i = b.x; i <= a.x; i++) {
				Pixel shift;
				float interp = sqrt(pow(a.x - i, 2) + pow(a.y, 2)) / sqrt(pow(b.x - i, 2) + pow(b.y, 2));
				shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
				shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
				shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
				_canvas.set(a.y, i, shift);
			}
		}
	}
	else if (W == 0) {
		printf("w = 0 called\n");
		if (b.y > a.y) {
			for (int i = a.y; i <= b.y; i++) {
				Pixel shift;
				float interp = sqrt(pow(a.x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x, 2) + pow(b.y - i, 2));
				printf("b.x: %d, i: %d\n", b.x, i);
				shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
				shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
				shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
				_canvas.set(i, b.x, shift);
			}
		}
		else {
			for (int i = b.y; i <= a.y; i++) {
				Pixel shift;
				float interp = sqrt(pow(a.x, 2) + pow(a.y - i, 2)) / sqrt(pow(b.x, 2) + pow(b.y - i, 2));
				shift.r = a.color.r * (1 - interp) + b.color.r * (interp);
				shift.g = a.color.g * (1 - interp) + b.color.g * (interp);
				shift.b = a.color.b * (1 - interp) + b.color.b * (interp);
				_canvas.set(i, b.x, shift);
			}
		}
	}else if ((H / W) == 1) {
		if (H > 0) {

		}
		else {

		}
	}
	else if (abs(W) > abs(H)) {
		printf("absW > absH\n");
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
		else {
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
	else if (abs(H) > abs(W)) {
		printf("absH > abs W\n");
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

	printf("a.x: %d b.x: %d c.x: %d\n", a.x, b.x, c.x);
	int xmax = max(max(a.x, b.x), c.x);
	if (xmax >= _canvas.width()) {
		xmax = _canvas.width() - 1;
	}
	int xmin = min(min(a.x, b.x), c.x);
	if (xmin < 0) {
		xmin = 0;
	}
	int ymax = max(max(a.y, b.y), c.y);
	if (ymax >= _canvas.height()) {
		ymax = _canvas.height() - 1;
	}
	int ymin = min(min(a.y, b.y), c.y);
	if (ymin < 0) {
		ymin = 0;
	}
	for (int i = xmin; i <= xmax; i++) {
		for (int j = ymin; j <= ymax; j++) {
			struct vertColor currvtx = { i, j, currentColor };
			float alpha = TriInterp(currvtx, b, c) / TriInterp(a, b, c);
			float gamma = TriInterp(currvtx, a, b) / TriInterp(c, a, b);
			float beta = 1 - alpha - gamma;
			if (i < 10) {
				printf("alpha: %f beta: %f gamma: %f\n", alpha, beta, gamma);

			}
			if (alpha >= 0 && beta >= 0 && gamma >= 0) {
				Pixel hold;
				hold.r = (a.color.r * alpha) + (b.color.r * beta) + (c.color.r * gamma);
				hold.g = (a.color.g * alpha) + (b.color.g * beta) + (c.color.g * gamma);
				hold.b = (b.color.b * alpha) + (b.color.b * beta) + (c.color.b * gamma);
				_canvas.set(j, i, hold);
			}
		}
	}
}

void Canvas::setSides(int num) {
	this->sides = num;
}

void Canvas::drawPolygon(vertColor a) {
	vector<vertColor> triVtx;
	//create them
	float helper = 6.283185;
	float helper2 = helper / (float)sides;
	float helper3 = helper2;
	for (int j = 0; j < sides; j++) {
		int localX = a.x + (radius * cos(helper3));
		int localY = a.y + (radius * sin(helper3));
		vertColor add = {localX, localY, a.color};
		triVtx.push_back(add);
		helper3 += helper2;
	}
	//draw them
	printf("trivtx size: %d\n", triVtx.size());
	for (int i = 0; i < triVtx.size(); i++) {
		vertex(triVtx[i].x, triVtx[i].y);
		vertex(triVtx[(i+1) % triVtx.size()].x, triVtx[(i + 1) % triVtx.size()].y);
		vertex(a.x, a.y);
		drawTriangles();
	}
}

void Canvas::drawStar(vertColor a) {
	vector<vertColor> triVtx;
	vector<vertColor> ptVtx;
	//create them
	float helper = 6.283185;
	float helper2 = helper / (float)sides;
	float helper3 = helper2;
	for (int j = 0; j < sides; j++) {
		int localX = a.x + (radius * cos(helper3));
		int localY = a.y + (radius * sin(helper3));
		vertColor add = { localX, localY, a.color };
		triVtx.push_back(add);
		helper3 += helper2;
	}

	float helper4 = helper2 / (float)2;
	for (int k = 0; k < sides; k++) {
		int localX = a.x + (radius *2* cos(helper4));
		int localY = a.y + (radius * 2 * sin(helper4));
		vertColor add = { localX, localY, a.color };
		ptVtx.push_back(add);
		helper4 += helper2;
	}
	//draw them
	printf("trivtx size: %d\n", triVtx.size());
	for (int i = 0; i < triVtx.size(); i++) {
		vertex(triVtx[i].x, triVtx[i].y);
		vertex(triVtx[(i + 1) % triVtx.size()].x, triVtx[(i + 1) % triVtx.size()].y);
		vertex(a.x, a.y);
		drawTriangles();
		vertex(triVtx[i].x, triVtx[i].y);
		vertex(triVtx[(i + 1) % triVtx.size()].x, triVtx[(i + 1) % triVtx.size()].y);
		int helper5 = (i + 2) % ptVtx.size();
		vertex(ptVtx[helper5].x, ptVtx[helper5].y);
		drawTriangles();
	}
	
}

void Canvas::gradBackground(Pixel a, Pixel b, Pixel c, Pixel d) {
	for (int i = 0; i < _canvas.width(); i++) {
		for (int j = 0; j < _canvas.height(); j++) {
			float hpc = (float)j / (float)_canvas.height();
			float wpc = (float)i / (float)_canvas.width();
			float pcnta = (1 - hpc)*(1-wpc);
			float pcntb = (1 - hpc)*(wpc);
			float pcntc = (hpc) * (1-wpc);
			float pcntd = (hpc * wpc);
			Pixel test;
			test.r = a.r * pcnta + b.r * pcntb + c.r * pcntc + d.r * pcntd;
			test.g = a.g * pcnta + b.g * pcntb + c.g * pcntc + d.g * pcntd;
			test.b = a.b * pcnta + b.b * pcntb + c.b * pcntc + d.b * pcntd;
			_canvas.set(j, i, test);
		}
	}
	
}
//if diag = true, 0,0 and max, max are both a
void Canvas::gradBackground(Pixel first, Pixel second, bool column) {
	Pixel a = first;
	Pixel b = second;
	Pixel d;
	Pixel c;
	if (column) {
		d = a;
		c = b;
	}
	else {
		d = second;
		c = d;
		b = a;
	}
	for (int i = 0; i < _canvas.width(); i++) {
		for (int j = 0; j < _canvas.height(); j++) {
			float hpc = (float)j / (float)_canvas.height();
			float wpc = (float)i / (float)_canvas.width();
			float pcnta = (1 - hpc) * (1 - wpc);
			float pcntb = (1 - hpc) * (wpc);
			float pcntc = (hpc) * (1 - wpc);
			float pcntd = (hpc * wpc);
			Pixel test;
			test.r = a.r * pcnta + b.r * pcntb + c.r * pcntc + d.r * pcntd;
			test.g = a.g * pcnta + b.g * pcntb + c.g * pcntc + d.g * pcntd;
			test.b = a.b * pcnta + b.b * pcntb + c.b * pcntc + d.b * pcntd;
			_canvas.set(j, i, test);
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