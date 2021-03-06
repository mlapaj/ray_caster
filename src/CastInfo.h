/*
 * CastInfo.h
 *
 *  Created on: 29 gru 2014
 *      Author: lapajmar
 */

#ifndef CASTINFO_H_
#define CASTINFO_H_

#include <set>
#include <memory>

#include "Object.h"
using namespace std;

namespace RayCaster {

class CastInfo {
public:
	static set<shared_ptr<Object>, Object::compare > objects;
	double distance;
	int sliceNo;
	int textureNumber;
	CastInfo();
	virtual ~CastInfo();
};

} /* namespace RayCaster */

#endif /* CASTINFO_H_ */
