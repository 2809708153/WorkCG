#include <iostream> 
using namespace std;

struct Student {
	int num;
	char name[30];
	int age;
	int score[6];
};

int main() {
	Student s;
	cin >> s.num >> s.name >> s.age;
	for (int i = 0; i < 6; i++) {
		cin >> s.score[i];
	}
	int sum = 0;
	int score[6] = { 4, 3, 4, 3, 3, 3 };
	for (int i = 0; i < 6; i++)
		if (s.score[i] >= 60)
			sum += score[i];
	cout << s.num << " " << s.name << " " << s.age << endl;
	cout << sum << endl;
	return 0;
}