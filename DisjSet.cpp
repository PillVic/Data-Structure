#include"DisjSet.h"
#include<stdlib.h>

void Initialize(DisjSet S,int length){
    S.set = (int*)malloc(length*sizeof(int));
    for(int i=0;i<length;i++){
	S.set[i] = 0;
    }
    S.length = length;
}
/*Assums Root1 and Root2 are roots
 *union is a keyword, so this routine is named SetUnion
 * */
void SetUnion(DisjSet S, SetType Root1, SetType Root2){
    S.set[Root2] = Root1;
}
SetType Find(ElementType x, DisjSet S){
    if(S.set[x] <= 0){
	return x;
    }else{
	return Find(S.set[x], S);
    }
}
