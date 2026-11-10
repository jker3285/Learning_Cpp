/*
	우리가 특정 프로그램을 짤 때 특정 횟수를 넘어가는 프로그램을 짤 경우가 있다.
	이런 반복적인 작업은 코드의 가독성 뿐만 아니라 작업 효율성도 떨어진다.
	그래서 우리가 필요한 기능들을 따로 작성해서 main 함수에 선언해서 작동하는 것을 함수라고 한다.

	선언 예시)
	void Function()
	{
		...
	}

	이처럼 함수는 return을 받을 변수의 타입명을 따르고 함수명과 그 함수에 들어가는 파라미터로 형성된다.
	함수를 작성하기 위해서 필수적인 사항은 함수의 타입과 함수명은 무조건 있어야 한다는 점이다.
	
	<<주의>>
	void 타입의 함수는 return 값을 가지지 않는다.
	이를 이용해서 return을 할 필요 없이 함수 내부에서 모든 것들을 끝낼 때 자주 사용한다.
*/

#include <iostream>

using namespace std;

//간단하게 정수 제곱을 구하는 함수를 구현하겠다.

int Pow(int Base, int Index)
{
	int total = 1;
	for (int i = 1; i <= Index; i++)
	{
		total *= Base;
	}

	return total;
}

// void 함수의 예시. 간단하게 삼각형을 구하는 함수를 만들겠다.
void Triangle(int Length, int Type)
{
	switch (Type)
	{
	case 1:
	{
		for (int i = 0; i < Length; i++)
		{
			for (int j = 0; j <= i; j++)
				cout << "*";

			cout << endl;
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < Length; i++)
		{
			for (int j = i; j < Length; j++)
				cout << "*";
			cout << endl;
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < Length; i++)
		{
			for (int j = i; j < Length - 1; j++)
				cout << " ";

			for (int h = 0; h < (i * 2 + 1); h++)
				cout << "*";

			cout << endl;
		}
		break;
	}
	}
}

int main() {
	{
		int base, index;

		cout << "밑수와 지수를 입력하시오. >> ";
		cin >> base >> index;

		cout << "결과 값은 >> " << Pow(base, index) << "이다." << endl;
	}

	{
		int Length, Type;

		cout << "삼각형의 밑변의 길이와 출력할 삼각형의 타입을 고르시오. >> ";
		cin >> Length >> Type;

		cout << "타입 " << Type << "의 삼각형은" << "\n===============================================================" << endl;
		Triangle(Length, Type);
	}
}