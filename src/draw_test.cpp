#include <iostream>
#include "canvas.h"

using namespace agl;
using namespace std;

void test_line(Canvas& drawer, int ax, int ay, int bx, int by, const std::string& savename)
{
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.vertex(ax, ay);
   drawer.vertex(bx, by);
   drawer.end();
   drawer.save(savename);
}

int main(int argc, char** argv)
{
   Canvas drawer(100, 100);

   drawer.color(255, 255, 255);

   printf("horizontal line: \n");
   test_line(drawer, 0, 50, 100, 50, "horizontal-line.png");
   printf("vertical line: \n");

   test_line(drawer, 50, 0, 50, 100, "vertical-line.png");
   printf("diagonal 1 line: \n");

   test_line(drawer, 0, 0, 100, 100, "diagonal-line-1.png");
   printf("height less than width 1: line: \n");

   test_line(drawer, 25, 10, 75, 25,  "h-lessthan-w-line-1.png");
   printf("width less than height 1 line: \n");

   test_line(drawer, 25, 25, 75, 75,  "w-lessthan-h-line-1.png");
   printf("diagonal 2 line: \n");

   test_line(drawer, 0, 100, 100, 0, "diagonal-line-2.png");
   printf("height less than width 2 line: \n");

   test_line(drawer, 25, 90, 75, 75,  "h-lessthan-w-line-2.png");

   printf("width less than height 2 line: \n");
   test_line(drawer, 25, 90, 75, 25,  "w-lessthan-h-line-2.png"); 

   // test line interpolation
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.color(255, 0, 255);
   drawer.vertex(0, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(100, 100);
   drawer.end();
   drawer.save("line-color-interpolation.png");
   printf("interp line\n");

   // test triangle with interpolation
   drawer.background(0, 0, 0);
   printf("here\n");
   drawer.begin(TRIANGLES);
   drawer.color(255, 0, 255);
   drawer.vertex(10, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(90, 50);
   drawer.color(255, 255, 0);
   drawer.vertex(10, 90);
   drawer.end();
   drawer.save("triangle.png");

   // test triangle with interpolation
   drawer.background(0, 0, 0);
   drawer.begin(TRIANGLES);
   drawer.color(255, 0, 255);
   drawer.vertex(10, 10);
   drawer.vertex(10, 90);
   drawer.vertex(90, 90);

   drawer.color(255, 255, 0);
   drawer.vertex(90, 90);
   drawer.vertex(90, 10);
   drawer.vertex(10, 10);
   drawer.end();
   drawer.save("quad.png");
   printf("saved\n");

   drawer.background(85, 1, 130);
   drawer.begin(CIRCLES);
   drawer.border(5);
   drawer.secondColor(0,0,0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("circle.png");

   drawer.background(85, 1, 130);
   drawer.begin(CRESCENTR);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("crescentR.png");

   drawer.background(85, 1, 130);
   drawer.begin(CRESCENTL);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("crescentL.png");

   drawer.background(85, 1, 130);
   drawer.begin(GIBBOUSL);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("gibbousL.png");

   drawer.background(85, 1, 130);
   drawer.begin(GIBBOUSR);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("gibbousR.png");

   drawer.background(85, 1, 130);
   drawer.begin(SEMIR);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("semiR.png");

   drawer.background(85, 1, 130);
   drawer.begin(SEMIL);
   drawer.border(5);
   drawer.secondColor(0, 0, 0);
   drawer.color(250, 2, 140);
   drawer.setRadius(25);
   drawer.vertex(50, 50);
   drawer.end();
   drawer.save("semiL.png");

   printf("here 7\n");
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
   moonPhases.save("moons.png");

   Canvas polyTester(500, 600);
   polyTester.background(8, 23, 199);
   Pixel a = Pixel{240, 0, 0};
   Pixel b = Pixel{ 0, 240, 0};
   Pixel c = Pixel{ 0, 0, 240 };
   Pixel d = Pixel{ 0, 0, 0 };
   polyTester.gradBackground(a,b,c,d);
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
   polyTester.save("poly.png");

   Canvas star(400, 400);
   star.background(0, 0, 0);
   star.color(255, 255, 255);
   star.setSides(8);
   star.setRadius(50);
   star.begin(STAR);
   star.vertex(200, 200);
   star.end();
   star.save("stars.png");

   Canvas rose(400, 400);
   rose.background(0, 0, 0);
   rose.color(255, 0, 0);
   rose.secondColor(0, 0, 255);
   rose.begin(ROSECURVE);
   rose.vertex(200, 200);
   rose.setRadius(75);
   rose.setK(8);
   rose.end();
   rose.save("rosecurve.png");

   

   return 0;
}
