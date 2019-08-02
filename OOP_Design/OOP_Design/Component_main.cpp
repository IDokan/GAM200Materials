#include "Component.hpp"

class Object
{
    public:
        Object()
        {
            component_ = new Component();
        }

    Component* GetComponent()
    {
        return component_;
    }

private:
    Component* component_;

};

int main(void)
{
    Object* obj = new Object;

    obj->GetComponent()->add(new ProCouple("Jinhyun Is Not a"));
    obj->GetComponent()->add(new ProSingle("Jinhyun Is a"));

    obj->GetComponent()->update();

	return 0;
}
/*
 * template <typename COMPONENT>
COMPONENT* Object::GetComponentByTemplate() const
{
    for (auto i : m_component)
    {
        if (typeid(COMPONENT) == typeid(*i))
        {
            return dynamic_cast<COMPONENT*>(i);
        }
    }
    return nullptr;
}
 */
