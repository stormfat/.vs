/*用动态绑定实现多态*/

#include <iostream>
#include <string>
using namespace std;

class Item_base
{
public:
	Item_base(const string& book = "", double sale_price = 0.0)
		: isbn(book), price(sale_price) {}
	string book() const { return isbn; }
	virtual double net_price(size_t n) const {
		return n * price;
	}// virtual关键字修饰的虚函数,可以在派生类中重新定义.

private:
	string isbn;

protected: // proteced关键字,其声明成员用来继承.派生类可以使用,基类不可使用.
	double price;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const string& book = "", double sale_price = 0.0, size_t qty = 0,
		double disc_rate = 0.0)
		: Item_base(book, sale_price), min_qty(qty), discount(disc_rate) {}

	double net_price(size_t cnt) const {
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

private:
	size_t min_qty;
	double discount;
};

void print_total(ostream& os, Item_base* item, size_t n) {
	os << "ISBN:" << item->book() << "\tnumber sold:" << n << "\ttotal price:" << item->net_price(n) << endl;
}

int main() {
	Item_base* a = new Item_base("1-234-567-01", 11.0);
	Bulk_item* b = new Bulk_item("1-234-567-02", 22.0, 2, 0.05);
	print_total(cout, a, 2);
	print_total(cout, b, 3);//可以接受派生类对象作为基类形参的实参,基类中的虚函数如果在派生类中被重定义,那么就根据传入的对象进行动态绑定

	Item_base* books[5];
	books[0] = new Item_base("0-123-456-01", 10.0);
	books[1] = new Bulk_item("0-123-456-02", 20.0, 6, 0.05);//指向基类对象的指针可以指向派生类
	books[2] = new Item_base("0-123-456-03", 30.0);
	books[3] = new Bulk_item("0-123-456-04", 40.0, 4, 0.15);
	books[4] = new Bulk_item("0-123-456-05", 50.0, 2, 0.18);

	int num[5];
	num[0] = 2;
	num[1] = 10;
	num[2] = 1;
	num[3] = 5;
	num[4] = 3;

	for (int i = 0; i < 5; i++) { print_total(cout, books[i], num[i]); }
	return 0;
}