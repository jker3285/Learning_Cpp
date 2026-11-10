/*
	객체 지향성으로 넘어가기 전 가장 중요한 단계인 구조체 단계에 오신 걸 환영한다.
	지난 시간에 우리는 함수라는 것을 배웠다.
	함수를 호출하기 위해서 우리가 무엇을 했을까?

	그렇다. main 함수에 다른 함수를 호출해서 사용했다.
	이처럼 main 함수에 없는 다른 무언가를 호출하기 위해서는
	main 함수에 호출하려는 대상을 main 함수에 작성해야한다.
	그게 전역 함수 혹은 변수가 되었든 다른 함수에 있는 다른 변수가 되었든.

	오늘은 외부에서 호출하는 데이터 덩어리인 구조체에 대해서 공부하겠다.

	한 가지의 변수에 여러 가지에 데이터를 저장하는 것을 배열이라고 했다.
	그러면 다른 여러가지를 한 가지 변수에 집어 넣어서 간편하게 접속하는 방법이 없을까?
	그런 불편함을 해소하기 위해 우리는 구조체를 사용 할 수 있다.

	struct 구조체명
	{
		....
	};

	or

	struct 
	{
		...
	}구조체명;

	이런 식으로 main 함수 외부에서 구조체를 선언하고 여러분들이 원하는 자료형의 데이터를 선언한다.
	그리고 main 함수에서 구조체를 사용할 때는
	
	ex)
	===============================
	구조체명 main함수에서 쓸 변수명;
	===============================

	의 형식으로 사용 할 수 있다.
	그리고 그 안에 있는 변수에 접속하고 싶을 때는 변수명.데이터명으로 접속이 가능하다.
	만일 구조체가 포인터로 사용되면 '->'방식으로도 안에 있는 데이터에 접속이 가능하다.
*/

#include <iostream>

using namespace std;

struct Student {
	char name[20];
	int age;
	char subject[100];
};

struct Person{
	char name[20];
	int age;
	char address[20];
}person, *ID = &person; // 여기에 선언하는 것은 main 함수에서 따로 선언하지 않아도 그대로 사용이 가능함!

int main()
{
	{
		Student student;
		
		cout << "학생의 기본 정보를 입력하시오. << ";
		cin >> student.name >> student.age >> student.subject;

		cout << "이름: " << student.name << " | 나이: " << student.age << " | 학과: " << student.subject << endl;
	}

	{

		cout << "서비스를 이용하기 위해서는 주민등록번호를 입력하시오. << ";
		cin >> ID->name >> ID->age >> ID->address;

		cout << "환영합니다. " << ID->name << "님" << endl;

		cout << ID->name << "님\n" << "나이: " << ID->age << " 주소: " << ID->address << endl;

	}

	{
		// 이런식으로 cin으로 입력받지 않아도 구조체를 초기화 하는 것이 가능하다.
		// 나중에 객체지향을 배우면 위 방식처럼 초기화를 하는 것을 인스턴스화라고 한다.
		Student st{ "김철수", 20 }; 

		// 이런식으로 구조체로 배열을 만드는 것도 가능하다.
		Student student[20];

		student[0] = { "홍길동", 20 };
		student[1] = { "김철수", 21 };

		cout << student[0].name << " " << student[1].name << endl;
	}

	{
		// 구조체도 위와 마찬가지로 다른 변수에 기존의 구조체를 복사하는 것이 가능하다.
		// 물론 참조(Referenct)도 가능하다.
		Student original{ "진은수", 21 };
		Student copied = original;

		cout << "이름: " << copied.name << "나이: " << copied.age;
	}

	// 참조란?
	// 보통 '&'으로 표기를 하면서 주소와 같이 대상으로하는 값을 건들인다는 공통점이 있다.
	// 하지만 그런다고 둘이 같은 개념일까? 전혀이다.
	// 보통 주소는 다른 주소값을 얼마든지 대입하면서 사용하는 것이 가능한데 참조는 대상으로 하는 그 변수에서만 한정되어있다. 
	{
		int number = 10;

		int& ref = number;      // 참조: number의 또 다른 이름
		int* ptr = &number;     // 주소: number의 위치를 구해 포인터에 저장

		ref = 20;              // 참조로 원본 수정
		cout << number << '\n'; // 20

		*ptr = 30;             // 포인터가 가리키는 원본 수정
		cout << number << '\n'; // 30

		cout << &number << '\n'; // number의 주소
		cout << &ref << '\n';    // 같은 주소: ref는 number의 별명
		cout << ptr << '\n';     // 같은 주소를 저장하고 있음
	}

}