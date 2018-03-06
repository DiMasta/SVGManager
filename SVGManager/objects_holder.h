#ifndef __OBJECTS_HOLDER_H__
#define __OBJECTS_HOLDER_H__

#include "object.h"

class ObjectsHolder {
public:
	ObjectsHolder();
	~ObjectsHolder();

	void initObjects(int objectsCount);

	const Objects* const getObjectsPtr();

	Object** getObjectPtr(int objectIdx);

	const Object* const getObject(int objectIdx);

	int getObjectsCount() const;

private:
	Objects objects;
};

#endif //__OBJECTS_HOLDER_H__
