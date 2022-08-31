#include <stdexcept>


template<typename T>
/*abstract*/class IIndexable
{
private:
	IIndexable()
	{
		//haha you can't call this
	}

public:

	virtual T operator [](int index)
	{
		throw std::bad_exception("OVERRIDE THIS");
		//figure out how to override this next time or just make this a virtual function
	}

	//virtual void IncreaseLength()
	//{
	//	throw std::bad_exception("YOU CAN'T INCREASE THE HEIGHT OF https://www.bing.com/search?q=static+datastructor&form=WSBEDG&qs=SW&cvid=30edba4f93c249e18a9d3b932ef877b3&pq=static+datastructor&cc=US&setlang=en-US&PC=DCTS&nclid=FFA46D9F59F7B7CC9D9FDEC0EF0D3C71&ts=1661813737545&wsso=Moderate");
	//}
};
