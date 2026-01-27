#include "Functor.h"

Functor::Functor(int d) : m_d(d)
{
}

bool Functor::operator()(int x) const
{
	return (x % m_d == 0);
}
