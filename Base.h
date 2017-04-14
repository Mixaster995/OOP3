#pragma once
#include<string>
class Printable
{
public:
	virtual std::string Print() const = 0;
};
class Named : public Printable
{
public:
	std::string name;
	std::string Print() const
	{
		return name;
	}
	Named(const std::string& input)
	{
		name = input;
	}
	virtual std::string GetName() const
	{
		return this->name;
	};
};