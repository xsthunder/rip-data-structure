#include"utilities.h"
#include<string>
#include<vector>
using namespace std;

class Polygon{
    // 多边形
    protected:
        string _name;
        vector<Point> _points;
    public:
        Polygon(const string &name, const vector<Point>& points):_name(name), _points(points){
        }
        const string & getName(){
            return _name;
        }
        bool HasAllEqualSides(){
            int i = 0;
            int j = 1;
            float prev_len = DistanceBetween(_points[i], _points[j]);
            for(unsigned int k = 0;k<_points.size();k++){
                i = (i+1)%_points.size();
                j = (j+1)%_points.size();
                float cur_len = DistanceBetween(_points[i], _points[j]);
                if(!EqualSides(prev_len, cur_len))return false;
            }
            return true;
        }
        virtual void hello(){

        }
};

class Triangle:public Polygon{
    // 三角形
    public:
        Triangle (const string &name, const vector<Point>& points) throw (int) :Polygon(name, points) 
        {
            if(points.size() != 3)throw 30;
        }
};

class IsoscelesTriangle: public Triangle{
    // 等腰三角形
    public:
        IsoscelesTriangle(const string &name, const vector<Point>& points) throw (int) :Triangle(name, points) 
        {
            int i = 0;
            int j = 1;
            float prev_len = DistanceBetween(_points[i], _points[j]);
            bool hasEqual=false;
            for(unsigned int k = 0;k<_points.size();k++){
                i = (i+1)%_points.size();
                j = (j+1)%_points.size();
                float cur_len = DistanceBetween(_points[i], _points[j]);
                if(EqualSides(prev_len, cur_len))hasEqual = true;
                prev_len = cur_len;
            }
            if(!hasEqual)throw 31;
        }
};

class EquilateralTriangle: public IsoscelesTriangle{
    // 等边三角形
    public:
        EquilateralTriangle(const string &name, const vector<Point>& points) throw (int) :IsoscelesTriangle(name, points) {
            if(!this->HasAllEqualSides())throw 32;
        }
};

class Quadrilateral:public Polygon{
    // 四边形
    public:
        Quadrilateral(const string &name, const vector<Point>& points) throw (int) :Polygon(name, points) {
            if(_points.size ()!= 4)throw 40;
        }
};

class Rectangle:public Quadrilateral{
    // 矩形
    public:
        Rectangle(const string &name, const vector<Point>& points) throw (int) :Quadrilateral(name, points) {
            // 三个直角
            int i,j,k;
            i = 0;
            j = 1;
            k = 2;
            for(int z = 0;z<3;z++){
                if(
                        !RightAngle(Angle(
                            _points[i],
                            _points[j],
                            _points[k]
                           ))
                  )throw 42;
                i = (i+1)%_points.size();
                j = (j+1)%_points.size();
                k = (k+1)%_points.size();
            }

        }
};
class Square:public Rectangle{
    // 正方形
    public:
        Square(const string &name, const vector<Point>& points) throw (int) :Rectangle(name, points) {
            // 等边
            if(!this->HasAllEqualSides()){
                throw 43;
            }
        }

};
