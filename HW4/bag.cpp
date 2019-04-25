#include"bag.h"
#include<string.h>
//struct Item
template<typename ItemType>struct Item
{
	ItemType item;
	struct Item *from,*to;
};
template<typename ItemType>struct Num
{
	ItemType item;
	int n;
};
//class Bag function
template<class ItemType>Bag<ItemType>::~Bag(void)
{
	Item<ItemType>*temp,*v;
	if(first != first->to)
	{
		for(v = first->to->to; v != first; v = v->to)delete v->from; 
		delete first->from; 
	}
	cout<<"Bag destructed"<<endl;
}
template<class ItemType>Bag<ItemType>::Bag(const Bag &original)
{
	Item<ItemType> *v,*temp,*now;
	now = first = new Item<ItemType>;
	int i;
	for(v = original.first->to; v != original.first; v = v->to)
	{
		temp = new Item<ItemType>;
		now->to = temp;
		temp->from = now;
		temp->item = v->item;
		now = temp;
	}
	first->from = now;
	now->to = first; 
	for(v =original.first->to,i=0; v!=original.finger&&original.finger!=NULL; i++,v=v->to);
	for(v = first->to; i>0; v = v->to,i--); 
	finger = v;
	cout<<"copy constructed\n";
	return;	
}
template<class ItemType>Bag<ItemType>::Bag(void):first(&item),finger(NULL)
{
	item.from = &item;
	item.to = &item;
	cout<<"Bag constructed"<<endl;
	return;
}
template<class ItemType>bool Bag<ItemType>::empty(void)const
{
	return(first->to == first)? true:false;
}
template<class ItemType>int Bag<ItemType>::size(void)const
{
	int num=0;
	for(Item<ItemType> *v = first->to; v != first; v = v->to)num++;
	return num;
}
template<class ItemType>int Bag<ItemType>::uniqueSize(void)const
{
	int i;
	Num<ItemType> num[10000];
	Item<ItemType> *v;
	memset(num,0,sizeof(num));
	for(v = first->to; v != first; v = v->to)
	{
		for(i=0; num[i].n!=0; i++)
			if(v->item == num[i].item)
			{
				num[i].n++;
				break;
			}
		if(num[i].n == 0)
		{
			num[i].item = v->item;
			num[i].n++;
		}
	}
	for(i=0; num[i].n!=0; i++);
	return i;
}
template<class ItemType>bool Bag<ItemType>::insert(const ItemType& value)
{
	Item<ItemType> *temp = new(nothrow) Item<ItemType>;
	if(temp == NULL)return false;
	temp->to = first;
	temp->from = first->from;
	temp->item = value;
	first->from->to = temp;	
	first->from = temp;	
	finger = NULL;
	return true;
}

template<class ItemType>int Bag<ItemType>::erase(const ItemType& value)
{
	int i;
	Item<ItemType> *v;
	finger = NULL;
	for(v = first->to, i=1; v != first; v = v->to,i++)
		if(v->item == value)
		{
			v->from->to = v->to;
			v->to->from = v->from;
			delete v; 
			return i;
		}
	return i;
}
template<class ItemType>int Bag<ItemType>::eraseAll(const ItemType& value)
{
	int num=0;
	finger = NULL;
	Item<ItemType> *temp;
	for(Item<ItemType> *v = first->to; v != first; v = v->to)
		if(v->item == value)
		{
			v->from->to = v->to;
			v->to->from = v->from;
			temp = v;
			v = v->from;
			delete temp;
			num++;
		}
	return num;
}

template<class ItemType>bool Bag<ItemType>::contains(const ItemType& value)const
{
	for(Item<ItemType> *v = first->to; v != first; v = v->to)if(v->item == value)return true;
	return false;
}
template<class ItemType>int Bag<ItemType>::count(const ItemType& value)const
{
	int num=0;
	for(Item<ItemType> *v = first->to; v != first; v = v->to)if(v->item == value)num++;
	return num;
}
template<class ItemType>void Bag<ItemType>::GET(void)const
{
	cout<<"\n************\norder: ";
	for(Item<ItemType> *v=first->to;v!=first;v=v->to)cout<<v->item<<' ';
	cout<<"\ninverse: ";
	for(Item<ItemType> *v=first->from;v!=first;v=v->from)cout<<v->item<<' ';
	cout<<endl;
	cout<<"************\n";
}

// Iteration functions
template<class ItemType>void Bag<ItemType>::start(void)
{
	finger = first->to;
	if(finger == first)cout<<"lease input item\n";
}
template<class ItemType>void Bag<ItemType>::next(void)
{
	if(finger == NULL)
	{
		cout<<"Please initializes\n";
		return;
	}
	finger = finger->to;
}
template<class ItemType>bool Bag<ItemType>::ended(void)const{return (finger==first||finger==NULL)? true:false;}
template<class ItemType>const ItemType& Bag<ItemType>:: currentValue(void)const
{
	if(finger == NULL)
	{
		cout<<"Please initializes\n";
		return first->item;
	}
	return finger->item;
}
template<class ItemType>int Bag<ItemType>::currentCount(void)const
{
	int i=1;
	if(finger == NULL)
	{
		cout<<"Please initializes\n";
		return 0;
	}
	for(Item<ItemType> *v = first->to;; v = v->to,i++)if(v == finger)return i;
}
//operator overload
template<class ItemType>const Bag<ItemType>& Bag<ItemType>::operator=(const Bag& Right)
{
	cout<<"Bag assignment operator\n";
	Item<ItemType> *v,*temp,*now;
	if(&Right == this)return *this;
	if(first != first->to)
	{
		for(v = first->to->to; v != first; v = v->to)delete v->from;
		delete first->from;
	}
	now = first = new Item<ItemType>;
	for(v = Right.first->to; v != Right.first; v = v->to)
	{
		temp = new Item<ItemType>;
		now->to = temp;
		temp->from = now;
		temp->item = v->item;
		now = temp;
	}
	first->from = now;
	now->to = first; 
	int i;
	for(v =Right.first->to,i=0; v!=Right.finger&&Right.finger!=NULL; i++,v=v->to);
	for(v = first->to; i>0; v = v->to,i--); 
	finger = v;
	return *this;
}

template<class ItemType>bool Bag<ItemType>::operator==(const Item<string>& Right)const
{
	if(strcmp(Right.item,item) == 0)return true;
	return false;
}

//non-member function

template<class IT>void combine(const Bag<IT>&bag1,const Bag<IT>&bag2, Bag<IT>&result)
{
	Item<IT> *v,*temp,*now;
	if(result.first != result.first->to)
	{
		for(v = result.first->to->to; v != result.first; v = v->to)delete v->from;
		delete result.first->from;
	}
	now = result.first = new Item<IT>;
	for(v = bag1.first->to; v != bag1.first; v = v->to)
	{
		temp = new Item<IT>;
		now->to = temp;
		temp->from = now;
		temp->item = v->item;
		now = temp;
		//cerr<<"**\n";
	}
	for(v = bag2.first->to; v != bag2.first; v = v->to)
	{
		temp = new Item<IT>;
		now->to = temp;
		temp->from = now;
		temp->item = v->item;
		now = temp;
		//cerr<<"++\n";
	}
	result.first->from = now;
	now->to = result.first; 
	result.finger = NULL;
	return;
}
template<class IT>void subtract(const Bag<IT>&bag1,const Bag<IT>&bag2, Bag<IT>&result)
{
	Bag<IT>copy = bag1;
	Item<IT> *v1,*v2,*temp,*now;
	if(result.first != result.first->to)
	{
		for(v1 = result.first->to->to; v1 != result.first; v1 = v1->to)delete v1->from;
		delete result.first->from;
	}
	for(v1 = bag2.first->to; v1 != bag2.first; v1 = v1->to)
		for(v2 = copy.first->to; v2 != copy.first; v2 = v2->to)
			if(v2->item == v1->item)
			{
				copy.erase(v2->item);
				break;
			}
	now = result.first = new Item<IT>;
	for(v1 = copy.first->to; v1 != copy.first; v1 = v1->to)
	{
		temp = new Item<IT>;
		now->to = temp;
		temp->from = now;
		temp->item = v1->item;
		now = temp;
	}
	result.first->from = now;
	now->to = result.first; 
	result.finger = NULL;
	return;
}
