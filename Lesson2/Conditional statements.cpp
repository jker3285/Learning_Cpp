/*
	조건 분기문
	if, else, else if, switch case 문
	
	우리가 프로그램을 짤 때 특정 조건을 충족 시킬 때
	실행 됐으면 할 떄가 있다.
	이때 사용되는 프로그래밍 문법으로 조건문을 사용 할 수 있다.

	if(조건) { }
	- 가장 대표적인 조건 문이다. ()에 있는 조건을 만족 시키면 그 안에 있는 조건문이 실행된다.

	else { }
	- 자신의 위에 있는 조건문이 거짓일 경우에 실행된다. (위에 있는 조건문이 참인 경우 실행 안 됨)
	- 보통 마지막에 있는 조건문을 실행 시킬 때 사용된다.
	- 무조건 선두로 하는 조건문이 있어야 한다. 그 외엔 실행 되지 않는다.

	else if(조건) { }
	- 기본적인 역할은 else와 똑같지만 ()에 조건을 충족시켜야만 실행되는 조건문이다.
	- if의 밑에 사용 될 수 있으며 이외에는 절대 사용 불가능이다.
	- else와 달리 조건을 충족시켜야지 실행되므로 마지막 문단에 사용하는 것은 비추이다.

	switch(변수) 
	{
	case 조건:
		break;
	}
	- switch()에서 ()에 비교할 대상의 변수를 집어 넣는다.
	- 그 이후에 "case 조건"을 통해 비교할 변수가 같다면 그 아래에 있는 조건문들을 모두 실행 시킨다.
	- "break;"를 사용하는 이유는 만일 사용하지 않으면 현재 실행되고 있는 case 문을 기준으로
	  아래에 있는 case문의 조건들을 따지지 않고 실행되기 때문이다.
	- 대표적인 사용 예시) 게임에서 선택지를 고를 때 주로 사용됨.
*/

#include <iostream>

using namespace std;

int main()
{
	// 예제 1
	{
		int a;

		cin >> a;

		if (a == 1)
			cout << "a는 참이다." << endl;

		else
			cout << "a는 거짓이다." << endl;
	}

	// 예제 2
	{
		cout << "학생의 성적을 입력하시오." << endl;

		int student_score;
		
		cin >> student_score;

		if (student_score > 100 || student_score < 0) 
		{
			cout << "다시 입력하시오." << endl;
			cin >> student_score;
		}

		if (student_score >= 90)
			cout << "Your grade is A" << endl;

		else if (student_score >= 80)
			cout << "Your grade is B" << endl;

		else if (student_score >= 70)
			cout << "Your grade is C" << endl;

		else if (student_score >= 60)
			cout << "Your grade is D" << endl;

		else
			cout << "Your grade is F" << endl;
	}

	// 예제 3
	{
		cout << "상황이 1부터 3까지가 있다. 원하는 선택지를 고르시오. >> ";

		int num;

		cin >> num;

		switch (num)
		{
		case 1:
			cout << "Hello World!" << endl;
			break;
		case 2:
			cout << "Welcome To Cpp!" << endl;
			break;
		case 3:
			cout << "Cheer Up To Your Cpp Studing!" << endl;
		}
	}
}