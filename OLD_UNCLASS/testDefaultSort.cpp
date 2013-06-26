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
#include <algorithm>
#include <vector>
#define MAX 30

int list[MAX];
int n;
int sum;
int sl=0;
int currentSum=0;
void swap(int *x, int *y){
     int temp;
     temp=*x;
     *x=*y;
     *y=temp;
}
void quicksort(int start, int end){
     int k,key,i,j;
     if(start>=end ) return;
     //start <end;
     k=(start+end)/2;
     key=list[k];
     swap(&list[start], &list[k]);
     i=start+1;
     j=end;
     while(i<=j){
                 while(i<=end && list[i]<=key)
                 i++;
                 while(j>=start+1&&list[j]>key)
                 j--;
                 if(i<j) swap(&list[i],&list[j]);
                 
     }
     swap(list[start],list[j]);
     quicksort(start,j-1);
     quicksort(j+1,end);
}
void printList(int arr[],int n)
{
 for(int i=0;i<n;i++)
 printf("%d\t",arr[i]);     
}

void attempt(int i){
     int j;
     for(j=i+1;j<n;j++)
     {
      if (currentSum+list[j]==sum) {
                                   sl++;
         }
         else {
              if(sum< currentSum && list[j]>=0) return;
              if(sum> currentSum+(n-j+1)*list[n-1] &&list[j]>=0) return;
              currentSum+=list[j];
              attempt(j);
              currentSum=currentSum-list[j];
              }                
     }
}
int main(){
    int i=0;
    //Input
    cout<<"n= ";
    cin>>n;
    for(i=0;i<n;i++){
                     cout<<"list["<<i<<"]=";
                     cin >>list[i];
                       }
    cout<<"sum= ";
    cin >>sum;
    //process
    printList(list,n);
    quicksort(0,n-1);
    printf("\n+++++++++\n");
    printList(list,n);
    attempt(-1);
    cout<<"so luong:" <<sl;
    getch();
}
