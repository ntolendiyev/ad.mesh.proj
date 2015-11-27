#pragma once
class Cell
{
public:
	Cell(void);
	~Cell(void);
		int cellface1,cellface2,cellface3,cellface4;
		int num;
		bool switcher;
		Cell(int f1, int f2, int f3, int f4,int n){
			cellface1=f1;
			cellface2=f2;
			cellface3=f3;
			cellface4=f4;
			num=n;
			switcher=true;}
};

