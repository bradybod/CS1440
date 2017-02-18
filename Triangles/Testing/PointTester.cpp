//
// Created by Stephen Clyde on 2/3/17.
//

#include <iostream>
#include <cmath>

#include "../Point.h"
#include "PointTester.h"

void PointTester::testConstructorWithDoubles()
{
    std::cout << "Execute PointTester::testConstructorWithDoubles" << std::endl;

    // Test 1st constructor by building 4 points
    Point p0(0,0,0);
    if (!p0.isValid() || p0.getX()!=0 || p0.getY()!=0 || p0.getZ()!=0)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p0.isValid()
                  << " x=" << p0.getX()
                  << " y=" << p0.getY()
                  << " z=" << p0.getZ()
                  << std::endl;
        return;
    }

    Point p1(1,2,3);
    if (!p1.isValid() || p1.getX()!=1 || p1.getY()!=2 || p1.getZ()!=3)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p2(2.235,43.2,0);
    if (!p2.isValid() || p2.getX()!=2.235 || p2.getY()!=43.2 || p2.getZ()!=0)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

    Point p3(2.235,43.2,0.00001);
    if (!p3.isValid() || p3.getX()!=2.235 || p3.getY()!=43.2 || p3.getZ()!=0.00001)
    {
        std::cout << "Failure in constructing Point(0,0,0) isValid()="
                  << p3.isValid()
                  << " x=" << p3.getX()
                  << " y=" << p3.getY()
                  << " z=" << p3.getZ()
                  << std::endl;
        return;
    }

}

void PointTester::testIsEquivalentTo()
{
    std::cout << "Execute PointTester::testIsEquivalentTo" << std::endl;

    Point p0(0,0,0);
    Point p1(1,2,3);
    Point p2(2.235,43.2,0);
    Point p3(2.235,43.2,0.00001);

    // Test the equality of p0 with all four points
    if (!p0.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p0 and p0 -- should be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p0 and p1 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p0 and p2 -- should not be equal" << std::endl;
    }

    if (p0.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p0 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p1 with all four points
    if (p1.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p1 and p0 -- should not be equal" << std::endl;
    }

    if (!p1.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p1 and p1 -- should be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p1 and p2 -- should not be equal" << std::endl;
    }

    if (p1.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p1 and p3 -- should not be equal" << std::endl;
    }

    // Test the equality of p2 with all four points
    if (p2.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p2 and p0 -- should not be equal" << std::endl;
    }

    if (p2.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p2 and p1 -- should not be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p2 and p2 -- should be equal" << std::endl;
    }

    if (!p2.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p2 and p3 -- should be equal" << std::endl;
    }

    // Test the equality of p3 with all four points
    if (p3.isEquivalentTo(p0))
    {
        std::cout << "Failure in comparing p3 and p0 -- should not be equal" << std::endl;
    }

    if (p3.isEquivalentTo(p1))
    {
        std::cout << "Failure in comparing p3 and p1 -- should not be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p2))
    {
        std::cout << "Failure in comparing p3 and p2 -- should be equal" << std::endl;
    }

    if (!p3.isEquivalentTo(p3))
    {
        std::cout << "Failure in comparing p3 and p3 -- should be equal" << std::endl;
    }

}

void PointTester::testConstructorWithStrings()
{
    std::cout << "Execute PointTester::testConstructorWithStrings" << std::endl;

    Point p0(0,0,0);
    Point p1(1,2,3);
    Point p2(2.235,43.2,0);
    Point p3(2.235,43.2,0.00001);

    // TODO Test second constructor by creating for new points that should be the same as the previous four
    Point q0("0,0,0");
    if (!q0.isValid() || !q0.isEquivalentTo(p0))
    {
        std::cout << "Failure in constructing Point(\"0,0,0\") isValid()="
                  << q0.isValid()
                  << " x=" << q0.getX()
                  << " y=" << q0.getY()
                  << " z=" << q0.getZ()
                  << std::endl;
        return;
    }
    Point q1("1,2,3");
    if (!q1.isValid() || !q1.isEquivalentTo(p1))
    {
        std::cout << "Failure in constructing Point(\"1,2,3\") isValid()="
                  << q1.isValid()
                  << " x=" << q1.getX()
                  << " y=" << q1.getY()
                  << " z=" << q1.getZ()
                  << std::endl;
        return;
    }
    Point q2("2.235,43.2,0");
    if (!q2.isValid() || !q2.isEquivalentTo(p2))
    {
        std::cout << "Failure in constructing Point(\"2.235,43.2,0\") isValid()="
                  << q2.isValid()
                  << " x=" << q2.getX()
                  << " y=" << q2.getY()
                  << " z=" << q2.getZ()
                  << std::endl;
        return;
    }
    Point q3("2.235,43.2,0.00001");
    if (!q3.isValid() || !q3.isEquivalentTo(p3))
    {
        std::cout << "Failure in constructing Point(\"2.235,43.2,0.00001\") isValid()="
                  << q3.isValid()
                  << " x=" << q3.getX()
                  << " y=" << q3.getY()
                  << " z=" << q3.getZ()
                  << std::endl;
        return;
    }

    if (!q0.isEquivalentTo(q0))
    {
        std::cout << "Failure in comparing q0 and q0 -- should be equal" << std::endl;
    }

    if (q0.isEquivalentTo(q1))
    {
        std::cout << "Failure in comparing q0 and q1 -- should not be equal" << std::endl;
    }

    if (q0.isEquivalentTo(q2))
    {
        std::cout << "Failure in comparing q0 and q2 -- should not be equal" << std::endl;
    }

    if (q0.isEquivalentTo(q3))
    {
        std::cout << "Failure in comparing q0 and q3 -- should not be equal" << std::endl;
    }

    // Test the equality of q1 with all four points
    if (q1.isEquivalentTo(q0))
    {
        std::cout << "Failure in comparing q1 and q0 -- should not be equal" << std::endl;
    }

    if (!q1.isEquivalentTo(q1))
    {
        std::cout << "Failure in comparing q1 and q1 -- should be equal" << std::endl;
    }

    if (q1.isEquivalentTo(q2))
    {
        std::cout << "Failure in comparing q1 and q2 -- should not be equal" << std::endl;
    }

    if (q1.isEquivalentTo(q3))
    {
        std::cout << "Failure in comparing q1 and q3 -- should not be equal" << std::endl;
    }

    //  Test the equality of q2 with all four points
    if (q2.isEquivalentTo(q0))
    {
        std::cout << "Failure in comparing q2 and q0 -- should not be equal" << std::endl;
    }

    if (q2.isEquivalentTo(q1))
    {
        std::cout << "Failure in comparing q2 and q1 -- should not be equal" << std::endl;
    }

    if (!q2.isEquivalentTo(q2))
    {
        std::cout << "Failure in comparing q2 and q2 -- should be equal" << std::endl;
    }

    if (!q2.isEquivalentTo(q3))
    {
        std::cout << "Failure in comparing q2 and q3 -- should be equal" << std::endl;
    }

    // TODO Test the equality of p3 with all four points
    if (q3.isEquivalentTo(q0))
    {
        std::cout << "Failure in comparing q3 and q0 -- should not be equal" << std::endl;
    }

    if (q3.isEquivalentTo(q1))
    {
        std::cout << "Failure in comparing q3 and q1 -- should not be equal" << std::endl;
    }

    if (!q3.isEquivalentTo(q2))
    {
        std::cout << "Failure in comparing q3 and q2 -- should be equal" << std::endl;
    }

    if (!q3.isEquivalentTo(q3))
    {
        std::cout << "Failure in comparing q3 and q3 -- should be equal" << std::endl;
    }
    // TODO Write additional meaningful test cases for Point's string-based constructor

}

void PointTester::testInvalid() {
    std::cout << "Execute PointTester::testInvalid" << std::endl;
    // TODO Write meaningful test cases to check for invalid points

    Point p0("hi,there,you");
    Point p1(2.235,43.2,INFINITY);

    if (p0.isValid())
    {
        std::cout << "p0 is valid and should not be"
                  << p0.isValid()
                  << " x=" << p0.getX()
                  << " y=" << p0.getY()
                  << " z=" << p0.getZ()
                  << std::endl;
        return;
    }
    if (p1.isValid())
    {
        std::cout << "p1 is valid and should not be"
                  << p1.isValid()
                  << " x=" << p1.getX()
                  << " y=" << p1.getY()
                  << " z=" << p1.getZ()
                  << std::endl;
        return;
    }

}

