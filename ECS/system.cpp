#include "system.h"

SystemId getUniqueSysId() {
	static SystemId idCounter = 0;
	return idCounter++;
}

void System::subscribeEntity(Entity * e) {
	_entities.insert(e);
}

void System::unsubscribeEntity(Entity * e)
{
	_entities.erase(_entities.find(e));
}
