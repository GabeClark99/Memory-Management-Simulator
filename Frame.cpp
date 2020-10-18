// Gabriel Clark

#include "Frame.hpp"

#include <string>

using std::string;

Frame::Frame(int id)
{
	this->id = id;
	this->storedPage = -1;
	return;
}

void Frame::SetId(int id)
{
	this->id = id;
	return;
}

void Frame::SetStoredPage(int storedPage)
{
	this->storedPage = storedPage;
	return;
}

int Frame::GetId()
{
	return this->id;
}

int Frame::GetStoredPage()
{
	return this->storedPage;
}

