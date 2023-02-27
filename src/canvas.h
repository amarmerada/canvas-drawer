/*-----------------------------------------------
 * Author:
 * Date:
 * Description:
 ----------------------------------------------*/

#ifndef canvas_H_
#define canvas_H_

#include <string>
#include <vector>
#include "math.h"
#include <vector>
#include "image.h"

namespace agl
{
    enum PrimitiveType { FAN, ROSECURVE, CONCENTRIC, UNDEFINED, LINES, TRIANGLES, CIRCLES, CRESCENTR, CRESCENTL, GIBBOUSL, GIBBOUSR, SEMIR, SEMIL, PHASE, POLYGON, STAR};
    struct vertColor {
        int x;
        int y;
        Pixel color;
    };
    class Canvas
    {
    public:
        Canvas(int w, int h);
        virtual ~Canvas();

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

        void setRadius(int r);
        void drawCircles(vertColor c);

        // Specify a color. Color components are in range [0,255]
        void color(unsigned char r, unsigned char g, unsigned char b);

        // Fill the canvas with the given background color
        void background(unsigned char r, unsigned char g, unsigned char b);

        void drawLines();
        void drawTriangles();
        void border(int b);
        void secondColor(unsigned char r, unsigned char g, unsigned char c);
        void drawCrescentR(vertColor a);
        void drawCrescentL(vertColor a);
        void drawGibbousR(vertColor a);
        void drawGibbousL(vertColor a);
        void drawSemiR(vertColor a);
        void drawSemiL(vertColor a);
        void generatePhases(vertColor a);
        void setSides(int n);
        void drawPolygon(vertColor a);
        void drawStar(vertColor a);
        void gradBackground(Pixel a, Pixel b, Pixel c, Pixel d);
        //if diag = true, 0,0 and max, max are the same color
        void gradBackground(Pixel a, Pixel b, bool column);
        void drawLine2(vertColor a, vertColor b);
        void drawUp(vertColor a, vertColor b);
        void drawDown(vertColor a, vertColor b);
        int getWidth();
        int getHeight();
        int getRadius();
        void drawRoseCurve(vertColor a);
        int getK();
        void setK(int k);
        void drawFan(vertColor a);
        void setAngle(int ang);


    private:
        Image _canvas;
        Pixel currentColor;
        PrimitiveType currentType;
        int radius = 0;
        int bwidth = 0;
        Pixel currentSecondary;
        int sides = 0;
        int k;
        int angle;


        float TriInterp(vertColor x, vertColor y, vertColor z);
 

    };
}

#endif