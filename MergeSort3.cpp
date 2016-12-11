#include <iostream>
#include <fstream>
using namespace std;
std::ifstream infile("IntegerArray.txt");

long long int MSI(int *a, int sizea, int *b, int sizeb, int *c, int &sizec){
	sizec = sizea+sizeb;
	long long int inv =0;
	int ia=0;
	int ib=0;
	for(int i=0; i<(sizea+sizeb); i++){
	if((a[ia]<b[ib])&&(ia<(sizea))){
		c[i] = a[ia];
		if(ia<(sizea)){ia++;}
	}
	else if((b[ib]<a[ia])&&(ib<(sizeb))){
		c[i] = b[ib];
		inv = inv + sizea-ia;
		if(ib<(sizeb)){ib++;}
	}
	else if (ia>=(sizea)){
		c[i] = b[ib];
		inv = inv + sizea-ia;
		if(ib<(sizeb)){ib++;}
	}
	else if (ib>=(sizeb)){
		c[i] = a[ia];
		if(ia<(sizea)){ia++;}
	}
    }
    return inv;
}

long long int Inversion(int *m,int &sizem){
	if (sizem==2){
		if(m[0]>m[1]){
		int tm =0;
		tm = m[1];
		m[1]=m[0];
		m[0]=tm;
		return 1;}
		else if (m[0]<m[1]){
		return 0;}
		}
	else if (sizem==1){
		return 0;
	}
	else if (sizem>2){
	long long  int left = 0;
	long long int right = 0;
	long long int midle = 0;
	int sizeleft;
	if(sizem%2==0){sizeleft=sizem/2;}
	else if (sizem%2==1){sizeleft= (sizem-1)/2;}
	int sizeright = sizem-sizeleft;
	//cout << "size left: " << sizeleft << "   " << "size right: " << sizeright << "   " << endl;
	int leftarray[sizeleft];
	int rightarray[sizeright];
	
	for (int i =0;i<sizeleft;i++){
		leftarray[i] = m[i];
	//	cout << "leftarray[" << i << "]: " << leftarray[i] << endl;
	}
	for (int i =0;i<sizeright;i++){
		rightarray[i] = m[i+sizeleft];
	//	cout << "rightarray[" << i << "]: " << rightarray[i] << endl;
	}
	
	left = Inversion(leftarray,sizeleft);
	for (int i =0;i<sizeleft;i++){
	//	cout << "After Inversion leftarray[" << i << "]: " << leftarray[i] << endl;
	}
	right = Inversion(rightarray,sizeright);
	for (int i =0;i<sizeright;i++){
	//	cout << "After Inversion rightarray[" << i << "]: " << rightarray[i] << endl;
	}
	midle = MSI(leftarray,sizeleft,rightarray,sizeright,m,sizem);
	//cout << "left: " << left << "   " << "right: " << right << "   " << "midle: " << midle << "   " <<endl;
	return left+right+midle;
	}
}


int main(){
//load file
	int in;
//	int input[10];
//	int inputsize = 10;	

	int input[100000];
	int inputsize = 100000;
//*/
	int loadindex = 0;
	while (infile >> in){
    input[loadindex] = in;
    loadindex++;
	}
//load file end
// test case;
/*
  int d[100] = {4, 80, 70, 23, 9, 60, 68, 27, 66, 78, 12, 40, 52, 53, 44, 8, 49, 28, 18, 46, 21, 39, 51, 7, 87, 99, 69, 62, 84, 6, 79, 67, 14, 98, 83, 0, 96, 5, 82, 10, 26, 48, 3, 2, 15, 92, 11, 55, 63, 97, 43, 45, 81, 42, 95, 20, 25, 74, 24, 72, 91, 35, 86, 19, 75, 58, 71, 47, 76, 59, 64, 93, 17, 50, 56, 94, 90, 89, 32, 37, 34, 65, 1, 73, 41, 36, 57, 77, 30, 22, 13, 29, 38, 16, 88, 61, 31, 85, 33, 54};
  int sd=100;
*/
  long long int sumi = 0;
  sumi =  Inversion(input,inputsize);
//  sumi =  Inversion(d,sd);
  cout <<"total Inversion:  " << sumi << endl;
/*  
  int i =0;
  while (i<sd){
  cout << d[i] << endl;
  i++;
}*/
return 0;
}
