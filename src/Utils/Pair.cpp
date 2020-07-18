#include "Pair.h"

using namespace Utils;

template <typename T, typename T2>
Pair<T, T2>::Pair(const T& firstItem, const T2& secendItem)
{
    this->m_firstItem = firstItem;
    this->m_secendItem = secendItem;
}

template <typename T, typename T2>
void Pair<T, T2>::Print()
{
    std:: cout << this->m_firstItem << ": " << this->m_secendItem << std::endl;
}

template <typename T, typename T2>
T& Pair<T, T2>::GetFirstItem()
{
    return this->m_firstItem;
}

template <typename T, typename T2>
T2& Pair<T, T2>::GetSecendItem()
{
    return this->m_secendItem;
}

template <typename T, typename T2>
void Pair<T, T2>::SetFirstItem(const T& firstItem)
{
    this->m_firstItem = firstItem;
}

template <typename T, typename T2>
void Pair<T, T2>::SetSecendItem(const T2& secendItem)
{
    this->m_secendItem = secendItem;
}

