#include "Circle.h"


Circle::Circle(){
	I.x = I.y = 0;
	r = 0;
}


Circle::~Circle()
{
}


void Circle::inputKey(){
	while (1){
		fflush(stdin);
		cout << "TOA DO TAM (X,Y): ";
		cin >> I.x >> I.y;
		I.y = -I.y;
		if (cin.fail()) cin.clear();
		else break;
	}
	while (1){
		fflush(stdin);
		cout << "BAN KINH: ";
		cin >> r;
		if (r < 1 || cin.fail()){
			cout << "DU LIEU KHONG DUNG. VUI LONG KIEM TRA LAI" << endl;
			cin.clear();
		}
		else break;
	}
}

void Circle::inputClick(){
	bool checkClick = 0;
	int x, y;
	while (1){
		if (ismouseclick(WM_LBUTTONDOWN)){
			if (checkClick == 0){
				getmouseclick(WM_LBUTTONDOWN, I.x, I.y);
				I.x = getX(I.x);
				I.y = -getY(I.y);
				cout << "I(" << I.x << "," << -I.y << ")" << endl;
				checkClick++;
			}
			else {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				x = getX(x);
				y = -getY(y);
				r = lenghLine(x, y, I.x, I.y);
				cout << "R = " << r << endl;
				break;
			}
		}
	}
}

void Circle::draw(int color){
	if (r > 0){
		circleMidPoint(I.x, I.y, r, color);
		putpixel(I.x, I.y, color);
	}
}

void Circle::remove(){
	I.x = I.y = 0;
	r = 0;
}

bool Circle::isInside(int x, int y){
	return lenghLine(x, y, I.x, I.y) < r ? true : false;
}

void Circle::floodFill(int fillColor){
	stack<Point> st;
	st.push(I);
	while (!st.empty()){
		Point Q = st.top();
		st.pop();
		if (getpixel(Q.x, Q.y) != fillColor && isInside(Q.x, Q.y)){
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