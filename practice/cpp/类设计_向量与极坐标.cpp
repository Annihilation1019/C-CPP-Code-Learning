#include <iostream>
#include <cmath>
const double PI = 3.141592653;
using std::acos;
using std::asin;
using std::atan2;
using std::cos;
using std::pow;
using std::sin;
using std::sqrt;
namespace VECTOR
{
    /**
     * @class Vector
     * @brief 数据表示：直角坐标形式与极坐标形式；方法：向量加减 向量点积 直角坐标与极坐标相互转换 比较两个向量大小以及是否相等 设置两种坐标值 输出两种坐标值
     */
    class Vector
    {
    private:
        double x;
        double y;
        double rad;
        double r;

    public:
        Vector(int mode = 0, double x = 0, double y = 0);
        void Reset(double x, double y);
        ~Vector() = default;
        Vector operator+(Vector &another);
        Vector operator-(Vector &another);
        double operator*(Vector &another) { return x * another.x + y * another.y; }
        friend Vector operator*(double n, const Vector &vec);
        bool operator<(Vector &another) { return r < another.r; }
        bool operator>(Vector &another) { return r > another.r; }
        bool operator==(Vector &another) { return r == another.r; }
        bool operator!=(Vector &another) { return r != another.r; }
        friend std::ostream &operator<<(std::ostream &os, const Vector &vec);
    };
} // namespace VECTOR
using VECTOR::Vector;
int main()
{
    Vector vec1(0, 1, 2);
    Vector vec2(1, 1, PI);
    Vector vec3(0, 2, 5);
    Vector vec4 = 2 * vec1;
    double val = vec1 * vec3;
    std::cout << vec1 << std::endl;
    std::cout << vec2 << std::endl;
    std::cout << vec3 << std::endl;
    std::cout << vec4 << std::endl;
    std::cout << "vec1*vec3：" << val << std::endl;
    return 0;
}

Vector::Vector(int mode, double a, double b)
{
    if (mode == 0)
    { // 直角坐标模式
        this->x = a;
        this->y = b;
        this->r = sqrt(pow(a, 2) + pow(b, 2));
        this->rad = atan2(b, a);
    }
    else if (mode == 1)
    { // 极坐标模式
        this->r = a;
        this->rad = b;
        this->x = a * cos(b);
        this->y = a * sin(b);
    }
}

void Vector::Reset(double x, double y)
{
    this->x = x;
    this->y = y;
    this->r = sqrt(pow(x, 2) + pow(y, 2));
    this->rad = atan2(y, x);
}

Vector Vector::operator+(Vector &another)
{
    Vector result;
    result.x = x + another.x;
    result.y = y + another.y;
    result.r = sqrt(pow(result.x, 2) + pow(result.y, 2));
    result.rad = atan2(result.y, result.x);
    return result;
}

Vector Vector::operator-(Vector &another)
{
    Vector result;
    result.x = x - another.x;
    result.y = y - another.y;
    result.r = sqrt(pow(result.x, 2) + pow(result.y, 2));
    result.rad = atan2(result.y, result.x);
    return result;
}
namespace VECTOR
{
    Vector operator*(double n, const Vector &vec)
    {
        Vector result;
        result.x = n * vec.x;
        result.y = n * vec.y;
        result.r = sqrt(pow(result.x, 2) + pow(result.y, 2));
        result.rad = atan2(result.y, result.x);
        return result;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &vec)
    {
        os << "x: " << vec.x << ", y: " << vec.y << std::endl;
        os << "r: " << vec.r << ", rad: " << vec.rad << std::endl;
        return os;
    }
} // namespace VECTOR
