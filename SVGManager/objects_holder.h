#ifndef __OBJECTS_HOLDER_H__
#define __OBJECTS_HOLDER_H__

#include "object.h"

class ObjectsHolder {
public:
	ObjectsHolder();
	~ObjectsHolder();

	void initObjects(int objectsCount);

	Object** getObjectPtr(int objectIdx);

	const Objects* const getObjectsPtr() const;

	const Object* const getObject(int objectIdx) const;

	int getObjectsCount() const;

private:
	Objects objects;
};

#endif //__OBJECTS_HOLDER_H__
