#include <iostream>
#include <cmath>
// Eigen 几何模块

#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
int main(int argc, char const *argv[])
{
    Eigen::AngleAxisd testrotation_vector(M_1_PI / 4, Eigen::Vector3d(0, 0, 1));

    Eigen::Quaterniond q(testrotation_vector);
    Eigen::Quaterniond qtest(Eigen::Vector4d(0.01, 0.02, 0.03,1));
    Eigen::Quaterniond qtest1(Eigen::Vector4d(0.005, 0.01, 0.015,1));
    Eigen::Quaterniond qresult;
    qresult = q * qtest1;
    cout << qresult.matrix() << endl;

    Eigen::Matrix3d vtest;
    vtest << 0, -qtest.z(), qtest.y(), qtest.z(), 0, -qtest.x(), -qtest.y(), qtest.x(), 0;
    cout << vtest.matrix() << endl;
    // vtest1= vtest.exp();
    cout << testrotation_vector.toRotationMatrix() * vtest.exp() << endl;
    return 0;
}
