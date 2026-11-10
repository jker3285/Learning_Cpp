/*
	이전 시간에는 공용체 'union'을 알아봤다.
	이번 시간에는 'enum'이라는 열거형에 대해서
	알아보는 시간을 가지겠다.

	enum
	- 서로 관련된 명명된 상수들의 집합을 정의하여 사용하는 특수한 데이터 타입

	<<특징>>
	가독성 향상
	의미 없는 숫자(예: 0, 1, 2) 대신 직관적인 이름(예: SPRING, SUMMER, FALL, WINTER)을 사용하여 코드를 쉽게 이해할 수 있다.
	
	타입 안정성 (Type Safety)
	허용된 값 외에 다른 값이 할당되는 것을 컴파일 시점에 방지하여 버그를 줄인다.
	
	중복 제거
	매번 final static 상수를 직접 선언하지 않고 일괄적으로 관리할 수 있다.
*/

#include <iostream>

using namespace std;

enum Action {
    Attack = 1,  // 값을 직접 지정할 수 있음
    Move,        // 2
    Jump,        // 3
    Hide         // 4
};

int main() {
    enum Action skill;
    skill = Attack;

    switch (skill) {
    case Attack:
        cout << Attack << endl;
        break;
    case Move:
        cout << Move <<endl;
        break;
    case Jump:
        cout << Jump << endl;
        break;
    case Hide:
        cout << Hide << endl;
        break;
    }
    return 0;
}