#ifndef FRAME_HPP
#define FRAME_HPP

#include <string>

using std::string;

class Frame
{
	private:
		string id;
		int storedPage;

	public:
		Frame();
		void SetId(string id);
		void SetStoredPage(int storedPage);
		string GetId();
		int GetStoredPage();
};

#endif
