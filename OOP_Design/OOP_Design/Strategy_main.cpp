#include "Strategy.hpp"

int main()
{
	// �̿Ͱ��� �÷��̾ �� ��Ȳ�� �°� �������� �������� �ʿ��ϴٸ� Strategy �������� ����

	Player* player = new Player();

	player->SetWeapon(new Sword());
	player->Attack();

	player->SetWeapon(new Bow());
	player->Attack();

	return 0;
}