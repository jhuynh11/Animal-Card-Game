/*
 * QueryResult.h
 *
 *  Created on: Dec 6, 2015
 *      Author: Kyle, Justin
 */

#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <string>

class QueryResult {
private:
	int row, col; //wolf + hare
	std::string playerName; //bear and deer
	int newRow, newCol; //hare

public:
	QueryResult() = default;
	QueryResult(std::string playerName);
	QueryResult(int row, int col);
	QueryResult(int row, int col, int newRow, int newCol);
	void getOriginalPoint(int& row, int& col);
	void getNewPoint(int& newrow, int& newcol);
	std::string getName();
};

#endif /* QUERYRESULT_H_ */
