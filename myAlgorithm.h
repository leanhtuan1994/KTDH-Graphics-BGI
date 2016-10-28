#pragma once
#include "graphics.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stack>
using namespace std;
#define M_PI	3.1415926535897932384626433832795
#define MAXX 800
#define MAXY 600
#define MAX 3
#define Round(a) int(a + 0.5)
#define min(a, b)	(((a) < (b)) ? (a) : (b))
#define max(a, b)	(((a) > (b)) ? (a) : (b))
#define INF 10000

typedef struct point{
	int x, y;
}Point;


int getY(int y);
int getX(int x);
void veMuiTen(double start_x, double start_y, double end_x, double end_y, int color);
void veTrucToaDo();
void nhanMaTran(double **A, double **B, double **C, int da, int ca, int cb);
void xuatMaTran(double **A, int n, int m);
void nhanVganMaTran(double **M, double  **X, int n);
void lineBrese(int x1, int y1, int x2, int y2, int color);
void lineDDA(int x1, int y1, int x2, int y2, int color);
void lineMidPoint(int x1, int y1, int x2, int y2, int color);
void circlePoint(int x0, int x, int y0, int y, int color);
void circleMidPoint(int x0, int y0, int r, int color);
double lenghLine(int x1, int y1, int x2, int y2);
void biendoiTHScale(double **M, double Sx, double Sy);
void biendoiTHXoay(double **M, double alpha);
void biendoiTHTinhTien(double **M, int trX, int trY);
void deleteMatrix(double **M, int d, int c);
void swap(float &a, float &b);
void sapXepTangDan(float Arr[], int n);

void boundaryFill(int x, int y, int fillColor, int BColor);