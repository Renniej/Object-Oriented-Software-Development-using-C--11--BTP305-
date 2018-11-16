#include <iostream>
#include <string>
#include <memory>



class Entity {


public :
	Entity() {
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity() {
		std::cout << "Destroyed Entity!" << std::endl;
	}

	void Print() {
	
	}
};

int main() {
	{
		std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>(); //Shared_entity only dies when all of its references/soft-copies are dead

		{

			std::unique_ptr<Entity> entity = std::make_unique <Entity>(); //Unique pointers can not be copied and are limited to scope!!!!

			

			std::shared_ptr<Entity> shr_entity_cpy = shared_entity; //soft-clone is made here

			std::weak_ptr<Entity> weakEntity = shared_entity; //weakptr does not increase reference counter for shared pointers. However it does deallocate memory once out of scope


		} //soft-clone goes out of scope here but memory isn't deallocated because a reference still exist (shared_entity)
		//Unique_ptr dies here because it is locked to scope
	}
	std::cin.get();
}