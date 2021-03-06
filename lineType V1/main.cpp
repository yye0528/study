/*
/ Homework 1
/ Chapter 1 programming problem 6
/ Author: Ryan Yulin Ye
/ Date: 9/10/2013
*/

#include <iostream>
#include <iomanip>

using namespace std;

///////////////////////////////////////
class lineType
{
	private:
		float a;
		float b;
		float c;
	public:
		lineType(float A, float B, float C):a(A),b(B),c(C)
		{}

		bool isHori()
		{
			if(a==0)
				return true;
			else
				return false;
		}

		bool isVerti()
		{
			if(b==0)
				return true;
			else
				return false;
		}

		//return the slope of the line
		float	getSlope()
		{
			if(!isVerti())
			{
				float slp=-(a/b);
				return slp;
			}else{
				cout<<"the line is vertical!";
			}

			return -1;
		}

		//return if two lines are equal
		bool		isEqual(lineType ll)
		{
				if(a==ll.a && b==ll.b && c==ll.c)
				{
					return true;
				}else if(isHori() && ll.isHori() && b==ll.b && c==ll.c)
				{
					return true;
				}
				else if(isVerti() && ll.isVerti() && a==ll.a && c==ll.c)
				{
					return true;
				}
				return false;
		}

		//return if two lines are perpendicular
		bool		isPerpen(lineType ll)
		{
			if((getSlope() * ll.getSlope() == -1) || ((isHori() && ll.isVerti()) || (isVerti() && ll.isHori())))
				return true;
			else
				return false;
		}

		//return if two lines are parallel
		bool 	isPara(lineType ll)
		{
			if	(isVerti() && ll.isVerti())
			{
				return true;
			} else if(!isVerti() && !ll.isVerti())
			{
				if((-a/b)==(-ll.a/ll.b))
					return true;
			}

			return false;
		}

		//return the point of intercept of two lines
		void 	getIntcpt(lineType ll){
			float x,y;

			if(isPara(ll))
			{
				cout<<"the two lines have no intercept because they are parallel!"<<endl;
			}else
			{
				if(!isHori() && !ll.isHori() && !isVerti() && !ll.isVerti())
				{
					x=((c/b-ll.c/ll.b)/(a/b-ll.a/ll.b));
					y=((c/a-ll.c/ll.a)/(b/a-ll.b/ll.a));
				}else if(isHori() && !ll.isVerti())
				{
					y=(-c)/b;
					x=(-ll.c-ll.b*y)/ll.a;
				}else if(isVerti() && !ll.isHori())
				{
					x=(-c)/a;
					y=(-ll.c-ll.a*x)/ll.b;
				}else if(ll.isHori() && !isVerti())
				{
					y=(-ll.c)/ll.b;
					x=(-c-b*y)/a;
				}else if(ll.isVerti() && !isHori())
				{
					x=(-ll.c)/ll.a;
					y=(-c-a*x)/b;
				}else if(isVerti() && ll.isHori())
				{
					x=(-c)/a;
					y=(-ll.c)/ll.b;
				}else if(isHori() && ll.isVerti())
				{
					x=(-ll.c)/ll.a;
					y=(-c)/b;
				}
				cout<<"the intercept point is ("<<x<<","<<y<<")"<<endl;
			}
		}

};
/////////////////////////////////////////

int main()
{

	float a1,b1,c1,a2,b2,c2;

	cout<<"++++++++++++++++++++Beginning of the program++++++++++++++++++++ \n";
	cout<<"please input the a,b,c for the first line"<<endl;
	cin>>a1>>b1>>c1;

	cout<<endl<<"please input the a,b,c for the second line"<<endl;
	cin>>a2>>b2>>c2;

	if((a1==0 && b1==0)||(a2==0 && b2==0))
	{
		cout<<"Input error! a and b can't be zero at the same time!"<<endl;
	}
	else
	{
		lineType l1(a1,b1,c1),l2(a2,b2,c2);

		cout<<endl<<"slope of l1: "<<l1.getSlope()<<endl;
		cout<<"slope of l2: "<<l2.getSlope()<<endl;
		cout<<"is l1 and l2 equal? "<<boolalpha <<l1.isEqual(l2)<<endl;
		cout<<"is l1 and l2 perpendicular? "<<boolalpha <<l1.isPerpen(l2)<<endl;
		cout<<"is l1 and l2 parallel? "<<boolalpha <<l1.isPara(l2)<<endl;
		l1.getIntcpt(l2);
	}

	cout<<"++++++++++++++++++++End of the program++++++++++++++++++++ \n";
	return 0;
}
