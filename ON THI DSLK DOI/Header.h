#include <iostream>
#include <iomanip>
using namespace std;

struct HocSinh{
	char maHS[10];
	char hoTen[50];
	float diemToan;
	float diemVan;
};
typedef struct Node* Nodeptr;
struct Node {
	HocSinh data;
	Nodeptr next, pre;
};
typedef Node* List;

void init(List& head);
Nodeptr makeNode(HocSinh x);
void addFirst(List& head, HocSinh x);
void printList(List head);
void addLast(List &head, HocSinh x);
void addAfter(List& head, int idx, HocSinh x);
void addBefore(List& head, int idx, HocSinh x);
void chenVaoSau(List head);
void chenVaoTruoc(List head);
void deleteBegin(List& head);
void deleteEnd(Nodeptr& head);
void deleteMid(List head, int idx);
void deleteAt(List& head, int idx);

int length(List head);
Nodeptr nodeIndex(List head, int idx);