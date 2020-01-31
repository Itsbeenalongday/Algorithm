/************************************************************************************ 
 *   counting sort algorithm
 *   principle : 빈도수 배열 이용 해서 몇개 나온지 센 다음 위치 잡고 하나씩 줄여가면서 정렬
*************************************************************************************/
/*
#include <stdio.h>
#include <string.h>

void counting_sort(int* array,int len){
    // 최대값 구하기 - counting 배열의 길이
    int max = array[0];
    for(int i=0;i<len;i++){
        if(max<array[i]) max = array[i];
    }
    max++; // 0 포함해야되니

    int sorted[len]; // 정렬된 배열
    int count[max]; // 빈도수 배열
    // 초기화
    memset(count,0,sizeof(count));
    memset(sorted,0,sizeof(sorted));

    // 빈도수 구하기
    for(int i=0;i<len;i++){
        count[array[i]]++;
    }

    // 몇 칸씩 차지하지는지 알기 위해 빈도수 배열을 수정한다. 빈도수 배열의 i-1번 째와 i번 째 요소를 더하면 알 수 있다.
    // 0번 나온거는 0번 나온 요소 다음요소가 전전요소가 몇개 나왓는지 알아야 하니까 0번요소 전에 나온 것의 갯수를 그대로 주면 되니깐
    // 1 1 4 3 5 야 2가 안나왓잖아 count는 업데이트 하면 0 2 2 3 4 5 니까 1이 2번 인덱스부터 위치하면 됨
    // 빈도수 배열 업데이트 - 인덱스 이동
    for(int i=0;i<max-1;i++){ 
        count[i+1] += count[i];
    }
    
    // 정렬 안된 배열을 역순으로 읽으면서 빈도수 배열 참고하여 정렬
    for(int j = len-1;j>=0;j--){
        sorted[count[array[j]]-1] = array[j]; 
        // -1을 하지 않는다면, sorted 0 번째 요소는 업데이트 되지 않음.
        // 한 칸씩 앞으로 댕긴다.
        count[array[j]]--;
        // 빈도수 배열에서의 위치 다음꺼는 한 개 줄어야겟지? 
    }

    // copy
    for(int j = 0;j<len;j++){
        array[j] = sorted[j];
    }

}

int main(){
    int array[] = {9,8,7,6,5,4,3,2,1,1};
    int length = sizeof(array)/4;
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
   counting_sort(array,length);
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
*/

/****************************************** 
 *   mergesort1 algorithm
 *   principle : divide and conquer
******************************************/
/*
#include <stdio.h>

void merge(int h,int m, int u[],int v[], int s[]){
    int i,j,k;
    i=0,j=0,k=0;
    while(i<h && j<m){
        if(u[i]<v[j]){
            s[k++] = u[i++];
        }else{
            s[k++] = v[j++];
        }
    }
    if(i>h) while(j<=m) s[k++] = v[j++];
    else while(i<=h) s[k++] = u[i++];
}

void mergesort(int n, int s[]){
    if(n>1){
        int h = n/2;
        int m = n-h;
        int mid = h;
        int u[h+1];
        int v[m+1];
        int i=0, j=0;
        int k = 0;
      while(k<n){
        if(k<mid){
            u[i++]=s[k++];
        }else{
            v[j++]=s[k++];
        }
    }
        mergesort(h,u);
        mergesort(m,v);
        merge(h,m,u,v,s);
    }
}

int main(){
    int array[] = {9,8,7,6,5,4,3,2,1,1};
    int length = sizeof(array)/4;
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
   mergesort(length,array);
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
*/

/****************************************** 
 *   mergesort2 algorithm
 *   principle : divide and conquer
******************************************/
/*
#include <stdio.h>

void merge2(int low, int mid, int high,int s[]){
    int i = low, j=mid+1, k=low;
    int u[high];
    while(i<=mid && j<=high){
        if(s[i]<s[j]){
            u[k++]=s[i++];
        }else{
            u[k++]=s[j++];
        }
    }
    if(i>mid) while(j<=high) u[k++]=s[j++];
    else while(i<=mid) u[k++]=s[i++];

    for(int in=low;in<=high;in++){
        s[in]=u[in];
    }

}

void mergesort2(int low,int high,int s[]){
    int mid;
    if(low<high){
        mid = (low + high)/2;
        mergesort2(low,mid,s);
        mergesort2(mid+1,high,s);
        merge2(low,mid,high,s);
    }
}

int main(){
    int s[] = {10,9,8,7,6,5,4,3,2,1};
    int length = sizeof(s)/4;
    mergesort2(0,length,s);
    for(int i=0;i<length;i++) printf("%d ",s[i]);
    printf("\n");
    return 0;
}
*/

/****************************************** 
 *   power function algorithm => O(logn)
 *   principle : divide
******************************************/
/*
#include <stdio.h>

long long function(long long x,long long n);

int main(){
    long long x, n ,p;
    long long result = 0;
    printf("x^n %% p 구하는 프로그램입니다 . x n p를 차례대로 입력하세요.\n");
    scanf("%lld %lld %lld",&x,&n,&p);
    result = function(x,n);
    printf("%lld \n",result);
    return 0;
}

long long function(long long x,long long n){
    if(n==1) return x;
    if(n==__LONG_LONG_MAX__){
         printf("max!!!");
         return 0;
    }
    long long tmp = function(x,n/2);
    return tmp*tmp;
}
*/

// loop version
/*
#include <stdio.h>

int main(){
    int x,n;
    scanf("%d %d",&x,&n);
    int i = 1;
    long long tmp =x;
    while(1){
        if(i>=n) break;
        tmp *=tmp;
        i *=2;
    }

    printf("%lld \n",tmp);

    return 0;
}
*/

/****************************************** 
 *   quicksort algorithm
 *   principle : divide and conquer
******************************************/
/*
#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void partition(int low,int high,int pivotpoint,int s[]){
    int i, j;
    int pivotitem=s[low];
    j=low;
    for(i=low+1;i<=high;i++){
        if(s[i]<pivotitem){
            j++;
            swap(s+i,s+j);
        }
        
    }
    pivotpoint=j;
    swap(s+low,s+pivotpoint);
}

void quicksort(int low,int high,int s[]){
    int pivot = low;
    if(low<high){
        partition(low,high,pivot,s);
        quicksort(low,pivot-1,s);
        quicksort(pivot+1,high,s);
    }
}

int main(){
    int s[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(s)/4;
    quicksort(0,length-1,s);
    for(int i=0;i<length;i++) printf("%d ",s[i]);
    printf("\n");
    return 0;
}
*/

/****************************************** 
 *   finding maximmum algorithm
 *   principle : divide and conquer
******************************************/
/*
#include <stdio.h>

void find(int low, int high, int arr[],int * max){
    printf("%d\n",*max);
    if(arr[low]<arr[high]){
        if(*max<arr[high]) *max = arr[high];
    }else{
        if(*max<arr[low]) *max = arr[low];
    }
}

void findmax(int low,int high ,int arr[],int *max){
    
    if(low<high){
        int mid = (low+high)/2;
        findmax(low,mid,arr,max);
        findmax(mid+1,high,arr,max);
        find(low, high,arr,max);
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int max=0;
    findmax(0,9,arr,&max);
    printf("%d\n",max);
}
*/

/*********************************************************** 
 *   Huffmancode
 *   principle : Greedy Approach
************************************************************/
/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;

typedef struct TreeNode* TreePointer;
typedef struct TreeNode{
	int value;
	TreePointer left;
	TreePointer right;
}TreeNode;

int number = 15;

char alphabet = 65;

void Huffmanpreorder(TreePointer root,int depth,char* HuffmanCode) {
	if (root) {
		
		depth++;
		HuffmanCode[depth] = '0';
		
		Huffmanpreorder(root->left,depth,HuffmanCode);
		HuffmanCode[depth] = '1';
		
		Huffmanpreorder(root->right, depth,HuffmanCode);
		HuffmanCode[depth] = '\0';
		
		if (!root->left && !root->right) {
			printf("Node : %2d -> %c : %s\n",root->value,alphabet++,HuffmanCode);
		}
		
	}
}

int main() {

	TreeNode nodes[16];
	char HuffmanCode[100];

	for (int i = 1; i <= number; i++) { 
		nodes[i].value = i; 
		nodes[i].left = NULL; 
		nodes[i].right = NULL; 
	} 
	
	for (int i = 2; i <= number; i++) { 
		if (i % 2 == 0) { 
			nodes[i / 2].left = &nodes[i]; 
		}
		else { 
			nodes[i / 2].right = &nodes[i]; 
		} 
	}

	Huffmanpreorder(&nodes[1],-1,HuffmanCode);
}
*/

/*********************************************************** 
 *   Search for the longest string pattern
 *   principle : KMP algorithm transformation
************************************************************/
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char strArray[] = {"abcabcabcabcdededededede"};
	int fail[strlen(strArray)];
	int n;
	int i, j;
    
	n = strlen(strArray);
	fail[0] = -1;

	for (j = 1; j < n; j++)
	{
		i = fail[j - 1];
		while(strArray[j] != strArray[i + 1] && i >= 0)
			i = fail[i];
		if (strArray[j] == strArray[i + 1]) fail[j] = i + 1;
		else fail[j] = -1;
	}

    int max = fail[0];
    int end;
    int start;
	for (int i=0;i<n;i++){
        if(max<fail[i]) {
            max= fail[i];
            end = i;
        }
        if(fail[i]==0) start = i;
    }

    for(int i = start;i<=end;i++){
        printf("%c",strArray[i]);
    }
	printf("\n");
	return 0;
}
*/

