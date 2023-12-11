#include <iostream>
using namespace std;

class Test {
	int data;
public:
	Test(int d = 0) : data(d) { cout << "Constructor calls for: " << data << endl; }
	int get_data() const { return data; }
	~Test() { cout << "Destructor calls for: " << data << endl; }
};
//Custome Deleter for Smart Pointer
void my_deleter(Test* ptr) {
	cout << "Coustome Deleter!\n";
	delete ptr;
}

int main() {
	/*unique_ptr<Test> p1 = make_unique<Test>(10);
	unique_ptr<Test> p2{ new Test{20} };
	unique_ptr<Test> p3;
	p3 = move(p1);*/
	/*shared_ptr<Test> s1 = make_shared<Test>(2000);
	{

		shared_ptr<Test> s2{ new Test {100} , my_deleter };
	}
	cout << s1.use_count() << endl;
	shared_ptr<Test> s3 = s1;
	shared_ptr<Test> s4;
	s4 = move(s1);
	cout << s3.use_count() << endl;
	cout << s4.use_count() << endl;*/
	{
		//shared ptr custome deleter
		shared_ptr<Test> s1(new Test{ 200 },
			[](Test* ptr) {
				cout << "Lambda custome deleter!\n";
				delete ptr;
			});
	}
	//{
	//	//Unique ptr custome deleter
	//	unique_ptr<Test> p1 (new Test{ 400 },
	//		[] (Test* ptr) {
	//			cout << "Lambda custome deleter\n";
	//			delete ptr;
	//		});

	//}
	return 0;
}