#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_TEMP_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_TEMP_H

//the class
template<typename T>
class SmartPtr
{
public:
    explicit SmartPtr(T * p);
    ~SmartPtr();
    //overload operator-> 	!!!
    //overload operator*	!!!

private:
    SmartPtr(const SmartPtr&);
    SmartPtr& operator=(const SmartPtr&);

    T * m_ptr;
    //bool owner;
};


template<typename T>
SmartPtr::SmartPtr(T * p):owner(true)
{
    m_ptr = p;
}

template<typename T>
SmartPtr::~SmartPtr()
{
    //if(owner)
    delete p;
}

/*
template<typename T>
SmartPtr& operator=(const SmartPtr& sp)
{
	m_ptr = sp.m_ptr;
	sp.owner = false;
	owner = true;
	return *this;
}*/


int main()
{
    SmartPtr<Person> p(new Person);
    p->setName();
    *p = Person("Moshe");
}
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_TEMP_H
