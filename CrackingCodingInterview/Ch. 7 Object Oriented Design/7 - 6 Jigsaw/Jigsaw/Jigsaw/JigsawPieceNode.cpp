#include "stdafx.h"
#include "JigsawPieceNode.h"


JigsawPieceNode::JigsawPieceNode()
{
}


JigsawPieceNode::~JigsawPieceNode()
{
}

JigsawPieceNode::
JigsawPieceNode(const JigsawPieceNode & otherNode)
{
	pieceID = otherNode.pieceID;
	pieceRotation = otherNode.pieceRotation;
	x = otherNode.x;
	y = otherNode.y;

	for (int i = 0; i < 4; i++) {
		jigsawPieceNodeArray[i] = otherNode.jigsawPieceNodeArray[i];
		jigsawEdgeTypeArray[i] = jigsawEdgeTypeArray[i];
	}
}

void JigsawPieceNode::setUpPiece(JigsawPieceNode* newUpPiece) {
	upPiece = newUpPiece;
}
void JigsawPieceNode::setDownPiece(JigsawPieceNode* newDownPiece) {
	upPiece = newDownPiece;
}
void JigsawPieceNode::setLeftPiece(JigsawPieceNode* newLeftPiece) {
	upPiece = newLeftPiece;
}
void JigsawPieceNode::setRightPiece(JigsawPieceNode* newRightPiece) {
	upPiece = newRightPiece;
}

bool JigsawPieceNode::fitWidth(JigsawEdgeType a, JigsawEdgeType b) {
	if (a == JigsawEdgeType::FEMALE && b == JigsawEdgeType::MALE) {
		return true;
	}
	else if (a == JigsawEdgeType::MALE && b == JigsawEdgeType::FEMALE) {
		return true;
	}
	else
	{
		return false;
	}
}

int JigsawPieceNode::getRotation() const {
	return pieceRotation;
}
