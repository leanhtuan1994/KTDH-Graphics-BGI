#pragma once
#include "graphics.h"
#include "myAlgorithm.h"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;



typedef struct edge{
	int yMin;
	float xIntersect;		// Hoang do giao diem cua canh va dong quet
	float dxPerScan; // 1/m
	int deltaY;
}EDGE;


class polygon
{
private:
	vector <Point> listVertex;
	vector <EDGE> listEdge;
	vector<float> listIntersect;

	vector<Point> listPt;

public:

	polygon();
	~polygon();

	void clickInput();
	void keyInput();  
	void draw(int color);

	void translation(int trX, int trY);
	void rotate(int pX, int pY, double alpha);
	void scale(double sX, double sY);
	void composingTransformation();

	void putEdgeInList(Point p1, Point p2, int nextY);					// Đặt 1 cạnh vào danh sách cạnh
	int findNextY(int id);												// Tìm 1 đỉnh kế tiếp sao cho không nằm cùng với đường thẳng đang xét
	void makeSortedEdge(int &topScan, int &bottomScan);					// Tạo danh sách cạnh từ các đỉnh đã có
	void updateActiveEdgeList(int yScan, int &firstId, int &lastId);	// Cập nhật 2 con trỏ
	void findXIntersection(int fristId, int lastId);
	void updateEdgeList(int firstId, int lastId);
	void shortEdgeList();
	void shotOnXIntersect();
	void fillLine(int yScan);


	void scanLineFill(int color);

	void remove();

	
	bool isInside(int x, int y);
	Point findPointInside();

	void floodFill(int fillColor);
};
