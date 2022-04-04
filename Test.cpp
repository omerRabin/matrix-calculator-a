#include "Matrix.hpp"
#include "doctest.h"
#include <string>
using zich::Matrix;
#include <iostream>
#include <stdexcept>
using namespace std;

TEST_CASE("Bad inputs"){
std::vector<double> identity_3X3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
std::vector<double> identity_4X4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
std::vector<double> identity_3X4 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};

zich::Matrix matrix1(identity_3X3,3,3);
zich::Matrix matrix2(identity_4X4, 4, 4);
zich::Matrix matrix3(identity_3X4,3,4);

CHECK_THROWS(matrix1+matrix2);
CHECK_THROWS(matrix1+matrix3);
CHECK_THROWS(matrix1-matrix2);
CHECK_THROWS(matrix1-matrix3);
CHECK_THROWS(matrix1+=matrix2);
CHECK_THROWS(matrix1+=matrix3);
CHECK_THROWS(matrix1-=matrix2);
CHECK_THROWS(matrix1-=matrix3);
CHECK_THROWS(matrix1*=matrix2);
CHECK_THROWS(matrix1*matrix2);
bool flag;
CHECK_THROWS(flag=matrix1==matrix2;);
CHECK_THROWS(flag=matrix1==matrix2);
CHECK_THROWS(flag=matrix1==matrix3);
CHECK_THROWS(flag=matrix1!=matrix2);
CHECK_THROWS(flag=matrix1!=matrix3);
CHECK_THROWS(flag=matrix1<=matrix2);
CHECK_THROWS(flag=matrix1<=matrix3);
CHECK_THROWS(flag=matrix1>=matrix2);
CHECK_THROWS(flag=matrix1>=matrix3);
CHECK_THROWS(flag=matrix1>matrix2);
CHECK_THROWS(flag=matrix1>matrix3);
CHECK_THROWS(flag=matrix1<matrix2);
CHECK_THROWS(flag=matrix1<matrix3);
}
TEST_CASE("Check inequality functionalities"){
  std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
  Matrix a{identity, 3, 3};
  Matrix b{arr, 3, 3};
  bool flag;
  flag = b>a;
  CHECK(flag==1);
  flag = a>b;
  CHECK(flag==0);
  flag = a<b;
  CHECK(flag==1);
  flag = b<a;
  CHECK(flag==0);
  //-------
  flag = b>=a;
  CHECK(flag==1);
  flag = a>=b;
  CHECK(flag==0);
  flag = a<=b;
  CHECK(flag==1);
  flag = b<=a;
  CHECK(flag==0);
  //---------
  flag= a == a;
  CHECK(flag==1);
  flag= a == b;
  CHECK(flag==0); 
  flag= a != a;
  CHECK(flag==0);
  flag= a != b;
  CHECK(flag==1); 

}
