#include "Useless.h"

int Useless::s_nObjects{ 0 };

Useless::Useless() : m_nElems(0), m_data(nullptr)
{
	++s_nObjects;
	printCall("Useless()");
}

Useless::Useless(int k) : m_nElems(k)
{
	m_data = new char[k];
	++s_nObjects;
	printCall("Useless(int k)");
}

Useless::Useless(int k, char c) : m_nElems(k)
{
	m_data = new char[k];
	for (int i = 0; i < k; ++i)
	{
		m_data[i] = c;
	}
	++s_nObjects;
	printCall("Useless(int k, char c)");
}

Useless::Useless(const Useless& other) : m_nElems(other.m_nElems)
{
	m_data = new char[m_nElems];
	for (int i = 0; i < m_nElems; ++i)
	{
		m_data[i] = other.m_data[i];
	}
	++s_nObjects;
	printCall("Useless(const Useless& other)");
}

Useless::Useless(Useless&& other) noexcept : m_nElems(other.m_nElems)
{
	// Pilfer the data
	m_data = other.m_data;

	// Clear out other
	other.m_data = nullptr;
	other.m_nElems = 0;

	++s_nObjects;
	printCall("Useless(Useless&& other)");
}

Useless::~Useless()
{
	--s_nObjects;
	printCall("~Useless()");
}

Useless Useless::operator+(const Useless& other) const
{
	printCall("operator+(const Useless& other) const");

	Useless result(m_nElems + other.m_nElems);
	for (int i = 0; i < m_nElems; ++i)
	{
		result.m_data[i] = m_data[i];
	}
	for (int i = 0; i < other.m_nElems; ++i)
	{
		result.m_data[i + m_nElems] = other.m_data[i];
	}
	return result;
}

void Useless::print(std::string varName) const
{
	std::cout << "\"" << varName << "\"" << std::endl;
	std::cout << "Number of elements: " << m_nElems << std::endl;
	std::cout << "Data Address: " << static_cast<void*>(m_data) << std::endl;
	if (m_nElems > 0)
	{
		std::cout << "Data: \"";
		for (int i = 0; i < m_nElems; ++i)
		{
			std::cout << m_data[i];
		}
		std::cout << "\"" << std::endl;
	}
}

void Useless::printCall(std::string methodName)
{
	std::cout << "---" << std::endl;
	std::cout << methodName << " called. Number of objects=" << s_nObjects << std::endl;

}
