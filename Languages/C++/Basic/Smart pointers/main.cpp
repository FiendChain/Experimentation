#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
    std::string m_Name;
public:
    Entity(std::string name)
        : m_Name(name)
    {
        std::cout << "Created entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
    }
    void Print()
    {
        std::cout << "I am " << m_Name << std::endl;
    }
};

int main(int argc, char *argv[])
{
    // unique pointer
    {
        // explicit creation
        // std::unique_ptr<Entity> entity(new Entity());
        // preferred creation, more exception safe?
        std::unique_ptr<Entity> entity = std::make_unique<Entity>("Unique");
        // std::unique_ptr<Entity> entity0 = entity; // throws error b/c unique ptr cannot be shared
        entity->Print();
    }
    // shared pointer
    {
        // demonstrating shared pointers
        std::shared_ptr<Entity> entity0;
        {
            
            // shared pointers
            // shared entity ref count is 1
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>("Shared"); 
            // entity0 and sharedEntity ref count goes to 2
            entity0 = sharedEntity;
            sharedEntity->Print();
            entity0->Print();
        }
        // entity0 ref count goes to 1 after sharedEntity is unreferenced
        entity0->Print(); // entity instance still persists
    }
    // weak pointers
    {
        std::weak_ptr<Entity> weakEntity;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>("Shared used by weak");
            // weak pointer
            // doesn't increase reference count for the associated
            // shared pointed
            // weak pointers cannot keep an entity alive, like a shared pointer
            // can be checked if still valid
            weakEntity = sharedEntity;
            // testing pointers
            sharedEntity->Print();
            // to use a weak point you need to check the lock
            // this checks if it is valid
            if (auto ptrEntity = weakEntity.lock())
                ptrEntity->Print();
            else
                std::cout << "weakEntity has expired" << std::endl;
        }
        // testing it again will indicate the entity has expired
        if (auto ptrEntity = weakEntity.lock())
                ptrEntity->Print();
        else
            std::cout << "weakEntity has expired" << std::endl;
    }
    

    std::cin.get();
    return 0;
}