/*
 * CastInfo.cpp
 *
 *  Created on: 29 gru 2014
 *      Author: lapajmar
 */

#include "CastInfo.h"

namespace RayCaster {


set<shared_ptr<Object> , Object::compare> CastInfo::objects;

CastInfo::CastInfo() {
	// TODO Auto-generated constructor stub

}

CastInfo::~CastInfo() {
	// TODO Auto-generated destructor stub
}

} /* namespace RayCaster */
