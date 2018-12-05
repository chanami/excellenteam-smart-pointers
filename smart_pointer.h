#ifndef EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
#define EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
#include <iostream>
template<typename T>
class UniquePtr
{
public:
    explicit UniquePtr(T* ptr):m_ptr(ptr) { if (!ptr)throw std::invalid_argument(); };
    UniquePtr() { throw std::invalid_argument(); };
    ~UniquePtr() { delete(m_ptr); };

    T* operator->() const;
    T& operator*()  const;

    T* get() const;

private:
    // Prevent coping
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);

    T*   m_ptr;
};

template <typename T>
T & UniquePtr<T>::operator * () const {  return *m_ptr; }

template <class T>
T * UniquePtr<T>::operator -> () const { return m_ptr; }

template <class T>
T * UniquePtr<T>:: get() const { return m_ptr; }
#endif //EXCELLENTEAM_ELLA_CPP_SMART_POINTERS_CHANAMI_SMART_POINTER_H
