/*
Trong ma(.t pha(?ng to.a ?o^. c� N v�c to+. Mo^~i mo^.t v�c to+ ?u+o+.c cho bo+?i hai chi? so^' x v� y. To^?ng cu?a hai v�c to+ (xi, yi) v� (xj, yj) ?u+o+.c ?i.nh nghi~a l� mo^.t v�c to+ (xi + xj, yi + yj). B�i to�n ?a(.t ra l� ca^`n cho.n mo^.t so^' v�c to+ trong N v�c to+ ?� cho sao cho to^?ng cu?a c�c vec to+ ?� l� v�c to+ (U, V).

Y�u ca^`u: ?e^'m so^' c�ch cho.n thoa? m�n y�u ca^`u b�i to�n ?a(.t ra o+? tr�n.
Input

D�ng thu+' nha^'t ghi so^' N (0 ? N ? 30).

N d�ng tie^'p theo, d�ng thu+' i ghi c�c so^' nguy�n xi, yi la^`n lu+o+.t l� hai chi? so^' cu?a v�c to+ thu+' i. (|xi|, |yi| ? 100).

D�ng cuo^'i c�ng ghi so^' hai so^' nguy�n U V (|U|, |V| ? 109).
Output

Go^`m mo^.t so^' duy nha^'t l� so^' c�ch cho.n thoa? m�n.
Example

Input:
4
0  0
-1  2
2  5
3  3
2  5

Output:
4

*/
#include <iostream>
using namespace std;
#include <conio.h>
#define MAX 40

int listX[MAX];
int listY[MAX];
int n;
int sumX,sumY;
int sl=0;
int currentSumX=0,currentSumY=0;
void swap(int x, int y){
     int temp;
     temp= listX[x];
     listX[x]=listX[y];
     listX[y]=temp;
     temp= listY[x];
     listY[x]=listY[y];
     listY[y]=temp;
}
void quicksort(int start, int end){
     int k,key,i,j;
     if(start>=end ) return;
     //start <end;
     k=(start+end)/2;
     key=listX[k];
     swap(start, k);
     i=start+1;
     j=end;
     while(i<=j){
                 while(i<=end && listX[i]<=key)
                 i++;
                 while(j>=start+1&&listX[j]>key)
                 j--;
                 if(i<j) swap(i,j);
                 
     }
     swap(start,j);
     quicksort(start,j-1);
     quicksort(j+1,end);
}

void attempt(int i){
     int j;
     for(j=i+1;j<n;j++)
     {
      if (currentSumX+listX[j]==sumX ) {
                                    if(currentSumY+listY[j]==sumY)
                                    sl++;
         }
         else {
              //(sumX< currentSumX && listX[j]>=0) return;
              //(sumX> currentSumX+(n-j+1)*listX[n-1] &&listX[j]>=0) return;
              currentSumX+=listX[j];
              currentSumY+=listY[j];
              attempt(j);
              currentSumX=currentSumX-listX[j];
              currentSumY=currentSumY-listY[j];
              }                
     }
}
int main(){
    int i=0;
    //Input
    cin>>n;
    for(i=0;i<n;i++){
                      cin >>listX[i];
                      cin >>listY[i];
                       }
    cin >>sumX>>sumY;
    
    //process
    //printlistX(listX,n);
    quicksort(0,n-1);
   
    //printlistX(listX,n);
    attempt(-1);
    cout<<sl;
    getch();
}
