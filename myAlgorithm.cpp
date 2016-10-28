#include "myAlgorithm.h"

int getY(int y){
	return MAXY / 2 - y;
}
int getX(int x){
	return x - (MAXX / 2);
}

template<class T>
void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

/*Thuật toán Bresenham vẽ đường thẳng*/
void lineBrese(int x1, int y1, int x2, int y2, int color){
	int x, y, dX, dY, fabsdX, fabsdY, pX, pY, xE, yE;
	dX = x2 - x1;
	dY = y2 - y1;
	fabsdX = fabs((double)dX);			// Trị tuyệt đối dX
	fabsdY = fabs((double)dY);			// Trị tuyệt đối dY
	pX = (fabsdY << 1) - fabsdX;		// 2 * fasdY
	pY = (fabsdX << 1) - fabsdY;
	int constX1 = fabsdY << 1;
	int constX2 = (fabsdY - fabsdX) << 1;
	int constY1 = fabsdX << 1;
	int constY2 = (fabsdX - fabsdY) << 1;
	int xUnit, yUnit;
	float m = float(dY) / dX;	// Hệ số góc

	if (m < 0){
		xUnit = yUnit = -1;
	}
	else{
		xUnit = yUnit = 1;
	}

	if (fabsdY <= fabsdX){
		if (dX >= 0){
			x = x1;
			y = y1;
			xE = x2;
		}
		else{
			x = x2;
			y = y2;
			xE = x1;
		}
		putpixel(x, y, color);
		for (x; x < xE; x++){
			if (pX < 0) pX += constX1;
			else{
				y += yUnit;
				pX += constX2;
			}
			putpixel(x, y, color);
		}
	}
	else{
		if (dY >= 0){
			x = x1;
			y = y1;
			yE = y2;
		}
		else{
			x = x2;
			y = y2;
			yE = y1;
		}
		putpixel(x, y, color);
		for (y; y < yE; y++){
			if (pY <= 0)	pY += constY1;
			else{
				x += xUnit;
				pY += constY2;
			}
			putpixel(x, y, color);
		}
	}
}

void lineDDA(int x1, int y1, int x2, int y2, int color){
	int dX = x2 - x1;
	int dY = y2 - y1;
	int yUnit = 1, xUnit = 1;
	float x = x1, y = y1;
	int xtemp, ytemp;

	if (dX < 0)
		xUnit = -1;
	if (dY < 0)
		yUnit = -1;

	// đường thẳng đứng
	if (x1 == x2) {
		while (y != y2)
		{
			y += yUnit;
			putpixel(x, y, color);
		}
	}
	// đường ngang
	else if (y1 == y2) {
		while (x != x2){
			x += xUnit;
			putpixel(x, y, color);
		}
	}

	else if (x1 != x2 && y1 != y2){
		float m = float(dY) / dX;

		// Chạy theo x
		if (abs(dY) < abs(dX)){
			if (dX < 0){
				y = y2;
				x = x2;
				xtemp = x1;
			}
			else{
				y = y1;
				x = x1;
				xtemp = x2;
			}
			for (x; x <= xtemp; x++, y += m){
				putpixel(x, Round(y), color);
			}
		}
		// Chạy theo y
		else{
			if (dY < 0){
				x = x2;
				y = y2;
				ytemp = y1;
			}
			else{
				x = x1;
				y = y1;
				ytemp = y2;
			}
			for (y; y <= ytemp; y++, x += 1 / m){
				putpixel(Round(x), y, color);
			}
		}
	}
}

void lineMidPoint(int x1, int y1, int x2, int y2, int color){
	int x, y, dX, dY, d1, d2, fabsdX, fabsdY, xE, yE;
	dX = x2 - x1;
	dY = y2 - y1;
	fabsdX = fabs(double(dX));
	fabsdY = fabs(double(dY));
	d1 = fabsdY - (fabsdX >> 1);
	d2 = fabsdX - (fabsdY >> 1);

	int xUnit, yUnit;
	float m = float(dY) / dX;

	if (m < 0){
		xUnit = yUnit = -1;
	}
	else{
		xUnit = yUnit = 1;
	}

	if (fabsdY <= fabsdX){
		if (dX >= 0){
			x = x1;
			y = y1;
			xE = x2;
		}
		else{
			x = x2;
			y = y2;
			xE = x1;
		}
		putpixel(x, y, color);
		for (x; x < xE; x++){
			if (d1 <= 0) d1 += fabsdY;
			else{
				y += yUnit;
				d1 += (fabsdY - fabsdX);
			}
			putpixel(x, y, color);
		}
	}
	else{
		if (dY >= 0){
			x = x1;
			y = y1;
			yE = y2;
		}
		else{
			x = x2;
			y = y2;
			yE = y1;
		}
		putpixel(x, y, color);
		for (y; y < yE; y++){
			if (d2 <= 0)	d2 += fabsdX;
			else{
				x += xUnit;
				d2 += (fabsdX - fabsdY);
			}
			putpixel(x, y, color);
		}
	}

}

void circlePoint(int x0, int x, int y0, int y, int color){
	putpixel(x0 + x, y0 + y, color);
	putpixel(x0 + x, y0 - y, color);
	putpixel(x0 - x, y0 - y, color);
	putpixel(x0 - x, y0 + y, color);

	putpixel(x0 + y, y0 + x, color);
	putpixel(x0 + y, y0 - x, color);
	putpixel(x0 - y, y0 - x, color);
	putpixel(x0 - y, y0 + x, color);
}

void circleMidPoint(int x0, int y0, int r, int color){
	int x = 0;
	int y = r;
	double f = 1 - r;					// f0
	circlePoint(x0, x, y0, y, color);

	while (y > x){
		if (f < 0){
			f += ((x << 1) + 3);
		}
		else{
			f += (((x - y) << 1) + 5);
			y--;
		}
		x++;
		circlePoint(x0, x, y0, y, color);
	}
}
void veMuiTen(double start_x, double start_y, double end_x, double end_y, int color){
	double x1, x2, y1, y2;
	double arrow_lenght_(20), arrow_degrees_(0.4);
	double angle = atan2(end_y - start_y, end_x - start_x) + M_PI;
	x1 = end_x + arrow_lenght_ * cos(angle - arrow_degrees_);
	y1 = end_y + arrow_lenght_ * sin(angle - arrow_degrees_);
	x2 = end_x + arrow_lenght_ * cos(angle + arrow_degrees_);
	y2 = end_y + arrow_lenght_ * sin(angle + arrow_degrees_);
	int x4 = (x1 + x2 + end_x) / 3;
	int y4 = (y1 + y2 + end_y) / 3;
	int arr[] = { x1, y1, x2, y2, end_x, end_y, x1, y1 };
	/*Tô lại màu trắng	*/
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	fillpoly(4, arr);
}
void veTrucToaDo(){
	setcolor(WHITE);
	line(-getmaxx(), 0, getmaxx(), 0);
	line(0, -getmaxy(), 0, getmaxy());
	veMuiTen(0, 0, getmaxx() / 2 - 10, 0, WHITE);
	veMuiTen(0, 0, 0, -getmaxy() / 2, WHITE);
}

double lenghLine(int x1, int y1, int x2, int y2){
	return sqrt(double(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void biendoiTHTinhTien(double **M, int trX, int trY){
	double **V = new double *[3];
	for (int i = 0; i < 3; i++){
		V[i] = new double[3];
	}
	V[0][0] = V[1][1] = V[2][2] = 1;
	V[0][1] = V[0][2] = V[1][0] = V[1][2] = 0;
	V[2][0] = trX;
	V[2][1] = trY;

	nhanVganMaTran(M, V, 3);

	// Giải phóng vùng chớ cho ma trận V
	for (int i = 0; i < 3; i++){
		delete[] V[i];
	}
	delete[] V;
}

void biendoiTHXoay(double **M, double alpha){

	// Ma trận biến đổi
	double  **V = new double *[3];
	for (int i = 0; i < 3; i++){
		V[i] = new double[3];
	}
	V[0][0] = V[1][1] = cos(alpha);
	V[0][1] = sin(alpha);
	V[1][0] = -sin(alpha);
	V[0][2] = V[1][2] = V[2][0] = V[2][1] = 0;
	V[2][2] = 1;

	nhanVganMaTran(M, V, 3);

	// Giải phóng vùng chớ cho ma trận V
	for (int i = 0; i < 3; i++){
		delete[] V[i];
	}
	delete[] V;
}

void biendoiTHScale(double **M, double Sx, double Sy){
	// Ma trận biến đổi
	double **V = new double *[3];
	for (int i = 0; i < 3; i++){
		V[i] = new double[3];
	}
	V[0][0] = Sx;
	V[1][1] = Sy;
	V[2][2] = 1;
	V[0][1] = V[0][2] = V[1][0] = V[1][2] = V[2][0] = V[2][1] = 0;

	nhanVganMaTran(M, V, 3);

	// Giải phóng vùng chớ cho ma trận V
	for (int i = 0; i < 3; i++){
		delete[] V[i];
	}
	delete[] V;
}
void nhanVganMaTran(double **M, double  **X, int n){
	// Tạo ma trận KQ
	double **KQ = new double *[n];
	for (int i = 0; i < n; i++){
		KQ[i] = new double[n];
	}

	nhanMaTran(M, X, KQ, n, n, n);

	// Gán ma trận kết quả lại cho ma trận M
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			M[i][j] = KQ[i][j];
		}
	}

	// Giải phóng vùng nhớ cho KQ
	for (int i = 0; i < n; i++){
		delete[] KQ[i];
	}
	delete[] KQ;
}

void nhanMaTran(double **A, double **B, double **C, int da, int ca, int cb){
	for (int i = 0; i < da; i++){
		for (int j = 0; j < cb; j++){
			C[i][j] = 0;
			for (int k = 0; k < ca; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void xuatMaTran(double **A, int n, int m){
	cout.setf(ios::left);
	for (int i = 0; i < n; i++){
		cout << "[ ";
		for (int j = 0; j < m; j++){
			cout << setw(20) << A[i][j];
		}
		cout << " ]" << endl;
	}
}

void deleteMatrix(double **M, int d, int c){
	for (int i = 0; i < d; i++){
		delete[] M[i];
	}
	delete[] M;
}

void swap(float &a, float &b){
	int temp = a;
	a = b;
	b = temp;
}

void sapXepTangDan(float Arr[], int n){
	for (int i = 0; i < n - 1; i++){
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (Arr[j] < Arr[min]){
				min = j;
			}
		}
		swap(Arr[min], Arr[i]);
	}
}

void boundaryFill(int x, int y, int fillColor, int BColor){
	stack<Point> st;
	Point P = { x, y };
	st.push(P);
	while (!st.empty()){
		Point Q = st.top();
		st.pop();
		int color = getpixel(Q.x, Q.y);
		if (color != fillColor && color != BColor){
			putpixel(Q.x, Q.y, fillColor);
			Point t;
			t.x = Q.x + 1; t.y = Q.y;
			st.push(t);
			t.x = Q.x - 1; t.y = Q.y;
			st.push(t);
			t.x = Q.x; t.y = Q.y + 1;
			st.push(t);
			t.x = Q.x; t.y = Q.y - 1;
			st.push(t);
		}
	}
}