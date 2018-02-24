#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "game_constants.h"

class Object {
public:
	Object();
	virtual ~Object();

	int getId() const;
	ObjectType getType() const;
	std::string getColor() const;
	float getXCoord() const;
	float getYCoord() const;

	void setId(int id);
	void setType(ObjectType type);
	void setColor(const std::string& color);
	void setXCoord(float xCoord);
	void setYCoord(float yCoord);

private:
	int id;
	ObjectType type;
	std::string color;
	float xCoord;
	float yCoord;
};

#endif // __OBJECT_H__

