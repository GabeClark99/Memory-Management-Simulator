#ifndef FRAME_HPP
#define FRAME_HPP

#include <string>

class Frame
{
	private:
		int id;
		int storedPage;

	public:
		Frame(int id);
		void SetId(int id);
		void SetStoredPage(int storedPage);
		int GetId();
		int GetStoredPage();
};

#endif
