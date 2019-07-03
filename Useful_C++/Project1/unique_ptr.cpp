#include <iostream>
#include <memory>

std::unique_ptr<int> TestUnique(int* a)
{
	//���� �����͸� ������ �����Ӱ� �̿��ϰ�����ÿ� �̷���
	return std::unique_ptr<int>(a);

	//���� �����͸� �����鼭 �ٸ� �޸� �ּҰ��� ������ �Ͱ� �Ҷ� �̷���
	/* Like a Deep Copy
	*/
	//return  std::unique_ptr<int>(new int(*a));
}

std::shared_ptr<int> TestShared(int* a)
{
	//���� �����͸� ������ �����Ӱ� �̿��ϰ�����ÿ� �̷���
	return std::shared_ptr<int>(a);

	//���� �����͸� �����鼭 �ٸ� �޸� �ּҰ��� ������ �Ͱ� �Ҷ� �̷���
	/* Like a Deep Copy
	*/
	//return  std::shared_ptr<int>(new int(*a));
}


int main()
{
	int* a = new int(5);

	std::unique_ptr<int> unique_a = TestUnique(a);
	std::shared_ptr<int> shared_a = TestShared(a);

	// ����ũ �������̱� ������ std::move��� �Լ��� ���� �ʴ��̻� �������� �����ʴ´� 
	// std::move�� �޸� ��ü�� �� �������ٰ� �ű�� ������ ������ ������ move���� �ƿ� ������ ��ü�� �������
	std::unique_ptr<int> second_a = std::move(unique_a);
    //std::unique_ptr<int> second_a = unique_a;

	// shared �����Ͷ� ���� �������� �����ϴ� --> �޸� ������ ���ʿ� ����
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


	// ������ �� ������ ��Ʈ���Ϳ��� ������ --> unique_ptr�� shared_ptr�� ���� ���� �޸𸮸� �����ϰ� �ֱ⶧����
	// ��Ʈ���Ϳ��� ������ �ȴ�. --> shallow copy �̱� ����

	// ��ġ�� ���ؼ� ���� �ϳ��� ����Ʈ ������ �Լ����� �ι�° ���� ������ ����ϸ�ȴ�

	// �׸��� ���͸޸𸮸� ���� �˰����� �޸� free �� �Ű�Ƚᵵ �˾Ƽ� �����ֱ� ������ �޸� ���� good
	return 0;
}