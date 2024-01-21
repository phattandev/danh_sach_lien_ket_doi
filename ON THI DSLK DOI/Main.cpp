#include "Header.h"

int main() {
	List head;
	init(head);

	HocSinh x;
	do {
		cout << "Nhap ma hoc sinh(-99 to stop): ";
		cin.getline(x.maHS, 10);
		//chu y
		if (strcmp(x.maHS, "-99") == 0)
			break;
		//cin.ignore();
		cout << "Nhap ten hoc sinh: ";
		cin.getline(x.hoTen, 35);

		cout << "Nhap diem Toan: ";
		cin >> x.diemToan;
		while (x.diemToan < 0 || x.diemToan>10) {
			cout << "Nhap lai diem Toan(>0 && <10): ";
			cin >> x.diemToan;
		}
		cout << "Nhap diem Van: ";
		cin >> x.diemVan;
		while (x.diemVan < 0 || x.diemVan>10) {
			cout << "Nhap lai diem Van(>0 && <10): ";
			cin >> x.diemVan;
		}
		addLast(head, x);
		//chu y
		cin.ignore();
	} while (true);
	printList(head);

	chenVaoTruoc(head);

	cout << "\n-----Xoa mot hoc sinh------";
	int idx2;
	cout << "\nMoi nhap vi tri hoc sinh muon xoa: ";
	cin >> idx2;
	deleteAt(head, idx2);
	printList(head);
	return 0;
}