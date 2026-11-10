/*
	중첩 반복문
	- 반복문을 중첩해서 사용하는 문법
	- 보통 while문과 for문을 중첩시키는 것이 일반적이다.
*/

#include <iostream>

using namespace std;

int main()
{
	{
		cout << "밑변이 a인 삼각형을 출력하시오." << endl;

		int Length;

		cin >> Length;

		for (int i = 0; i <= Length; i++)
		{
			for (int j = 0; j < i; j++)
				cout << "*";
			cout << endl;
		}
	}
}