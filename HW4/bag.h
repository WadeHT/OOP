#include<iostream>
using namespace std;
template<typename ItemType>struct Item;
template<class ItemType>
class Bag
{
	template<class IT>friend void combine(const Bag<IT>&,const Bag<IT>&, Bag<IT>&);
	template<class IT>friend void subtract(const Bag<IT>&,const Bag<IT>&, Bag<IT>&);
	Item<ItemType> *finger,*first;
	Item<ItemType> item;
public:
	Bag(void);
	Bag(const Bag&);
	~Bag(void);
	bool empty(void)const;
	int size(void)const;
	int uniqueSize(void)const;
	bool insert(const ItemType& );
	int erase(const ItemType& );
	int eraseAll(const ItemType& );
	bool contains(const ItemType& )const;
	int count(const ItemType& )const;
	// Iteration functions
	void start(void);
	void next(void);
	bool ended(void)const;
	const ItemType& currentValue(void)const;
	int currentCount(void)const;
	const Bag &operator=(const Bag&);
	bool operator==(const Item<string>&)const;
	void GET(void)const;
};
