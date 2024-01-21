#include "Header.h"

void init(List& head) {
	head = NULL;
}

Nodeptr makeNode(HocSinh x) {
	Nodeptr p = new Node;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->next = p->pre = NULL;
	return p;
}

void printList(List head) {
	cout << "\n-----DANH SACH HOC SINH-----\n";
	cout << setw(15) << left << "Ma HS" << setw(50) << left << "Ho ten" << setw(10) << left << "Toan" << setw(10) << left << "Van" << endl;
	while (head != NULL) {
		cout << setw(15) << left << head->data.maHS << setw(50) << left << head->data.hoTen << setw(10) << left << head->data.diemToan << setw(10) << left << head->data.diemVan << endl;
		head = head->next;
	}
}


void addFirst(List& head, HocSinh x) {
	Nodeptr p = makeNode(x);
	if (head == NULL)
		head = p;
	else {
		p->next = head;
		head->pre = p;
		head = p;
	}
}

void addLast(List &head, HocSinh x) {
	Nodeptr p = makeNode(x);
	if (head == NULL)
		head = p;
	else {
		Nodeptr r;
		for (r = head; r->next != NULL; r = r->next);
		r->next = p;
		p->pre = r;
	}
}

int length(List head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

Nodeptr nodeIndex(List head, int idx) {

	int count = 0;
	while (head != NULL) {
		if (count++ == idx)
			return head;
		head = head->next;
	}
	return NULL;
}

void addAfter(List& head, int idx, HocSinh x) {
	Nodeptr r = nodeIndex(head, idx);
	Nodeptr p = makeNode(x);
	p->next = r->next;
	r->next = p;
	r->next->pre = p;
	p->pre = r;
}

void addBefore(List &head, int idx, HocSinh x){
	Nodeptr r = nodeIndex(head, idx);
	Nodeptr p = new Node;
	*p = *r;
	r->next = p;
	p->pre = r;
	r->data = x;
}

void chenVaoSau(List head) {
	int idx;
	HocSinh y;
	cout << "\nNhap vi tri muon chen: ";
	cin >> idx;
	if (idx<0 || idx>length(head))
		cout << "\nVi tri khong jop le!!!";
	else {
		cout << "---Nhap thong tin hoc sinh can chen---\n";
		cin.ignore();
		cout << "Nhap ma hoc sinh: ";
		cin.getline(y.maHS, 10);
		cout << "Nhap ten hoc sinh: ";
		cin.getline(y.hoTen, 35);
		cout << "Nhap diem Toan: ";
		cin >> y.diemToan;
		while (y.diemToan < 0 || y.diemToan>10) {
			cout << "Nhap lai diem Toan(>0 && <10): ";
			cin >> y.diemToan;
		}
		cout << "Nhap diem Van: ";
		cin >> y.diemVan;
		while (y.diemVan < 0 || y.diemVan>10) {
			cout << "Nhap lai diem Van(>0 && <10): ";
			cin >> y.diemVan;
		}
		addAfter(head, idx, y);
		printList(head);
	}
}

void chenVaoTruoc(List head) {
	int idx;
	HocSinh y;
	cout << "\nNhap vi tri muon chen: ";
	cin >> idx;
	if (head == NULL)
		cout << "\nDanh sach rong!!!";
	else if (idx<0 || idx>length(head))
		cout << "\nVi tri khong jop le!!!";
	else {
		cout << "---Nhap thong tin hoc sinh can chen---\n";
		cout << "Nhap ma hoc sinh: ";
		cin.ignore();
		cin.getline(y.maHS, 10);
		cout << "Nhap ten hoc sinh: ";
		cin.getline(y.hoTen, 35);
		cout << "Nhap diem Toan: ";
		cin >> y.diemToan;
		while (y.diemToan < 0 || y.diemToan>10) {
			cout << "Nhap lai diem Toan(>0 && <10): ";
			cin >> y.diemToan;
		}
		cout << "Nhap diem Van: ";
		cin >> y.diemVan;
		while (y.diemVan < 0 || y.diemVan>10) {
			cout << "Nhap lai diem Van(>0 && <10): ";
			cin >> y.diemVan;
		}
		addBefore(head, idx, y);
		printList(head);
	}
}

int demHSToanLonHon5(List head) {
	int count = 0;
	while (head != NULL) {
		if (head->data.diemToan >= 5)
			count++;
	}
	return count;
}

void deleteBegin(List& head) {
	if (head == NULL)
		cout << "\nDanh sach rong!!!";
	else{
		Nodeptr p = head;
		head = head->next;
		head->pre = NULL;
		delete(p);
	}
}

void deleteEnd(Nodeptr& head) {
	if (head == NULL)
		cout << "\nDanh sach rong!!!";
	else {
		Nodeptr r, tail;
		for (tail = head; tail->next != NULL; tail = tail->next);
		for (r = head; r->next != tail; r = r->next);
		r->next = NULL;
		tail->pre = NULL;
		delete(tail);
	}
}

void deleteMid(List head, int idx) {
	if (head == NULL)
		cout << "\nDanh sach rong!!!";
	else {
		Nodeptr r, p =nodeIndex(head,idx);
		for (r = head; r->next != p; r = r->next);
		r->next = p->next;
		p->next->pre = r;
		delete(p);
	}
}

void deleteAt(List& head, int idx) {
	if (head == NULL)
		cout << "\nDanh sach rong!!!";
	else if (idx<0 || idx>length(head))
		cout << "\nVi tri khong hop le!!!";
	else if (idx == 0)
		deleteBegin(head);
	else if (idx == length(head)-1)
		deleteEnd(head);
	else{
		deleteMid(head, idx);
	}
}