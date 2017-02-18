//
// Created by Stephen Clyde on 2/3/17.
//

#include "TriangleTester.h"

#include <iostream>
#include <cmath>

#include "../Triangle.h"
#include "../Utils.h"

void TriangleTester::testFirstConstructor()
{
    std::cout << "Execute TriangleTester::testConstructorWithStrings" << std::endl;

    Point** points = new Point*[3];
    points[0] = new Point(1,2,8);
    points[1] = new Point(3,1,4);
    points[2] = new Point(6,4,3);

    Triangle t(points);
    if (!t.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computerArea(), 9.35414, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t.computerArea() << std::endl;
        return;
    }

    const Point* p = t.getPoint(0);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8)
    {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4)
    {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3)
    {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testSecondConstructor()
{
    std::cout << "Execute TriangleTester::testSecondConstructor" << std::endl;

    // Write representative test cases for the Triangle's second constructor
    Point** points = new Point*[3];
    points[0] = new Point(3,1,4);
    points[1] = new Point(6,4,3);
    points[2] = new Point(1,2,8);

    Triangle t(points);
    if (!t.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computerArea(), 9.35414, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t.computerArea() << std::endl;
        return;
    }

    const Point* p = t.getPoint(0);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4)
    {
        std::cout << "Point 0 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3)
    {
        std::cout << "Point 1 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8)
    {
        std::cout << "Point 2 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }
}

void TriangleTester::testEquilateralTriangles()
{
    std::cout << "Execute TriangleTester::testEquilateralTriangles" << std::endl;

    std::string triangleStr = "-10,0,0|10,0,0|0,17.32050808,0";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='E')
    {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 173.205, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t1.computerArea() << std::endl;
        return;
    }

    //Write additional representative test cases equilateral triangles

    std::string triangleStr2 = "10,0,0|0,17.32050808,0|-10,0,0";
    Triangle t2(triangleStr2);
    if (!t2.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='E')
    {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 173.205, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }

}

void TriangleTester::testIsoscelesTriangles()
{
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;

    // Write representative test cases isosceles triangles

    std::string triangleStr = "10,0,0|0,33,0|-10,0,0";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='I')
    {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 330, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t1.computerArea() << std::endl;
        return;
    }

    std::string triangleStr2 = "-10,0,0|10,0,0|0,33,0";
    Triangle t2(triangleStr2);
    if (!t2.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='I')
    {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 330, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }
}

void TriangleTester::testScaleneTriangles()
{
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;

    // Write representative test cases scalene triangles
    std::string triangleStr = "1,0,0|3,4,5|2,3,4";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 1.870828693, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t1.computerArea() << std::endl;
        return;
    }

    std::string triangleStr2 = "3,4,5|2,3,4|1,0,0";
    Triangle t2(triangleStr2);
    if (!t2.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 1.870828693, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }

    std::string triangleStr3 = "1,1,0|3,0,5|0,0,0";
    Triangle t3(triangleStr3);
    if (!t3.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t3.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t3.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t3.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t3.computerArea(), 3.840572874, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t3.computerArea() << std::endl;
        return;
    }

    std::string triangleStr4 = "3,0,5|0,0,0|1,1,0";
    Triangle t4(triangleStr4);
    if (!t4.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t4.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t4.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t4.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t4.computerArea(), 3.840572874, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t4.computerArea() << std::endl;
        return;
    }

    std::string triangleStr5 = "1,2,8|3,1,4|6,4,3";
    Triangle t5(triangleStr5);
    if (!t5.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t5.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t5.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t5.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t5.computerArea(), 9.354143467, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t5.computerArea() << std::endl;
        return;
    }

    std::string triangleStr6 = "3,1,4|6,4,3|1,2,8";
    Triangle t6(triangleStr6);
    if (!t6.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t6.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t6.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t6.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t6.computerArea(), 9.354143467, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t6.computerArea() << std::endl;
        return;
    }

    std::string triangleStr7 = "2.3,5.25,25|12.25,2.4,40|12,8.3,3.2";
    Triangle t7(triangleStr7);
    if (!t7.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t7.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t7.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t7.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t7.computerArea(), 183.6929793, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t7.computerArea() << std::endl;
        return;
    }

    std::string triangleStr8 = "12.25,2.4,40|12,8.3,3.2|2.3,5.25,25";
    Triangle t8(triangleStr8);
    if (!t8.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t8.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t8.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t8.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t8.computerArea(), 183.6929793, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t8.computerArea() << std::endl;
        return;
    }
}

void TriangleTester::testNonTriangles()
{
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;

    // Write representative test cases non-triangles triangles
    std::string triangleStr = "0,0,0|1,1,1|2,2,2";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='N')
    {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 11.6913, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t1.computerArea() << std::endl;
        return;
    }

    std::string triangleStr2 = "3,3,3|4,4,4|5,5,5";
    Triangle t2(triangleStr2);
    if (!t2.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='N')
    {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t2.computerArea(), 11.6913, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }

}

void TriangleTester::testInvalid()
{
    std::cout << "Execute TriangleTester::testInvalid" << std::endl;

    // Write representative test cases invalid triangles
    std::string triangleStr = ".00023,.000525,0.00025|.0001225,0.00024,0.0004|0.00012,.00083,0.00032";
    Triangle t1(triangleStr);
    if (t1.isValid())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='X')
    {
        std::cout << "Triangle: unexpected type of "
                  << t1.getTriangleType() << std::endl;
        return;
    }
    if (!approximatelyEquals(t1.computerArea(), 180, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t1.computerArea() << std::endl;
        return;
    }
    std::string triangleStr2 = ".0001225,0.00024,0.0004|0.00012,.00083,0.00032|.00023,.000525,0.00025";
    Triangle t2(triangleStr2);
    if (t2.isValid())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly invalid" << std::endl;
        return;
    }

    if (!t2.isTriangle())
    {
        std::cout << "Failure to construct a triangle from 3 points; expectedly not a triangle" << std::endl;
        return;
    }

    if (t2.getTriangleType()!='X')
    {
        std::cout << "Triangle: unexpected type of "
                  << t2.getTriangleType() << std::endl;
        return;
    }
    if (!approximatelyEquals(t2.computerArea(), 180, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t2.computerArea() << std::endl;
        return;
    }

    std::string triangleStr3 = "A,B,C|What, is, this|is, not valid";
    Triangle t3(triangleStr3);
    if (!t3.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid " << std::endl;
        return;
    }

    if (!t3.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t3.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                  << t3.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t3.computerArea(), 9.354143467, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                  << t3.computerArea() << std::endl;
        return;
    }
}
