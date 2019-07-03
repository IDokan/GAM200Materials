#include "Observer.hpp"

int main()
{
	// 1 : N(다수) 의 형태일때 자주 쓰는 디자인
	// 예로들자면 플레이어가 충돌했을시에 모든 시스템에 알리기위해 쓰인다? 라는 개념식으로 생각하면될듯
	//객체 사이에 일 대 다의 의존 관계를 정의해두어, 
	//어떤 객체의 상태가 변할 때 그 객체에 의존성을 가진 다른 객체들이 그 변화를 통지 받고 
	//자동으로 업에이트될 수 있게 만듭니다
	//https://boycoding.tistory.com/107 --> 예제 존나 좋음 ㄹㅇ

	Subject* newsubjects = new ConcreateSubjects();

	Observer* new_reader = new Newreader(newsubjects);
	Observer* neighbor = new NeighborReader(newsubjects);

	newsubjects->notify();

	return 0;
}