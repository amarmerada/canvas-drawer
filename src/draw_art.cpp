#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
	Canvas moonPhases(500, 500);

	moonPhases.background(85, 1, 130);
	Pixel f = Pixel{ 20, 0, 60 };
	Pixel e = Pixel{ 0, 40, 15 };
	moonPhases.gradBackground(f, e, false);

	moonPhases.end();
	moonPhases.begin(PHASE);
	moonPhases.border(0);
	moonPhases.secondColor(0, 0, 0);
	moonPhases.color(230, 250, 200);
	moonPhases.setRadius(25);
	moonPhases.vertex(250, 100);
	moonPhases.end();
	moonPhases.begin(ROSECURVE);
	moonPhases.color(200, 0, 100);
	moonPhases.secondColor(100, 0, 200);
	moonPhases.setK(10);
	moonPhases.vertex(100, 300);
	moonPhases.end();
	moonPhases.begin(ROSECURVE);
	moonPhases.color(0, 200, 100);
	moonPhases.setK(8);
	moonPhases.vertex(200, 300);
	moonPhases.end();
	moonPhases.begin(ROSECURVE);
	moonPhases.color(100, 200, 50);
	moonPhases.setK(6);
	moonPhases.setRadius(100);
	moonPhases.vertex(300, 300);
	moonPhases.end();
	moonPhases.save("moons2.png");

	Canvas polyTester(500, 600);
	polyTester.background(8, 23, 199);
	Pixel a = Pixel{ 240, 0, 0 };
	Pixel b = Pixel{ 0, 240, 0 };
	Pixel c = Pixel{ 0, 0, 240 };
	Pixel d = Pixel{ 0, 0, 0 };
	polyTester.gradBackground(a, b, c, d);
	polyTester.begin(POLYGON);
	polyTester.setRadius(80);
	polyTester.setSides(12);
	polyTester.color(0, 0, 0);
	polyTester.vertex(100, 100);
	polyTester.end();
	polyTester.begin(STAR);
	polyTester.setRadius(40);
	polyTester.setSides(12);
	polyTester.color(255, 255, 255);
	polyTester.vertex(300, 100);
	polyTester.end();
	polyTester.begin(POLYGON);
	polyTester.setRadius(90);
	polyTester.setSides(5);
	polyTester.color(0, 0, 0);
	polyTester.vertex(300, 300);
	polyTester.end();
	polyTester.begin(STAR);
	polyTester.setRadius(45);
	polyTester.setSides(5);
	polyTester.color(255, 255, 255);
	polyTester.vertex(100, 300);
	polyTester.end();
	polyTester.begin(POLYGON);
	polyTester.setRadius(90);
	polyTester.setSides(8);
	polyTester.color(0, 0, 0);
	polyTester.vertex(100, 500);
	polyTester.end();
	polyTester.begin(STAR);
	polyTester.setRadius(45);
	polyTester.setSides(8);
	polyTester.color(255, 255, 255);
	polyTester.vertex(300, 500);
	polyTester.end();
	polyTester.save("poly2.png");
}

