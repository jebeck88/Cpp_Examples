#pragma once
class Functor
{
public:
	Functor(int d);

	bool operator()(int x) const;

private:
	int m_d;
};

