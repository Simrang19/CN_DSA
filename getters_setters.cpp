#include <iostream>
using namespace std;
class Student {

	public :

	int rollNumber;
	
	private :

	int age;


	public :

	void display() {
		cout << age << " " << rollNumber << endl;
	}

	int getAge() {
		return age;
	}

	void setAge(int a, int password) {
		if(password != 123) {
			return;
		}
		if(a < 0) {
			return;
		}
		age = a;
	}

};



int main() {
	Student s1;

	Student *s2 = new Student;

	s1.setAge(20,123);
	s2 -> setAge(24,12);

	s1.display();
	s2 -> display();


}