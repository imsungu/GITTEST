#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	// throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}

/* (실습 1-1) 분석 결과: exception이 없으면 B가 실행되고 함수가 종료되면서 B도 소멸된다. 그다음 A가 실행되고 함수가 종료될때 A도 소멸된다. */
/* (실습 1-2) 분석 결과: exception이 발생하면 B객체가 소멸되고 funcA도 종료되면서 A객체도 소멸된다. 그리고 Exception이 catch가 된다. */