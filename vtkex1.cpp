#include "stdafx.h"
#include "Cell.h"
#include "Point.h"
#include<iostream>
#include <vector>
#include <list>
#include<fstream>
#include<cmath>
#include "Face.h"
using namespace std;
	ofstream out("out.vtk",ios::out);

	vector<Point> points;
	vector<Cell> cells;
	int gl=0;



	void split(Point a1,Point a2, Point a3, Point a4){
	double centrx,centry;
	centrx=(a1.x+a2.x+a3.x+a4.x)/4;
	centry=(a1.y+a2.y+a3.y+a4.y)/4;
	Point centr(centrx,centry,points.size());
		points.push_back(centr);

			points.push_back(Point(centr.x,a1.y,points.size()));
			points.push_back(Point(a2.x,centr.y,points.size()));
			points.push_back(Point(centr.x,a4.y,points.size()));
			points.push_back(Point(a3.x,centr.y,points.size()));
			
			cells.push_back(Cell(a1.num,points.size()-4,points.size()-1,centr.num));
			cells.push_back(Cell(points.size()-4,a2.num,centr.num,points.size()-3));
			cells.push_back(Cell(centr.num,points.size()-3,points.size()-2,a4.num));
			cells.push_back(Cell(points.size()-1,centr.num,a3.num,points.size()-2));

}
	void savevtk(){
		int i;
		out<<"# vtk DataFile Version 2.1\nmerger Visser/Rosendal\nASCII\nDATASET POLYDATA\nPOINTS "<<points.size()<<" float\n";
		for(i=0;i<points.size();i++)
			out<<points[i].x<<" "<<points[i].y<<" 0"<<endl;

		out<<"POLYGONS "<<cells.size()-gl<<" "<<5*(cells.size()-gl)<<endl;
		for(i=0;i<cells.size();i++)
			if(cells[i].switcher)
				out<<"4 "<<cells[i].pointnum0<<" "<<cells[i].pointnum1<<" "<<cells[i].pointnum3<< " "<<cells[i].pointnum2<<endl;
	}


void main(){
	int splitcell[4];
	int i,j,n=5;
	splitcell[0]=10;
	splitcell[1]=17;
	splitcell[2]=20;
	splitcell[3]=27;
	vector<Face> faces;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			points.push_back(Point(j,i,n*i+j));
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			faces.push_back(Face(points[n*i+j],points[n*i+j+1],faces.size()));
	for(i=0;i<n-1;i++)
		for(j=0;j<n;j++)
			faces.push_back(Face(points[n*i+j],points[n*i+j+n],faces.size()));
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
			cells.push_back(Cell(n*i+j,n*i+j+1,n*i+j+n,n*i+j+1+n));

	for(i=0;i<cells.size();i++)
		for(j=0;j<4;j++)
		if(i==splitcell[j]){
			split(points[cells[i].pointnum0],points[cells[i].pointnum1],points[cells[i].pointnum2],points[cells[i].pointnum3]);
			cells[i].switcher=false;
			gl++;
		}
		savevtk();
}
