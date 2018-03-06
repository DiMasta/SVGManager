#include "objects_holder.h"

ObjectsHolder::ObjectsHolder() :
	objects()
{

}

//*************************************************************************************************************
//*************************************************************************************************************


ObjectsHolder::~ObjectsHolder() {
	for (size_t objIdx = 0; objIdx < objects.size(); ++objIdx) {
		delete objects[objIdx];
	}

	objects.clear();
}

//*************************************************************************************************************
//*************************************************************************************************************

void ObjectsHolder::initObjects(int objectsCount) {
	objects.resize(objectsCount, nullptr);
}

//*************************************************************************************************************
//*************************************************************************************************************

const Objects* const ObjectsHolder::getObjectsPtr() {
	return &objects;
}

//*************************************************************************************************************
//*************************************************************************************************************

Object** ObjectsHolder::getObjectPtr(int objectIdx) {
	return objects.data() + objectIdx;
}

//*************************************************************************************************************
//*************************************************************************************************************

const Object* const ObjectsHolder::getObject(int objectIdx) {
	return objects[objectIdx];
}

//*************************************************************************************************************
//*************************************************************************************************************

int ObjectsHolder::getObjectsCount() const {
	return static_cast<int>(objects.size());
}
