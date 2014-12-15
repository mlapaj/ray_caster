/*
 * Map.h
 *
 *  Created on: 15 gru 2014
 *      Author: cod3r
 */

#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include <vector>
using namespace std;

class Map {
public:
	int height;
	int width;
	vector<vector<int> > MapData;
	Map(int height,int width,vector<vector<int> > MapData);
	void PrintMap();
	virtual ~Map();
};

#endif /* MAP_H_ */
