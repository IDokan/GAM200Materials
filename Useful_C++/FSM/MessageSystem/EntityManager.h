/******************************************************************************
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name:   EntityManager.h
Author
		Dev_Il
		rtd99062@gmail.com
Creation Date: 01.08.2020

	Header file for Entity Manager
		It manages entities in world
******************************************************************************/
#pragma once
#include <map>

class BaseGameEntity;

class EntityManager
{
public:
	static EntityManager* Instance();

	/*	Example of usage of RegisterEntity()
		When an entity is created it is registered with the entity manager like so:

	// ent_Miner_Bob is declared in "MessageTypes.h"
	// Miner(int ID);
	Miner* Bob = new Miner(ent_Miner_Bob); // enumerated ID
	EntityMgr->RegisterEntity(Bob);
	*/	

	// this method stores a pointer to the entity in the std::vector
	// m_Entities at the index position indicated by the entity's ID
	// (makes for faster access)
	void RegisterEntity(BaseGameEntity* NewEntity);


	/*	Example of usage of GetEntityFromId()
		A client can now request a pointer to a specific entity by passing its ID
		to the method EntityManager::GetEntityFromID in this way:

	// ent_Miner_Bob is declared in "MessageTypes.h"
	Entity* pBob = EntityMgr->GetEntityFromID(ent_Miner_Bob);
	*/
	// returns a pointer to the entity with the ID given as a parameter
	BaseGameEntity* GetEntityFromId(int id) const;

	// this method removes the entity from the list
	void RemoveEntity(BaseGameEntity* pEntity);

private:
	// to save the ol' fingers
	using EntityMap = std::map<int, BaseGameEntity>;


private:
	// to facilitate quick lookup the entites are stored in a std::map,
	// in which pointers to entities are cross-referenced by their identifying number
	EntityMap m_EntityMap;

	// private ctor to implement this as a singleton class
	EntityManager() {}

	// copy ctor and assignment should be private
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
};

// provide easy access to the instance of the EntityManager
#define EntityMgr EntityManager::Instance()

