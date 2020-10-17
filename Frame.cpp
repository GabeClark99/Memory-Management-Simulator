#include "Frame.hpp"

#include <string>

using std::string;

Frame::Frame()
{
	this->id = "";
	this->storedPage = -1;
	return;
}

void Frame::SetId(string id)
{
	this->id = id;
	return;
}

void Frame::SetStoredPage(int storedPage)
{
	this->storedPage = storedPage;
	return;
}

string Frame::GetId()
{
	return this->id;
}

int Frame::GetStoredPage()
{
	return this->storedPage;
}

