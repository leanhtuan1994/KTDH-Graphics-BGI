#include "Polygon.h"
#include "Circle.h"
#include <iostream>

using namespace std;

void initMainMenu();
void initVeHinhMenu();
void initVeHinhTronMenu();
void initBienDoiMenu();
void initToMauDGMenu();

bool veHinh(polygon &p);
void bienDoi(polygon &p);
bool veHinhTron(Circle &c);
void toMauDG(polygon &p);
void toMauHinhTron(Circle &c);

int main(){
	initwindow(800, 600);
	setviewport(getmaxx() / 2, getmaxy() / 2, getmaxx(), getmaxy(), 0);
	veTrucToaDo();
	int luaChon = 0;
	polygon p;
	Circle c;

	bool checkPolygon = false;
	bool checkCircle = false;

	while (1){
		system("cls");
		initMainMenu();
		do{
			fflush(stdin);
			cout << "LUA CHON: ";
			cin >> luaChon;
			if (luaChon < 0 || luaChon > 6 || cin.fail()) {
				cout << "LUA CHON KHONG HOP LE. VUI LONG NHAP LAI!" << endl;
				cin.clear();
			}
			else break;
		} while (1);

		if (luaChon == 6) break;
		switch (luaChon){
		case 1:
			checkPolygon = veHinh(p);
			if (checkPolygon){
				checkCircle = false;
				c.remove();
			}
			break;
		case 2:
			checkCircle = veHinhTron(c);
			if (checkCircle == true){
				checkPolygon = false;
				p.remove();
			}
			break;
		case 3:
			if (checkPolygon){
				bienDoi(p);
			}
			else{
				cout << "KHONG TON TAI HINH DA GIAC!" << endl;
				Sleep(500);
			}
			break;

		case 4:
			if (checkPolygon)
				toMauDG(p);
			else cout << "KHONG TON TAI HINH DA GIAC!" << endl;
			break;
		case 5:
			if (checkCircle){
				toMauHinhTron(c);
			}
			else cout << "KHONG TON TAI HINH TRON!" << endl;
			break;
		}
	}
	return 0;
}

void initMainMenu(){
	cout << "			MENU			"					<< endl;
	cout << "		1. VE HINH DA GIAC	"					<< endl;
	cout << "		2. VE HINH TRON	"						<< endl;
	cout << "		3. CAC PHEP BIEN DOI"					<< endl;
	cout << "		4. TO MAU DA GIAC			"			<< endl;
	cout << "		5. TO MAU HINH TRON			"			<< endl;
	cout << "		6. THOAT	" << endl;
	cout << "===================================================================="	<< endl;
}

void initVeHinhMenu(){
	cout << "			MENU VE HINH DA GIAC"				<< endl;
	cout << "		1. NHAP TOA DO TU BAN PHIM "			<< endl;
	cout << "		2. CLICK MAN HINH CHON TOA DO"			<< endl;
	cout << "		3. QUAY LAI"							<< endl;
	cout << "==================================================================="	<< endl;
}

void initToMauDGMenu(){
	cout << "			MENU TO MAU DA GIAC	"			<< endl;
	cout << "		1. TO MAU SCAN-LINE "				<< endl;
	cout << "		2. TO MAU LOANG DA GIAC "			<< endl;
	cout << "		3. TO MAU THEO VUNG BANG CLICK"		<< endl;
	cout << "		4. QUAY LAI"						<< endl;
	cout << "===================================================================" << endl;
}

void initVeHinhTronMenu(){
	cout << "			MENU VE HINH TRON		"			<< endl;
	cout << "		1. NHAP TOA DO TU BAN PHIM "			<< endl;
	cout << "		2. CLICK MAN HINH CHON TOA DO"			<< endl;
	cout << "		3. QUAY LAI"							<< endl;
	cout << "=================================================================="<< endl;
}

void initBienDoiMenu(){
	cout << "			MENU BIEN DOI HINH			"	<< endl;
	cout << "		1. BIEN DOI TINH TIEN "				<< endl;
	cout << "		2. BIEN DOI XOAY	"				<< endl;
	cout << "		3. BIEN DOI TY LE"					<< endl;
	cout << "		4. DOI XUNG QUA TRUC OX"			<< endl;
	cout << "		5. DOI XUNG QUA TRUC OY"			<< endl;
	cout << "		6. DOI XUNG QUA TAM O "				<< endl;
	cout << "		7. DOI XUNG QUA 1 DIEM"				<< endl;
	cout << "		8. BIEN DOI TONG HOP"				<< endl;
	cout << "		9. QUAY LAI"						<< endl;
	cout << "================================================================" << endl;
}

bool veHinh(polygon &p){
	int luaChon;
	system("cls");
	initVeHinhMenu();
	while (1){
		fflush(stdin);
		cout << "LUA CHON: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 3 || cin.fail()){
			cout << "LUA CHON KHONG HOP LE. VUI LONG NHAP LAI!" << endl;
			cin.clear();
		}else break;
	}
	switch (luaChon){
	case 1:
		cleardevice();
		setbkcolor(BLACK);
		veTrucToaDo();
		p.keyInput();
		p.draw(WHITE);
		break;
	case 2:
		cleardevice();
		setbkcolor(BLACK);
		veTrucToaDo();
		cout << "CLICK CHUOT TRAI DE CHON DINH. CLICK CHUOT PHAI DE KET THUC" << endl;
		p.clickInput();
		p.draw(WHITE);
		break;
	case 3:
		return false;
		break;
	}
	return true;
}

bool veHinhTron(Circle &c){
	int luaChon;
	system("cls");
	initVeHinhMenu();
	while (1){
		fflush(stdin);
		cout << "LUA CHON: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 3 || cin.fail()){
			cout << "LUA CHON KHONG HOP LE. VUI LONG NHAP LAI!" << endl;
			cin.clear();
		}
		else break;
	}
	switch (luaChon){
	case 1:
		cleardevice();
		setbkcolor(BLACK);
		veTrucToaDo();
		c.inputKey();
		c.draw(WHITE);
		break;
	case 2:
		cleardevice();
		setbkcolor(BLACK);
		veTrucToaDo();
		cout << "CLICK CHUOT TRAI LAN 1 DE CHON TAM" << endl;
		cout << "CLICK CHUOT TRAI LAN 2 DE DO DAI BAN KINH TINH TU TAM" << endl;
		c.inputClick();
		c.draw(WHITE);
		break;
	case 3:
		return false;
		break;
	}
	return true;
}
void bienDoi(polygon &p){
	while (1){
		int luaChon;
		system("cls");
		initBienDoiMenu();
		while (1){
			fflush(stdin);
			cout << "LUA CHON: ";
			cin >> luaChon;
			if (luaChon < 0 || luaChon > 9 || cin.fail()){
				cout << "LUA CHON KHONG HOP LE. VUI LONG NHAP LAI!" << endl;
				cin.clear();
			}
			else break;
		}

		switch (luaChon){
		case 1:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			cout << "BIEN DOI TINH TIEN" << endl;
			int trX, trY;
			while (1){
				fflush(stdin);
				cout << "NHAP DO DOI X: ";
				cin >> trX;
				cout << "NHAP DO DOI Y: ";
				cin >> trY;
				trY = -trY;
				if (cin.fail()) cin.clear();
				else break;
			}
			p.translation(trX, trY);
			p.draw(RED);
			system("pause");
			break;

		case 2:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			cout << "BIEN DOI XOAY" << endl;
			int pX, pY;
			double alpha;
			while (1){
				fflush(stdin);
				cout << "TAM DOI XUNG (x,y): ";
				cin >> pX >> pY;
				pY = -pY;
				if (cin.fail()) cin.clear();
				else break;
			}
			while (1){
				fflush(stdin);
				cout << "GOC XOAY: ";
				cin >> alpha;
				alpha = -alpha;
				alpha = alpha*(M_PI / 180);
				if (cin.fail()) cin.clear();
				else break;
			}
			putpixel(pX, pY, RED);
			p.rotate(pX, pY, alpha);
			p.draw(RED);
			system("pause");
			break;
		case 3:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			cout << "BIEN DOI TY LE" << endl;
			double sX, sY;
			while (1){
				fflush(stdin);
				cout << "TI LE SX: ";
				cin >> sX;
				cout << "TI LE SY: ";
				cin >> sY;
				if (cin.fail()) cin.clear();
				else break;
			}
			p.scale(sX, sY);
			p.draw(RED);
			system("pause");
			break;
		case 4:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			sX = 1, sY = -1;
			p.scale(sX, sY);
			p.draw(RED);
			system("pause");
			break;
		case 5:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			sX = -1, sY = 1;
			p.scale(sX, sY);
			p.draw(RED);
			system("pause");
			break;
		case 6:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			sX = -1, sY = -1;
			p.scale(sX, sY);
			p.draw(RED);
			system("pause");
			break;
		case 7:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			system("cls");
			cout << "BIEN DOI XOAY" << endl;
			while (1){
				fflush(stdin);
				cout << "TAM DOI XUNG (x,y): ";
				cin >> pX >> pY;
				pY = -pY;
				if (cin.fail()) cin.clear();
				else break;
			}
			alpha = 180;
			alpha = alpha*(M_PI / 180);
			putpixel(pX, pY, RED);
			p.rotate(pX, pY, alpha);
			p.draw(RED);
			system("pause");
			break;
		case 8:
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			p.composingTransformation();
			p.draw(YELLOW);
			system("pause");
			break;
		case 9: 
			cleardevice();
			setbkcolor(BLACK);
			veTrucToaDo();
			p.draw(WHITE);
			return;
			break;
		}
	}
}

void toMauDG(polygon &p){
	int luaChon, x, y, myColor;
	cleardevice();
	setbkcolor(BLACK);
	veTrucToaDo();
	p.draw(WHITE);
	system("cls");
	initToMauDGMenu();

	while (1){
		cout << "LUA CHON: ";
		cin >> luaChon;
		if (luaChon < 0 || luaChon > 4 || cin.fail()){
			cout << "LUA CHON KHONG HOP LE. VUI LONG KIEM TRA LAI " << endl;
			cin.clear();
		}	else break;
	}

	if (luaChon == 4) return;

	while (1){
		cout << "MA MAU < 0-15 > : ";
		cin >> myColor;
		if (myColor < 0 || myColor > 15 || cin.fail()){
			cout << "MA MAU KHONG HOP LE. VUI LONG KIEM TRA LAI " << endl;
			cin.clear();
		}
		else break;
	}

	switch (luaChon){
	case  1:
		p.scanLineFill(myColor);
		p.draw(WHITE);
		break;
	case 2:
		p.floodFill(myColor);
		p.draw(WHITE);
		break;
	case 3:
		cout << "CLICK TRAI VAO VUNG CAN TO " << endl;
		cout << "CLICK PHAI DE KET THUC TO " << endl;
		cout << "....." << endl;
		while (1){
			if (ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				x = getX(x);
				y = -getY(y);
				boundaryFill(x, y, myColor, WHITE);
			}
			if (ismouseclick(WM_RBUTTONDOWN)){
				clearmouseclick(WM_RBUTTONDOWN);
				break;
			}
		}
		break;
	}
}

void toMauHinhTron(Circle &c){
	cleardevice();
	setbkcolor(BLACK);
	veTrucToaDo();
	c.draw(WHITE);
	int myColor;
	while (1){
		cout << "MA MAU < 0-15 > : ";
		cin >> myColor;
		if (myColor < 0 || myColor > 15 || cin.fail()){
			cout << "MA MAU KHONG HOP LE. VUI LONG KIEM TRA LAI " << endl;
			cin.clear();
		}
		else break;
	}
	c.floodFill(myColor);
	c.draw(WHITE);
}