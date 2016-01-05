/*
 * QueryResult.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: Kyle
 */

#include "QueryResult.h"

QueryResult::QueryResult(std::string playerName) : playerName(playerName),
													row(0), col(0), newRow(0), newCol(0){
}

QueryResult::QueryResult(int row, int col) : row(row), col(col),
											newRow(0), newCol(0){
}
QueryResult::QueryResult(int row, int col, int newRow, int newCol) : row(row), col(col),
																	newRow(newRow), newCol(newCol){

}
std::string QueryResult::getName(){
	return playerName;
}

void QueryResult::getOriginalPoint(int& row, int& col){
	row = this->row;
	col = this->col;
}

void QueryResult::getNewPoint(int& newRow, int& newCol){
	newRow = this->newRow;
	newCol = this->newCol;
}
