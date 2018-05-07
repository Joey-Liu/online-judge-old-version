#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
const int N = 6;

int main()
{
	string s1[N] = {"buffoon","thinkers","for","heavy","can","for"};
	string s2[N] = {"metal","any","food","elgant","deliver","for"};

	set<string> A(s1,s1 + N);
	set<string> B(s2, s2 + N);
	
	ostream_iterator<string,char> out_iter(cout," ");
	cout<<"Set A : ";
	copy(A.begin(),A.end(),out_iter);
	cout<<endl;

	cout<<"Set B : ";
	copy(B.begin(),B.end(),out_iter);
	cout<<endl;

	cout<<"Union of A and B :";
	set_union(A.begin(),A.end(),B.begin(),B.end(),out_iter);
	cout<<endl;

	cout<<"Intersection of A and B : ";
	set_intersection(A.begin(),A.end(),B.begin(),B.end(),out_iter);
	cout<<endl;

	cout<<"Different of A and B : ";
	set_difference(A.begin(),A.end(),B.begin(),B.end(),out_iter);
	cout<<endl;

	set<string> C;
	cout<<"Set C :";
	set_union(A.begin(),A.end(),B.begin(),B.end(),
		insert_iterator<set<string> > (C,C.begin() ) );
	copy(C.begin(),C.end(),out_iter);
	cout<<endl;

	string s3("grungy");
	C.insert(s3);
	cout<<"Set C after insertion : ";
	copy(C.begin(),C.end(),out_iter);
	cout<<endl;

	cout<<"Show a range : ";
	copy(C.lower_bound("ghost"),C.upper_bound("spook"),out_iter);
	cout<<endl;

	system("pause");

	return 0;
}
