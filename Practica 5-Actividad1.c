#include <stdio.h>

void intercambio(int array[],int size){
	int i,j,t;
	for(i=0; i<size-1; i++)
		for(j=i+1; j<size; j++)
			if(array[i]>array[j]){
				t=array[i];
				array[i]=array[j];
				array[j]=t;
			}
}

void seleccion(int array[],int size){
	int e,i,j,t;
	for(i=0; i<size-1; i++){
		e=i;
		for(j=i+1; j<size; j++)
			if(array[e]>array[j])
				e=j;
			if(i!=e){
				t=array[i];
				array[i]=array[e];
				array[e]=t;
			}
	}
}

void insercion(int array[],int size){
	int i,j,t;
	for(i=1;i<size;i++){
		t=array[i];
		for(j=i; j>0 && t<array[j-1];j--)
			array[j]=array[j-1];
		array[j]=t;
		}
}

void swap(int array[], int a,int b){
	int t;
	t=array[b];
	array[b]=array[a];
	array[a]=t;
}

void quicksort(int array[],int left, int right){
	if(left>=right)
		return;
	int pivot=(left+right)/2,pelement=array[pivot],first=left,last=right;
	while(left<right){
		while ((left<=right)&&(array[left]<=pelement)||(left==pivot))
			left++;		
		while ((left<=right)&&(array[right]>pelement)||(right==pivot))
			right--;	
		if(left<right)
			swap(array,left++,right--);
	}
	if(left < pivot){
		if(right < pivot){
			swap(array, left, pivot);
			pivot = left;
		}
	}else{
		if(right > pivot){
			swap(array, right, pivot);
			pivot = right;
		}
	}
	quicksort(array,first,pivot-1);
	quicksort(array,pivot+1, last);
}

int main(){
	int x,opc,arreglo[]={20,34,11,54,33,10,15,55,99,40};
	system("clear");
	printf("Valores Originales: ");
	for(x=0;x<10;x++)
		printf("[%d]",arreglo[x]);
	printf("\n");
	printf("ELIGA EL METODO DE ORDENAMIENTO: \n");
	printf("1) INTERCAMBIO\n");
	printf("2) SELECCION\n");
	printf("3) INSERCION\n");
	printf("4) QUICKSORT\n");
	scanf("%d",&opc);
	switch(opc){
	case 1: intercambio(arreglo,10);
			break;
	case 2: seleccion(arreglo,10);
			break;
	case 3: insercion(arreglo,10);
			break;
	case 4: quicksort(arreglo,0,9);
			break;
	}
	printf("Valores Ordenados: ");
	for(x=0;x<10;x++)
		printf("[%d]",arreglo[x]);
	printf("\n");
	return 0;
}	


