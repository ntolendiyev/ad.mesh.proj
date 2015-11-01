#include<iostream>
#include <vector>
#include <list>
#include<fstream>
using namespace std;
class Cell{
public: double x1,x2,y1,y2,cx,cy;
		Cell(double a1,double b1,double a2,double b2){
			x1=a1;x2=a2;y1=b1;y2=b2;
			cx=(x1+x2)/2;
			cy=(y1+y2)/2;
		}
		Cell newcell1(){
			Cell new1(x1,y1,cx,cy);
			return new1;
		}
		Cell newcell2(){
			Cell new2(cx,y1,x2,cy);
			return new2;
		}
		Cell newcell3(){
			Cell new3(x1,cy,cx,y2);
			return new3;
		}
		Cell newcell4(){
			Cell new4(cx,cy,x2,y2);
			return new4;
		}
};
void main(){
	ofstream out("out.vtk",ios::out);
	int i,j;

	vector<Cell> cells;
	for(i=0;i<5-1;i++)
		for(j=0;j<5-1;j++)
			cells.push_back(Cell(i,j,i+1,j+1));
	for(i=0;i<16;i++)
			if(i==6){
				cells.push_back(cells[i].newcell1());
				cells.push_back(cells[i].newcell2());
				cells.push_back(cells[i].newcell3());
				cells.push_back(cells[i].newcell4());}
			
	out<<"# vtk DataFile Version 2.1\nmerger Visser/Rosendal\nASCII\nDATASET POLYDATA\nPOINTS "<<76<<" float\n";
			for(i=0;i<20;i++)
				if(i!=6){
	out<<cells[i].x1<<" "<<cells[i].y1<<" 0\n";
	out<<cells[i].x2<<" "<<cells[i].y1<<" 0\n";
	out<<cells[i].x2<<" "<<cells[i].y2<<" 0\n";
	out<<cells[i].x1<<" "<<cells[i].y2<<" 0\n";}
	out<<"POLYGONS 19 95\n";
	for(i=0;i<76;i++){
		if(i%4==0){
	out<<"\n";
	out<<"4 ";}
		out<<i<<" ";}	
system("pause");
}
		