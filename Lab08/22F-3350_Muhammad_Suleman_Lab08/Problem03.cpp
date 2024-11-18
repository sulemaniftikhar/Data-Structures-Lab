//#include <iostream>
//
//using namespace std;
//
//class Order
//{
//public:
//	string description;
//	double price;
//};
//
//class PizzaSystem
//{
//private:
//	Order *orderArray;
//	int front;
//	int rear;
//	int maxOrders;
//	int count;
//
//public:
//	PizzaSystem(int maxOrders)
//		: front(0), rear(-1), count(0), maxOrders(maxOrders)
//	{
//		orderArray = new Order[maxOrders];
//	}
//
//	void placeOrder(string description, double price)
//	{
//		if (count >= maxOrders)
//		{
//			cout << "Maximum order limit reached" << endl;
//			return;
//		}
//		rear = (rear + 1) % maxOrders;
//		orderArray[rear].description = description;
//		orderArray[rear].price = price;
//		count++;
//
//		cout << "Order placed successfully!" << endl;
//	}
//
//	double calculateBill()
//	{
//		double totalBill = 0.0;
//		int i = front;
//		int numOrders = count;
//
//		while (numOrders > 0)
//		{
//			totalBill += orderArray[i].price;
//			i = (i + 1) % maxOrders;
//			numOrders--;
//		}
//		return totalBill;
//	}
//};
//
//int main()
//{
//	PizzaSystem pizzaSystem(10);
//
//	pizzaSystem.placeOrder("Pizza Margherita", 1000);
//	pizzaSystem.placeOrder("Pepperoni Pizza", 900);
//	pizzaSystem.placeOrder("Garlic Bread", 300);
//
//	double bill = pizzaSystem.calculateBill();
//	cout << "Total bill: Rs." << bill << endl;
//
//	system("pause");
//	return 0;
//}