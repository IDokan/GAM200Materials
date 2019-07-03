#include "Strategy.hpp"

int main()
{
	// 이와같이 플레이어가 각 상황에 맞게 전략적인 디자인이 필요하다면 Strategy 디자인이 좋다

	Player* player = new Player();

	player->SetWeapon(new Sword());
	player->Attack();

	player->SetWeapon(new Bow());
	player->Attack();

	return 0;
}