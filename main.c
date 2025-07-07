#include <stdio.h>
#include "avl.h"

int main(){
	int opt = 0, value, valueReturn;
	node* avl = NULL;
	while(1){
		scanf("%d", &opt);
		switch(opt){
			case 1:
				//inserir
				scanf("%d", &value);
				avl = insert(avl, value, &valueReturn);
				break;		
			case 2://inorder
				posOrder(avl);
				printf("\n");
				break;
			case 3://remover
				scanf("%d", &value);
				avl = removeNode(avl, value, &valueReturn);
			break;
			case 99:
				return 0;

		}
	}
}