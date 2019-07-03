#include <iostream>
#include <memory>

std::unique_ptr<int> TestUnique(int* a)
{
	//원래 데이터를 가지고 자유롭게 이용하고싶을시에 이렇게
	return std::unique_ptr<int>(a);

	//새로 데이터를 가지면서 다른 메모리 주소값을 가지고 싶게 할땐 이렇게
	/* Like a Deep Copy
	*/
	//return  std::unique_ptr<int>(new int(*a));
}

std::shared_ptr<int> TestShared(int* a)
{
	//원래 데이터를 가지고 자유롭게 이용하고싶을시에 이렇게
	return std::shared_ptr<int>(a);

	//새로 데이터를 가지면서 다른 메모리 주소값을 가지고 싶게 할땐 이렇게
	/* Like a Deep Copy
	*/
	//return  std::shared_ptr<int>(new int(*a));
}


int main()
{
	int* a = new int(5);

	std::unique_ptr<int> unique_a = TestUnique(a);
	std::shared_ptr<int> shared_a = TestShared(a);

	// 유니크 포인터이기 때문에 std::move라는 함수를 쓰지 않는이상 포인팅이 되지않는다 
	// std::move는 메모리 자체를 그 변수에다가 옮기기 때문에 오른쪽 변수는 move이후 아에 데이터 자체가 사라진다
	std::unique_ptr<int> second_a = std::move(unique_a);
    //std::unique_ptr<int> second_a = unique_a;

	// shared 포인터라 다중 포인팅이 가능하다 --> 메모리 걱정도 할필요 없다
	std::shared_ptr<int> second_s_a = shared_a;

	*a = 2;

	if (unique_a.get() != nullptr)
		std::cout << "First Unique Ptr Value: " << *unique_a.get() << std::endl;
	else
		std::cout << "First Unique Ptr Value: NULLPTR" << std::endl;

    delete unique_a.get();

	std::cout << "Second Unique Ptr Value: " << *second_a.get() << std::endl;

	std::cout << "First Shared Ptr Value: " << *shared_a.get() << std::endl;
	std::cout << "Second Shared Ptr Value: " << *second_s_a.get() << std::endl;


	// 하지만 이 예제는 디스트럭터에서 터진다 --> unique_ptr과 shared_ptr이 서로 같은 메모리를 참고하고 있기때문에
	// 디스트럭터에서 터지게 된다. --> shallow copy 이기 때문

	// 고치기 위해선 둘중 하나를 스마트 포인터 함수에서 두번째 줄의 리턴을 사용하면된다

	// 그리고 닥터메모리를 쓰면 알겠지만 메모리 free 를 신경안써도 알아서 다해주기 때문에 메모리 관리 good
	return 0;
}