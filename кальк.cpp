#include<iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Ukr");
  double da, db, dc; char op;
  cout << "Введите число а: ";
  cin >> da;
  cout << "Выберите операцию (-;+;*;/): ";
  cin >> op;
  cout << "Введите число b: ";
  cin >> db;
  switch ( op)
  {
     case '-': dc = da - db; break;
     case '+': dc = da + db; break;
     case '*': dc = da * db; break;
     case '/': dc = da / db; break;
     default: cout << "Неизвестная операция: " << op; return 0;
  }
  cout << "Результат: " << da << op << db << " = " << dc << endl;
  return 0;
}
