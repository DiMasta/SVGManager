#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "object.h"

class Circle : public Object {
public:
	Circle();
	~Circle();

	float getRadius() const;

	void setRadius(float radius);

private:
	float radius;
};

#endif // !__CIRCLE_H__
