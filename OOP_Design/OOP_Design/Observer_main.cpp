#include "Observer.hpp"

int main()
{
	// 1 : N(�ټ�) �� �����϶� ���� ���� ������
	// ���ε��ڸ� �÷��̾ �浹�����ÿ� ��� �ý��ۿ� �˸������� ���δ�? ��� ��������� �����ϸ�ɵ�
	//��ü ���̿� �� �� ���� ���� ���踦 �����صξ�, 
	//� ��ü�� ���°� ���� �� �� ��ü�� �������� ���� �ٸ� ��ü���� �� ��ȭ�� ���� �ް� 
	//�ڵ����� ������Ʈ�� �� �ְ� ����ϴ�
	//https://boycoding.tistory.com/107 --> ���� ���� ���� ����

	Subject* newsubjects = new ConcreateSubjects();

	Observer* new_reader = new Newreader(newsubjects);
	Observer* neighbor = new NeighborReader(newsubjects);

	newsubjects->notify();

	return 0;
}