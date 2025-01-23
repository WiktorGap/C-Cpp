#include <stdlib.h>
#include <math.h>
#include <ostream>
#include <iostream>
template <typename T>
class Vector
{
    public:
    virtual ~Vector(){};
    virtual double length() const = 0;
    virtual void normalize() = 0;


};

template <typename T>
class Vector2D : public Vector<T>
{
public:
    Vector2D(T _x, T _y): x(_x),y(_y){};
    ~Vector2D(){};
    virtual double length()const override
    {
        double pow_u1 = pow(x, 2);
        double pow_u2 = pow(y , 2);
        double result = sqrt(pow_u1 + pow_u2);
        return result;
    }
    virtual void normalize() override
    {
        double length_ = length();
        double normal_x = this->x = this->x / length_;
        double normal_y = this->y= this-> y / length_;


    }

    friend std::ostream& operator<<(std::ostream& out, Vector2D &obj)
    {
        return out<<"Pierwsza składowa: "<<obj.x<<"  Druga składowa: "<<obj.y;
    }



    T x;
    T y;    
    
};


template <typename T>
class Vector3D: public Vector2D<T>
{
    public:
    Vector3D(T _x, T _y,T _z): Vector2D<T>(_x,_y),z(_z){};
    ~Vector3D(){};
    virtual double length()const override
    {
        double pow_u1 = pow(this->x, 2);
        double pow_u2 = pow(this->y , 2);
        double pow_u3 = pow (z , 2);
        double result = sqrt(pow_u1 + pow_u2 + pow_u3);
        return result;
    }
    virtual void normalize() override
    {
        double length_ = length();
        double normal_x = this->x = this->x /  length_;
        double normal_y = this->y = this-> y /length_;
        double normal_z = this->z= this->z / length_;


    }

    friend std::ostream& operator<<(std::ostream& out, Vector3D &obj)
    {
        return out<<"Pierwsza składowa: "<<obj.x<<"  Druga składowa: "<<obj.y<<" Trzecia składowa: "<<obj.z;
    }

    private:
    //T x;
    //T y;
    T z;

  
};

int main()
{

    Vector2D<double> vector_1(20,70);
    vector_1.length();
    std::cout<<"Wektor 1 przed normalizacja: "<<vector_1<<"\n"; 
    vector_1.normalize();
    std::cout<<"Wektor 2 po normalizacji: "<< vector_1;
    
    Vector3D<double> vector_3(20,30,40);
    std::cout<<"Wektor przed normalizacji: "<<vector_3<<"\n";
    vector_3.length();
    vector_3.normalize();
    std::cout<<"Wektor po normalizacji: "<<vector_3<<"\n";



    return 0;
}
