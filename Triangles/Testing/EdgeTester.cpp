//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges that are parallel with other
    Point p0(1,2,3);
    Point p1(2,4,6);
    Edge e1(&p0, &p1);

    Point p2(2,4,6);
    Point p3(4,8,12);
    Edge e2(&p0, &p1);

    if(!e1.isParallelTo(e2)){
        printf("Failure at testing parallel edges: Edges e1 and e2 are not parallel.\n");
    }
    Point p4(1.001,2.002,3.003);
    Point p5(2.002,4.004,6.006);
    Edge e3(&p4, &p5);

    Point p6(2.002,4.004,6.006);
    Point p7(4.004,8.008,12.0012);
    Edge e4(&p6, &p7);

    if(!e3.isParallelTo(e4)){
        printf("Failure at testing parallel edges: Edges e3 and e4 are not parallel.\n");
    }
    Point p8("1,2,3");
    Point p9("2,4,6");
    Edge e5(&p8, &p9);

    Point p10("2,4,6");
    Point p11("4,8,12");
    Edge e6(&p10, &p11);

    if(!e1.isParallelTo(e2)){
        printf("Failure at testing parallel edges: Edges e5 and e6 are not parallel.\n");
    }

}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges that are not parallel with other
    Point p0(1,2,3);
    Point p1(2,7,1);
    Edge e1(&p0, &p1);

    Point p2(2,4,6);
    Point p3(4,1,1);
    Edge e2(&p2, &p3);

    if(e1.isParallelTo(e2)){
        printf("Failure at testing NON parallel edges: Edges e1 and e2 are parallel.\n");
    }
    Point p4(1.001,2.002,3.003);
    Point p5(2.002,1.001,2.006);
    Edge e3(&p4, &p5);

    Point p6(2.002,4.004,6.006);
    Point p7(4.004,3.003,2.0012);
    Edge e4(&p6, &p7);

    if(e3.isParallelTo(e4)){
        printf("Failure at testing NON parallel edges: Edges e3 and e4 are parallel.\n");
    }
    Point p8("1,2,3");
    Point p9("2,1,2");
    Edge e5(&p8, &p9);

    Point p10("2,4,6");
    Point p11("4,3,12");
    Edge e6(&p10, &p11);

    if(e5.isParallelTo(e6)){
        printf("Failure at testing NON parallel edges: Edges e5 and e6 are parallel.\n");
    }
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges have a length of zero or approximately zero
    Point p1(1,1,1);
    Point p2(1,1,1);

    Edge e1(&p1, &p2);
    if((!e1.getLength()) == 0){
        printf("Failure at testing: e1 is not an edge.\n");
    }
    Point p3(1,1,1);
    Point p4(1.0001,1.0001,1.0001);

    Edge e2(&p3, &p4);
    if((!e2.getLength()) > 0.001){
        printf("Failure at testing: e2 is not an edge.\n");
    }
}

void EdgeTester::testBadEdges()
{
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;

    // TODO: Writing a representative set of test cases for edges not formed correctly
    Point p3(1,1,1);
    Point p4(1.0001,1.0001,1.0001);

    Edge e2(&p3, &p4);
    if((!e2.getLength()) > 0.001){
        printf("Failure at testing: e5 is not an edge.\n");
    }
    Point p5(1, 1,1);
    Point p6(1.0001, 1.0001,1.0001);

    Edge e4(&p5, &p6);
    if(!e4.isValid()){
        printf("Failure at testing: e4 is not an edge.\n");
    }
}
