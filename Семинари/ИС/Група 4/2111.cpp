#include <iostream>

using namespace std;

template <typename T>
class DLL {
public:
    DLL() : head(nullptr), tail(nullptr) {}

    void push_back(T value) {
        Node* newNode = new Node{ value, nullptr, tail };
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
    }

    void push_front(T value) {
        Node* newNode = new Node{ value, head, nullptr };
        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }

    T pop_back() {
        if (!tail) throw std::runtime_error("Pop from empty list");
        T value = tail->data;
        Node* prevNode = tail->prev;
        delete tail;
        tail = prevNode;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        return value;
    }

    T pop_front() {
        if (!head) throw std::runtime_error("Pop from empty list");
        T value = head->data;
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        return value;
    }

    T front() {
        if (!head) throw std::runtime_error("Access front of empty list");
        return head->data;
    }

    T back() {
        if (!tail) throw std::runtime_error("Access back of empty list");
        return tail->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    ~DLL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    T foldl(T(*op)(T, T), T initialValue) {
        Node* curr = head;
        while (curr) {
            initialValue = op(initialValue, curr->data);
            curr = curr->next;
        }
        return initialValue;
    }

    template<typename Predicate>
    DLL filter(Predicate p) {
        DLL result;
        Node* curr = head;
        while (curr) {
            if (p(curr->data))
                result.push_back(curr->data);
            curr = curr->next;
        }
        return result;
    }

    //T findSth(T n) {
    //   DLL<int> newList = this->filter([n](int x) { return x < n;});
    //   return newList.back();
    //}

    bool contains(T item) {
        bool result = false;
        Node* curr = head;
        while (curr && !result) {
            if (curr->data == item)
            {
                result = true;
            }
            curr = curr->next;
        }
        return result;
    };
    template <typename R>
    DLL<R> map(R(*f)(T)) {
        DLL<R> result;
        Node* curr = head;
        while (curr) {
            result.push_back(f(curr->data));
            curr = curr->next;
        }
        return result;
    }

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    } *head, * tail;
};

#include <string>

class FoodItem {
private:
    int Id;                // Unique identifier
    double Price;          // Price of the item
    std::string Name;      // Name of the item
    double Weight;         // Weight of the item
    std::string barCode;   // Barcode of the item

public:
    // Default constructor
    FoodItem() : Id(0), Price(0.0), Name(""), Weight(0.0), barCode("") {}

    // Parameterized constructor
    FoodItem(int id, double price, const std::string& name, double weight, const std::string& code)
        : Id(id), Price(price), Name(name), Weight(weight), barCode(code) {
    }

    // Getters
    int getId() const { return Id; }
    double getPrice() const { return Price; }
    std::string getName() const { return Name; }
    double getWeight() const { return Weight; }
    std::string getBarCode() const { return barCode; }

    // Setters
    void setId(int id) { Id = id; }
    void setPrice(double price) { Price = price; }
    void setName(const std::string& name) { Name = name; }
    void setWeight(double weight) { Weight = weight; }
    void setBarCode(const std::string& code) { barCode = code; }
};



int main()
{
    DLL<int> list;

    list.push_back(4);
    list.push_back(15);
    list.push_back(52);
    list.push_back(35);

    //cout << list.foldl([](int x, int y) { return x > y ? x : y; }, 0);

    DLL<int> newList = list.filter([](int x) { return x % 2 == 0; });
    cout << newList.foldl([](int x, int y) { return x < y ? x : y; }, 100);

    DLL<int> ids;
    ids.push_back(1);
    ids.push_back(5);

    DLL<FoodItem> foodItems;

    std::string sampleNames[] = { "Apple", "Banana", "Yogurt", "Milk", "Krenvirshi" };
    std::string sampleBarCodes[] = { "123456789012", "234567890123", "345678901234", "456789012345", "567890123456" };

    for (int i = 0; i < 5; ++i) {
        int id = i + 1;
        double price = id * 10;
        std::string name = sampleNames[i];
        double weight = id * 1000;
        std::string barCode = sampleBarCodes[i];

        FoodItem item(id, price, name, weight, barCode);
        foodItems.push_back(item);
    }
    list.filter([](int x) { return x % 2 == 0; });
    DLL<FoodItem> filteredFoodItems = foodItems.filter([&ids](FoodItem x) {
        return ids.contains(x.getId());
    });

    cout << filteredFoodItems.map<double>([](FoodItem item) { return item.getPrice(); })
        .foldl([](double x, double y) { return x+y; }, 0);
}
