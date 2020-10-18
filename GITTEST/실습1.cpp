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

/* (�ǽ� 1-1) �м� ���: exception�� ������ B�� ����ǰ� �Լ��� ����Ǹ鼭 B�� �Ҹ�ȴ�. �״��� A�� ����ǰ� �Լ��� ����ɶ� A�� �Ҹ�ȴ�. */
/* (�ǽ� 1-2) �м� ���: exception�� �߻��ϸ� B��ü�� �Ҹ�ǰ� funcA�� ����Ǹ鼭 A��ü�� �Ҹ�ȴ�. �׸��� Exception�� catch�� �ȴ�. */