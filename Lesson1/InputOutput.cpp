/*
	이제 것 우리는 C에서 <stdio.h>를 사용해서 입출력을 했다.
	이제 우리가 사용하는 cpp에서는 <iostream>을 이용해서 입출력을 한다.
	
	iostream에서 주로 사용할 것

	"std::cin >> 변수명" : 입력
	"std::cout << 변수명" : 출력

	여기서 std는 "using namespace std;"를 사용하면 생략 할 수 있다.
*/

#include <iostream>

using namespace std;

int main() {

	int a;
	
	cin >> a;
	cout << a;
}