#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H
#include <iostream>

template<typename T>
class shared_ptr
{
public :

    explicit shared_ptr(T *ptr=NULL);
    ~shared_ptr();
    shared_ptr(const shared_ptr &ptr);

    shared_ptr& operator =(const shared_ptr &ptr);

    bool isvalid() const;
    int getCount() const;
    T* get() const;

    operator bool() const;
    bool operator!=(shared_ptr& other) const;
    bool operator==(shared_ptr& other) const;

    T* operator ->() const;
    T& operator *() const;

private :
    int *refCount;
    T* m_ptr;
};

template<typename T>
shared_ptr<T>::shared_ptr(T *ptr) :  m_ptr(ptr)
{
    if(ptr)
    {
        refCount = new int[1];
        *refCount=1;
    }
    else
        refCount = NULL;
}

template<typename T>
shared_ptr<T>::~shared_ptr()
{
    if(isvalid())
    {
        --(*refCount);
        if((*refCount) <= 0)
        {
            delete refCount;
            delete m_ptr;
        }

        refCount = NULL;
        m_ptr = NULL;
    }
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &ptr) : refCount(ptr.refCount), m_ptr(ptr.m_ptr)
{
    if(isvalid())
    {
        (*refCount)++;
    }
}

template<typename T>
shared_ptr<T>& shared_ptr<T>:: operator =(const shared_ptr &ptr)
{
//    shared_ptr  temp(ptr);
//    temp.swap(*this);
//    return *this;
    //for ctor
    shared_ptr<T> temp(ptr);

    //for dtor
    temp.refCount = refCount;
    temp.m_ptr = m_ptr;

    m_ptr = ptr.m_ptr;
    refCount = ptr.refCount;

    return *this;
}

template<typename T>
bool shared_ptr<T>::isvalid() const
{
    return (m_ptr != NULL && refCount != NULL);
}

template<typename T>
int shared_ptr<T>:: getCount() const
{
    if(refCount != NULL)
        return *refCount;
    else
        return 0;
}

template<typename T>
T* shared_ptr<T>::operator ->() const
{
    return m_ptr;
}

template<typename T>
T& shared_ptr<T>::operator *()const
{
    return *m_ptr;
}

template<typename T>
bool shared_ptr<T>::operator==(shared_ptr& other) const
 {
     return (m_ptr==other.m_ptr)&&(refCount==other.refCount);
 }

template<typename T>
bool shared_ptr<T>:: operator!=(shared_ptr& other) const
{
    return (m_ptr != other.m_ptr);
//    std::cout<<"here"<<std::endl;
//    return (m_ptr!=other.m_ptr)||(refCount!=other.refCount);
}

template<typename T>
T * shared_ptr<T>:: get() const
{
    return m_ptr;
}

template<typename T>
shared_ptr<T>::operator bool()const
{
    return dynamic_cast<T *>(get()) != NULL;
}
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SHARED_POINTER_H
