#include<iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Ukr");
  double da, db, dc; char op;
  cout << "������� ����� �: ";
  cin >> da;
  cout << "�������� �������� (-;+;*;/): ";
  cin >> op;
  cout << "������� ����� b: ";
  cin >> db;
  switch ( op)
  {
     case '-': dc = da - db; break;
     case '+': dc = da + db; break;
     case '*': dc = da * db; break;
     case '/': dc = da / db; break;
     default: cout << "����������� ��������: " << op; return 0;
  }
  cout << "���������: " << da << op << db << " = " << dc << endl;
  return 0;
}
