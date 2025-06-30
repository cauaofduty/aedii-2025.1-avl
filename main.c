#include <stdio.h>
#include "avl.h"

int main(){
	int opt = 0, value, valueReturn; // ->  value2
	node* avl = NULL;
	while(1){
		scanf("%d", &opt);
		switch(opt){
			case 1:
				//inserir
				scanf("%d", &value);
				avl = insert(avl, value);
				break;		
			case 2://inorder
				inOrder(avl);
				printf("\n");
				break;
			case 3://altura
				valueReturn = height(avl);
				printf("%d\n", valueReturn);
				break;
			case 99:
				return 0;

		}
	}
}