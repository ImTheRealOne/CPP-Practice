#pragma once


enum JigsawEdgeType
{
	FLAT, MALE, FEMALE
};
class JigsawPieceNode
{
private:
	int pieceID;
	int pieceRotation;
	int x;
	int y;

	JigsawPieceNode * jigsawPieceNodeArray[4];

	JigsawPieceNode* upPiece;
	JigsawPieceNode* downPiece;
	JigsawPieceNode* leftPiece;
	JigsawPieceNode* rightPiece;

	JigsawEdgeType * jigsawEdgeTypeArray[4];

	JigsawEdgeType upEdge;
	JigsawEdgeType downEdge;
	JigsawEdgeType leftEdge;
	JigsawEdgeType rightEdge;


public:
	JigsawPieceNode();
	JigsawPieceNode(int i, int j, int up, int down, int left, int right) :
		x(i),
		y(j),
		upEdge(JigsawEdgeType(up)),
		downEdge(JigsawEdgeType(down)),
		leftEdge(JigsawEdgeType(left)),
		rightEdge(JigsawEdgeType(right)) {};
	~JigsawPieceNode();

	JigsawPieceNode(const JigsawPieceNode& otherNode);


	void setUpPiece(JigsawPieceNode * newUpPiece);
	void setDownPiece(JigsawPieceNode * newDownPiece);
	void setLeftPiece(JigsawPieceNode * newLeftPiece);
	void setRightPiece(JigsawPieceNode * newRightPiece);

	bool fitWidth(JigsawEdgeType a, JigsawEdgeType b);
	int getRotation() const;

};

