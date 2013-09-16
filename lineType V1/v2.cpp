/*
/ Homework 2
/ Chapter 2 programming problem 18
/ Author: Ryan Yulin Ye
/ Date: 9/13/2013
/ Annotated from my Android tablet
*/

#include <iostream>
#include <iomanip>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
class lineType
{

	friend ostream& operator<< (ostream&, const lineType&);
	friend istream& operator>> (istream&, lineType&);

	private:
		float a;
		float b;
		float c;
	public:
		lineType():a(-1),b(1),c(0)
		{}

		lineType(float A, float B, float C):a(A),b(B),c(C)
		{}

		// test if the line is horizontal
		bool isHori() const
		{
			if(a==0)
				return true;
			else
				return false;
		}

		// test if the line is vertical
		bool isVerti() const
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
		bool		isEqual(const lineType& ll)
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
		bool	isPerpen(lineType& ll)
		{
			if((getSlope() * ll.getSlope() == -1) || ((isHori() && ll.isVerti()) || (isVerti() && ll.isHori())))
				return true;
			else
				return false;
		}

		//return if two lines are parallel
		bool 	isPara(lineType& ll)
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
		void 	getIntcpt(lineType& ll)
		{
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

		//start of the block of overloaded operator functions

		lineType& operator = (lineType& ll)
		{
			lineType newline(ll.a,ll.b,ll.c);
			return newline;
		}

		lineType& operator + (lineType& ll)
		{
			lineType newLine(a+ll.a,b+ll.b,c+ll.c);
			return newLine;
		}

		bool operator + ()
		{
			return isVerti();
		}

		bool operator -()
		{
			return isHori();
		}

		bool operator == (lineType& ll)
		{
			return isEqual(ll);
		}

		bool operator || (lineType& ll)
		{
			return isPara(ll);
		}
		bool operator && (lineType& ll)
		{
			return isPerpen(ll);
		}


};

ostream& operator << (ostream& osObj, const lineType& ll)
{
	osObj<<ll.a<<"x + "<<ll.b<<"y = "<<ll.c;
	return osObj;
}

istream& operator >> (istream& isObj, lineType& ll)
{
	isObj>>ll.a>>ll.b>>ll.c;
	return isObj;
}

////////////////////////////////////////////////////////////////////////////////

int main()
{

	lineType l1,l2;

	cout<<"++++++++++++++++++++Beginning of the program++++++++++++++++++++ \n";
	cout<<"please input the a,b,c for the first line"<<endl;
	cin>>l1;

	cout<<endl<<"please input the a,b,c for the second line"<<endl;
	cin>>l2;

		cout<<"l1 is: "<<l1<<endl;
		cout<<"l2 is: "<<l2<<endl;
		cout<<endl<<"slope of l1: "<<l1.getSlope()<<endl;
		cout<<"slope of l2: "<<l2.getSlope()<<endl;
		cout<<"is l1 and l2 equal? "<<boolalpha <<(l1==l2)<<endl;
		cout<<"is l1 and l2 perpendicular? "<<boolalpha <<(l1 && l2)<<endl;
		cout<<"is l1 and l2 parallel? "<<boolalpha <<(l1 || l2)<<endl;
		l1.getIntcpt(l2);

	cout<<"++++++++++++++++++++End of the program++++++++++++++++++++ \n";
	return 0;
}
