/*
	동적 배열

	우리가 배열의 인덱스는 변경 할 수 없다고 배웠다.
	하지만 특정한 상황에서 인덱스를 유동적으로 변경하면서 데이터를 저장하고 싶다.

	그러면 배열의 인덱스를 데이터 값을 집어넣을 때 마다 증가시키면 어떨까?
	이런 발상에서 온 것이 동적 배열이다.
	동적 배열은 앞서 배운 포인터를 통해서 선언된다.

	<<동적 배열을 선언하는 함수의 종류>>
	malloc: 가장 대표적인 동적 배열 선언 함수. 
			힙 영역에 메모리를 할당한다.

	calloc: calloc함수는 malloc함수와 같은 기능을 지니고 있다. 
			다만 사용하는 형태가 조금 다를 뿐이다.
			할당 한 값들을 모두 '0'으로 초기화 한다.

	realloc: 이미 할당한 공간의 크기를 바꿀 때 realloc 함수를 사용한다.

	free: 메모리를 할당만 하고 해제해 주지 않는다면, 언젠가는 메모리가 부족한 현상이 발생 할 것이다.
		  할당된 메모리가 더 이상 필요하지 않을경우 free함수를 이용하여 메모리를 해제시켜 줘야한다.

	<<선언 방법>>

	int *D_Array_M = (int*)malloc(sizeof(int) * 5);
	int *D_Array_C = (int*)calloc(5, sizeof(int));
	realloc(D_Array_M, sizeof(int) * 10);

	free(D_Array_M);
	free(D_Array_C);

	이런 식으로 선언 할 배열의 (자료형*)malloc(sizeof(자료형) * 배열의 크기) or (자료형*)calloc(n, sizeof(자료형))으로 선언 된다.

	간단히 선언할 자료형을 선언 한 다음 그 자료형 크기 만큼 할 당할 배열의 크기를 곱하면 된다.

	여기까지 따라왔다면 cpp만의 동적 배열을 할당하는 방법을 알려주겠다.
	
	new
	delete

	new는 기존에 알려준 malloc, calloc과 똑같은 역할을 한다.
	delete는 free 함수의 역할을 한다.
*/

#include <iostream>

using namespace std;

int main() {
	{
		int* D_Array_M = (int*)malloc(sizeof(int) * 5);
		int* D_Array_C = (int*)calloc(5, sizeof(int));

		D_Array_M = { 0, };

		for (int i = 0; i < 5; i++)
		{
			cout << "D_Array_M[" << i << "] = " <<  D_Array_M[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << D_Array_C[i] << " ";
		}

		free(D_Array_M);
		free(D_Array_C);
	}

	{
		int* D_Array = new int[10];

		D_Array = new int[20];

		delete(D_Array);

		//나머지 예시는 위와 동일하게 하여라.
	}
}