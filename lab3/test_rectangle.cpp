#include "Rectangle.h"
#include "Point2D.h"
#include<limits>
#include<cassert>
#include<cmath>
using namespace std;
bool feq(float f1, float f2){
    return fabs(f1 - f2) < numeric_limits<float>::epsilon();
}
bool peq(const Point2D& p1, const Point2D& p2){
    return feq(p1.x(), p2.x()) 
        && feq(p1.y(), p2.y());
}
int main(){
    /* test Point2D */
    Point2D p1, p2(0.5, 0.6);
    assert(feq(p1.x(), 0));
    assert(feq(p1.y(), 0));
    p1.set(1.0, 1.2);
    assert(feq(p1.x(), 1.0));
    assert(feq(p1.y(), 1.2));
    assert(feq(p2.x(), 0.5));
    assert(feq(p2.y(), 0.6));
    /* test Point2D */

    // p1 (1.0, 1.2)
    // p2 (0.5, 0.6)
    /* test Rectangle */
    Rectangle r1(p2, p1), r2(Point2D(), Point2D(0.8, 0.8));
    assert(peq(r1.lower_left_corner(), p2));
    assert(peq(r1.upper_right_corner(), p1));


    assert(r1.add_point(Point2D(10.0, 10.0)) == false);
    assert(r1.add_point(Point2D(1.0, 1.0)) == true);
    assert(r2.add_point(Point2D(0.1, 0.1)) == true);

    print_rectangle(r1);
    print_rectangle(r2);

    Point2D p(0.7, 0.7);

    r1.add_point(p);
    vector<Point2D> v = points_in_both(r1, r2);
    assert(v.size()== 1);
    assert(peq(v[0], p));

    return 0;
}
