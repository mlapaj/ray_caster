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

class mapLoader;
class map {
public:
	void PrintMap();
	int getHeight();
	int getWidth();
	virtual ~map();
	friend class mapLoader;
private:
	int height;
	int width;
	const int blockSize = 64;
	vector<vector<int> > MapData;
	map(int height,int width,vector<vector<int> > MapData);
};

#endif /* MAP_H_ */
