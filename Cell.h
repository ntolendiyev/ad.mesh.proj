#pragma once
class Cell
{
public:
	Cell(void);
	~Cell(void);
	double x1,x2,y1,y2,cx,cy;
		int pointnum0,pointnum1,pointnum2,pointnum3;
		bool switcher;
		Cell(int n1,int n2,int n3,int n4){
			pointnum0=n1;pointnum1=n2;pointnum2=n3;pointnum3=n4;
			switcher=true;
		}
};

