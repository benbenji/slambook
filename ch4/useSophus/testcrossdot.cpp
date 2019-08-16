#include <iostream>
#include <cmath>
using namespace std; 

#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/so3.h"
#include "sophus/se3.h"
Eigen::Matrix3d retcrossmat(Eigen::Vector3d w)
{
    Eigen::Matrix3d W;
    W(0,0)=0;
    W(0,1)=-w(2);
    W(0,2)=w(1);
    W(1,0)=w(2);
    W(1,1)=0;
    W(1,2)=-w(0);
    W(2,0)=w(1);
    W(2,1)=w(0);
    W(2,2)=0;
    return W;
}

int main(int argc, char const *argv[])
{
    Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();
    Eigen::Vector3d w = Eigen::Vector3d::Random();
    Eigen::Vector3d Rw = R * w;
    
    cout<<retcrossmat(Rw)*R<<endl;
    cout<<R*retcrossmat(w)<<endl;
    return 0;
}

