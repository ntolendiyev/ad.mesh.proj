#include "stdafx.h"
#include "Cell.h"
#include "Point.h"
#include "Face.h"
#include<iostream>
#include <vector>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

	vector<Point> points;
	vector<Face> faces;
	vector<Cell> cells;
	int gl=0;

	void split(Cell spcell){
	double centrx,centry;
	centrx=((points.at(faces.at(spcell.cellface1).pointid1)).x+(points.at(faces.at(spcell.cellface1).pointid2)).x)/2;
	centry=((points.at(faces.at(spcell.cellface3).pointid1)).y+(points.at(faces.at(spcell.cellface3).pointid2)).y)/2;
	Point centr(centrx,centry,points.size());
		points.push_back(centr);
		points.push_back(Point(centr.x,points.at(faces.at(spcell.cellface1).pointid1).y,points.size()));
		points.push_back(Point(points.at(faces.at(spcell.cellface1).pointid2).x,centr.y,points.size()));
		points.push_back(Point(centr.x,points.at(faces.at(spcell.cellface3).pointid2).y,points.size()));
		points.push_back(Point(points.at(faces.at(spcell.cellface1).pointid1).x,centr.y,points.size()));
		Face* spfaces=new Face[12];
		spfaces[0]=Face(faces.at(spcell.cellface1).pointid1,points.size()-4,faces.size());
		faces.push_back(spfaces[0]);
		spfaces[1]=Face(points.size()-4,faces.at(spcell.cellface1).pointid2,faces.size());
		faces.push_back(spfaces[1]);
		spfaces[2]=Face(points.size()-1,centr.num,faces.size());
		faces.push_back(spfaces[2]);
		spfaces[3]=Face(centr.num,points.size()-3,faces.size());
		faces.push_back(spfaces[3]);
		spfaces[4]=Face(faces.at(spcell.cellface2).pointid1,points.size()-2,faces.size());
		faces.push_back(spfaces[4]);
		spfaces[5]=Face(points.size()-2,faces.at(spcell.cellface2).pointid2,faces.size());
		faces.push_back(spfaces[5]);
		spfaces[6]=Face(faces.at(spcell.cellface1).pointid1,points.size()-1,faces.size());
		faces.push_back(spfaces[6]);
		spfaces[7]=Face(points.size()-4,centr.num,faces.size());
		faces.push_back(spfaces[7]);
		spfaces[8]=Face(faces.at(spcell.cellface1).pointid2,points.size()-3,faces.size());
		faces.push_back(spfaces[8]);
		spfaces[9]=Face(points.size()-1,faces.at(spcell.cellface2).pointid1,faces.size());
		faces.push_back(spfaces[9]);
		spfaces[10]=Face(centr.num,points.size()-2,faces.size());
		faces.push_back(spfaces[10]);
		spfaces[11]=Face(points.size()-3,faces.at(spcell.cellface2).pointid2,faces.size());
		faces.push_back(spfaces[11]);
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				cells.push_back(Cell(spfaces[2*i+j].num,spfaces[2*i+j+2].num,spfaces[6+3*i+j].num,spfaces[7+3*i+j].num,cells.size()));
		delete[] spfaces;
}	
	void savevtk(string file){
		ofstream out(file,ios::out);
		out<<"# vtk DataFile Version 2.1\nmerger Visser/Rosendal\nASCII\nDATASET POLYDATA\nPOINTS "<<points.size()<<" float\n";
		for(int i=0;i<points.size();i++)
			out<<points.at(i).x<<" "<<points.at(i).y<<" 0"<<endl;
		out<<"POLYGONS "<<cells.size()-gl<<" "<<5*(cells.size()-gl)<<endl;
		for(int i=0;i<cells.size();i++)
			if(cells[i].switcher)
				out<<"4 "<<faces.at(cells.at(i).cellface1).pointid1<<" "<<faces.at(cells.at(i).cellface1).pointid2<<" "<<faces.at(cells.at(i).cellface2).pointid2<< " "<<faces.at(cells.at(i).cellface2).pointid1<<endl;
	}
void main(){
	int splitcell[4];
	int n=5;
	splitcell[0]=10;
	splitcell[1]=17;
	splitcell[2]=20;
	splitcell[3]=27;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			points.push_back(Point(j,i,n*i+j));
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			faces.push_back(Face(n*i+j,n*i+j+1,faces.size()));
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n;j++)
			faces.push_back(Face(n*i+j,n*i+j+n,faces.size()));
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1;j++)
			cells.push_back(Cell((n-1)*i+j,(n-1)*i+j+n-1,n*(n-1)+n*i+j,n*(n-1)+n*i+j+1,cells.size()));
	
	fclose;
	string name="out";
	string file;
	string filevtk=".vtk";
	file=name+"0"+filevtk;
	savevtk(file);
	for(int j=1;j<100;j++){
		if(j>10)
			file=name+char(j/10+48)+char(j%10+48)+filevtk;
		else
		file=name+char(j+48)+filevtk;
	for(int i=0;i<cells.size();i++)
		//for(int j=0;j<4;j++)
			if(i==j-1){
			split(cells[i]);
			cells[i].switcher=false;
			gl++;
	}
			cout<<file<<endl;
			savevtk(file);}
}

	