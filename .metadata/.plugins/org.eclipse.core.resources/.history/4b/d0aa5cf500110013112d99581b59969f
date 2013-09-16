/* 
excercise 9.1 
*/


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class publication{
	protected:
		string title;
		float price;
	public:
		publication():title("untitled"),price(0)
			{}		
		publication(string t,float p): title(t),price(p)
			{}
		void getdata(){
			cout<<"title of publication: "; cin>>title; cout<<endl;
			cout<<"price of the publication: $"; cin>>price; cout<<endl;
		}
		void putdata(){
			cout<<"Title: "<<title<<endl<<"Price: $"<<price<<endl;
		}		
	};
/////////////////////////////////
class book:private publication{
	private:
		int page;
	public:
		book():publication(),page(0)
			{}
		book(string t, float p, int pg):publication(t,p),page(pg)
			{}
		void getdata(){
			publication::getdata();
			cout<<"page of the book: ";cin>>page;cout<<endl;
		}
		void putdata(){
			publication::putdata();
			cout<<"Number of pages: "<<page<<endl;
		}
};
/////////////////////////////////
class tape:private publication{
	private:
		float playtime;
	public:
		tape():publication(),playtime(0.0F)
			{}
		tape(string t, float p, float pt):publication(t,p),playtime(pt)
			{}
		void getdata(){
			publication::getdata();
			cout<<"playtime of the tape in sec: ";cin>>playtime;cout<<endl;
		}
		void putdata(){
			publication::putdata();
			cout<<"Playtime of the tape: "<<playtime<<" min"<<endl;
		}
};
////////////////////////////////////////////


int main(){

	book b1;
	book b2("C++ programming",20,800);
	
	tape t1;
	tape t2("Fairytale", 10, 20);

	b1.getdata();
	t1.getdata();
	
	b1.putdata();
	b2.putdata();
	t1.putdata();
	t2.putdata();
	
	return 0;
}
