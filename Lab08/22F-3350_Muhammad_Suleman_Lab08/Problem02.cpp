//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Car
//{
//private:
//	int carNum;
//	string parkingLocation;
//
//public:
//	Car(int carNum)
//		: carNum(carNum), parkingLocation("Parking not available") {}
//
//	Car(int carNum, string location)
//		: carNum(carNum), parkingLocation(location) {}
//
//	void setParkingLocation(string location)
//	{
//		parkingLocation = location;
//	}
//
//	int getCarNum()
//	{
//		return carNum;
//	}
//
//	string getParkingLocation()
//	{
//		return parkingLocation;
//	}
//};
//
//class Node
//{
//public:
//	Car car;
//	Node* next;
//	Node* prev;
//
//	Node(Car car)
//		: car(car), next(nullptr), prev(nullptr) {}
//};
//
//class Deque
//{
//private:
//	Node* front;
//	Node* rear;
//
//public:
//	Deque()
//		: front(nullptr), rear(nullptr) {}
//
//	bool isEmpty()
//	{
//		return front == nullptr;
//	}
//
//	void insert_at_beg(Car car)
//	{
//		Node* newNode = new Node(car);
//		if (isEmpty())
//		{
//			front = rear = newNode;
//		}
//		else
//		{
//			newNode->next = front;
//			front->prev = newNode;
//			front = newNode;
//		}
//		cout << "Car " << car.getCarNum() << " is inserted at beginning" << endl;
//	}
//
//	void insert_at_end(Car car)
//	{
//		Node* newNode = new Node(car);
//		if (isEmpty())
//		{
//			front = rear = newNode;
//		}
//		else
//		{
//			rear->next = newNode;
//			newNode->prev = rear;
//			rear = newNode;
//		}
//		cout << "Car " << car.getCarNum() << " is inserted at end" << endl;
//	}
//
//	void delete_fr_beg()
//	{
//		if (isEmpty())
//		{
//			cout << "Deque is empty" << endl;
//		}
//		else if (front == rear)
//		{
//			delete front;
//			front = rear = nullptr;
//		}
//		else
//		{
//			Node* temp = front;
//			front = front->next;
//			front->prev = nullptr;
//			delete temp;
//		}
//	}
//
//	void delete_fr_rear()
//	{
//		if (isEmpty())
//		{
//			cout << "Deque is empty" << endl;
//		}
//		else if (front == rear)
//		{
//			delete rear;
//			front = rear = nullptr;
//		}
//		else
//		{
//			Node* temp = rear;
//			rear = rear->prev;
//			rear->next = nullptr;
//			delete temp;
//		}
//	}
//
//	string search(int carNum)
//	{
//		Node* current = front;
//		while (current != nullptr)
//		{
//			if (current->car.getCarNum() == carNum)
//			{
//				return current->car.getParkingLocation();
//			}
//			current = current->next;
//		}
//		return "Car not found";
//	}
//};
//
//int main()
//{
//	Deque deque;
//
//	deque.insert_at_beg(Car(123, "CFD parking"));
//	deque.insert_at_end(Car(456, "CFD hostel parking"));
//	deque.insert_at_beg(Car(789));
//
//	cout << "Search results:" << endl;
//	cout << "Car 123: " << deque.search(123) << endl;
//	cout << "Car 456: " << deque.search(456) << endl;
//	cout << "Car 789: " << deque.search(789) << endl;
//
//	deque.delete_fr_beg();
//	deque.delete_fr_rear();
//
//	cout << "Search results after deletion:" << endl;
//	cout << "Car 123: " << deque.search(123) << endl;
//	cout << "Car 456: " << deque.search(456) << endl;
//	cout << "Car 789: " << deque.search(789) << endl;
//
//	system("pause");
//	return 0;
//}