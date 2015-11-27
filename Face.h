#pragma once
#include "Point.h"

class Face
{
public:
	Face(void);
	~Face(void);
		double lenght;
		int num;
		int owner, neighbor;
		int pointid1,pointid2;
		Face(int a1, int a2, int n){
			pointid1=a1;
			pointid2=a2;
			num=n;
		}

};

