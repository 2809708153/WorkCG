#include <iostream>
#include <bits/stdc++.h>
using namespace std;

enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };
class CPU {
private:
	CPU_Rank rank; //√∂æŸ¿‡–Õ
	int frequency;
	double voltage;
public:
	void setCPU(CPU_Rank r, int f, double v) {
		rank = r;
		frequency = f;
		voltage = v;
		cout << "one CPU is created!" << "\n" << "CPU is running!" << "\n" << "CPU stop!" << "\n" << "one CPU is distoried!";
	}
};
int main() {
	CPU Cpu;
	Cpu.setCPU(P6, 300, 2.8);
	return 0;
}
