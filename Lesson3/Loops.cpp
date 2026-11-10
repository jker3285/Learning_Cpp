/*
	반복문

	특정 조건을 충족 시켰을 때 특정 횟수를 만족 시킬 때 까지 반복 시키는 문장이다.

	while(조건) {}
	- 조건이 참일 경우에만 실행된다.
	- 조건이 거짓이 될 때까지 실행된다.

    for(변수; 조건; 변수 변경){}
	- (변수; 조건; 변경)을 기본 툴로 잡고 실행된다.
	- 위 조건에서 조건만 적어도 실행이 된다.
	- 나머지는 while문과 동일하다.

	do {

	} while(조건);

	- 루프를 진입하기 전에 무조건 1회를 실행시킨다. (루프를 진행시키고 검사한다.)
	- while(조건);을 쓰지 않으면 무조건 오류가 뜨니 신경 쓰자.
	- 나머지는 while문과 동일
*/

#include <iostream>

using namespace std;

int main()
{
	{
		cout << "0부터 10까지 출력하시오." << endl;

		int index = 0;


		while (index <= 10)
		{
			cout << index << endl;

			index++; //index = index + 1와 같다.
		}
	}

	{
		cout << "1부터 10까지의 반복 시킬 때 변수 a의 합을 출력하시오." << endl;
		
		int index;
		int a;
		int total = 0;
		
		cin >> a;

		for (index = 0; index < 10; index++)
		{
			total += a;
			a++;
		}

		cout << "a의 값은 " << total << "이다." << endl;
	}

	{
		cout << "a가 10 이상이 될 때까지 Hello World를 출력하여라. 대신 처음 집어넣는 수는 10을 넘어도 된다." << endl;

		int a;

		cin >> a;

		do {
			cout << "Hello World" << endl << "현제 a의 값 >> " << a << endl;
			cin >> a;
		} while (a < 10);
	}
}