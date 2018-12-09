#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
#include <iostream>

template<typename T>
class UniquePtr
{
public:
    explicit UniquePtr( T* ptr);
    //UniquePtr() { throw std::invalid_argument("error null pointer"); };
    ~UniquePtr() { delete(m_ptr); };

    T& operator=(T*);
    T* operator->() const;
    T& operator*() const;
    operator bool() const;
    T* get() const;

private:
    // Prevent coping
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);


    T*   m_ptr;
};

template <typename T>
UniquePtr<T>::UniquePtr( T* ptr):m_ptr(ptr)
{
    if (!ptr)
        throw std::invalid_argument("error null pointer");
}

template <typename T>
T & UniquePtr<T>::operator * () const {  return *m_ptr; }

template <typename T>
T * UniquePtr<T>::operator -> () const { return m_ptr; }

template <typename T>
T * UniquePtr<T>:: get() const { return m_ptr; }

template<typename T>
UniquePtr<T>::operator bool()const
{
    return dynamic_cast<T *>(get()) != NULL;
}
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
