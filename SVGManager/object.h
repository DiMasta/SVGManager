#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>
#include <string>

#include "game_constants.h"

class Object {
public:
	Object();
	virtual ~Object();

	int getId() const;
	int getFill() const;
	ObjectType getType() const;
	std::string getColor() const;
	float getXCoord() const;
	float getYCoord() const;
	float getContour() const;

	void setId(int id);
	void setType(ObjectType type);
	void setColor(const std::string& color);
	void setXCoord(float xCoord);
	void setYCoord(float yCoord);
	void setContour(float contour);
	void setFill(int fill);

private:
	int id;
	int fill;
	ObjectType type;
	std::string color;
	float xCoord;
	float yCoord;
	float contour;
};

typedef std::vector<Object*> Objects;

#endif // __OBJECT_H__

