#pragma once
class Face
{
public:
	Face(void);
	~Face(void);
	Point facepoint1,facepoint2;
		double lenght;
		int num;
		Cell owner, neighbor;
		Face(Point a1, Point a2,int n){
			facepoint1=a1;
			facepoint2=a2;
			num=n;
			lenght=sqrt((facepoint1.x-facepoint2.x)*(facepoint1.x-facepoint2.x)+(facepoint1.y-facepoint2.y)*(facepoint1.y-facepoint2.y));
		}
};

