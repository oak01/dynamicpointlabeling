/*
 * Solution.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: oakile
 */

#include "Solution.h"

namespace labelplacement {

Solution::Solution(ConflictGraph* conflictGraph) {
	this->conflictGraph = conflictGraph;
	this->labelPlacements = __null;
}

Solution::~Solution() {
	delete[] labelPlacements;
}

ConflictGraph* Solution::getConflictGraph() {
	return this->conflictGraph;
}
void Solution::setConflictGraph(ConflictGraph* conflictGraph) {
	this->conflictGraph = conflictGraph;
}

int* Solution::getLabelPlacements() {
	return this->labelPlacements;
}
void Solution::setLabelPlacements(int* labelPlacements) {
	this->labelPlacements = labelPlacements;
}

int Solution::getConflictSize() {
	return getConflictSize(this->conflictGraph);
}

int Solution::getConflictSize(ConflictGraph* conflictGraph) {
	int conflictSize = 0;
	for (int i = 0;
			i < conflictGraph->getConflictGraphOfPoints()->getVertexNumber();
			i++) {
		int position1 = labelPlacements[i];
		int posIx1 = i * conflictGraph->getPositionNumberPerPoint() + position1;
		for (int j = 0;
				j < conflictGraph->getConflictGraphOfPoints()->getVertexNumber();
				j++) {
			int position2 = labelPlacements[j];
			int posIx2 = j * conflictGraph->getPositionNumberPerPoint() + position2;
			if (conflictGraph->getConflictGraphOfPositions()->getAdjacencyMatrix()[posIx1][posIx2]) {
				conflictSize++;
				break;
			}
		}
	}
	return conflictSize;
}
} /* namespace labelplacement */
