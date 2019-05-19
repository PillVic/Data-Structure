
typedef struct{
    int* set;
    int length;
}DisjSet;
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S, int length);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);
