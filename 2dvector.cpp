#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

class Vector2D
{
  private:
  double x,y;
  public:
  /*
  * This function creates a 2-D vector object whose
  * x and y components are both zero.
  */
  Vector2D()
  {
   x = 0;
   y = 0;
  }
  /*
  * This function creates a 2-D vector object.
  * @param xVal - the value of the x-component
  * @param yVal - the value of the y-component
  */
  Vector2D(double xVal, double yVal)
  {
   x = xVal;
   y = yVal;
  }
  /*
  * This function computes the sum of two vectors.
  * a new 2-D vector object representing the sum of the two
  * two vectors is returned
  * @param v - a vector 2-D object.
  * @return the sum of this Vector2D object and v.
  */
  Vector2D add(const Vector2D& v) const
  {
   return Vector2D(x+v.x,y+v.y);
  }
  /*
  * This function subtracts this Vector2D object
  * from another Vector2D object.
  * @param v a Vector2D Object
  * @return a Vector2D object that represents the difference of this Vector2D
  * object and v.
  */
  Vector2D subtract(const Vector2D& v) const
  {
   return Vector2D(x-v.x,y-v.y);
  }
  /*
  * This function computes the Euclidean length of a two-vector.
  * @return the length of this Vector2D object.
  */
  double length() const
  {
   return (double) sqrt(pow(x,2) + pow(y,2));
  }
  /*
  * This function computes the dot product of this
  * Vector2D object and another Vector2D object.
  * @param v a Vector2D object.
  * @return the dot product of this Vector2D object and v.
  */
  double dotProduct(const Vector2D& v) const
  {
   return x*v.x+y*v.y;
  }
  /*
  * This function computes the norm of this vector.
  * @return a Vector2D object representing the norm of this vector
  */
  Vector2D norm() const
  {
   return Vector2D(x/length(),y/length());
  }
  /*
  * This function returns a string representation of this vector
  * in the format <x.xxxx,y.yyyy>, where each component has
  * four decimal places
  * @return a string representing this Vector2D object
  */
  string str() const
  {
   stringstream ss;
   ss<<"<"<<fixed<<setprecision(4)<<x<<","<<y<<">";
   return ss.str();
  }
  };

int main()
{
 int vectorx, vectory;
 cout<<"Enter the first two-vector>";		//Prompt the user to input 2 two dimensional vectors.
 cin>>vectorx>>vectory;
 Vector2D V1(vectorx,vectory);
 cout<<"Enter the second two-vector>";
 cin>>vectorx>>vectory;
 Vector2D V2(vectorx,vectory);
 Vector2D sum = V1.add(V2);	//Computes the sum of vector components in x and y.
 cout<<V1.str()<<" + "<<V2.str()<<" = "<<sum.str()<<endl;
 Vector2D subtraction = V1.subtract(V2);	//Computes the inverse addition of vector components x and y.
 cout<<V1.str()<<" - "<<V2.str()<<" = "<<subtraction.str()<<endl;
 cout<<V1.str()<<" * "<<V2.str()<<" = "<<fixed<<setprecision(4)<<V1.dotProduct(V2)<<endl;
 cout<<"||"<<V1.str()<<"|| = "<<V1.length()<<endl;	//Calculates & Displays the magnitude of the two vectors.
 cout<<"||"<<V2.str()<<"|| = "<<V2.length()<<endl;
 Vector2D norm1 = V1.norm();	//Computes and displays the normal component of the two vectors.
 cout<<"The norm of "<<V1.str()<<" is "<<norm1.str()<<"."<<endl;
 Vector2D norm2 = V2.norm();
 cout<<"The norm of "<<V2.str()<<" is "<<norm2.str()<<"."<<endl;
 Vector2D sumnorm = norm1.add(norm2);	//Computes and displays the sum of the two normal components.
 cout<<norm1.str()<<" + "<<norm2.str()<<" = "<<sumnorm.str()<<endl;

 return 0;
}
