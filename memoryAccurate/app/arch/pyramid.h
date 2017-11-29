/*
 * pyramid.h
 *
 *  Created on: Nov 27, 2017
 *      Author: spider
 */

#ifndef APP_ARCH_PYRAMID_H_
#define APP_ARCH_PYRAMID_H_

#include <stdlib.h>
#include <vector>

class IPyramid
{
private:
	std::vector<IPyramid> _assists;
protected:

	static const int TRIO = 3;
	static const int PENTA = 5;
	static const int HEPTA = 7;

	virtual int pyramid_cout()
	{
		return TRIO;
	}

public:
	int addAssist(IPyramid py)
	{
		if (_assists.size() < pyramid_cout())
		{
			_assists.push_back(py);
			return 0;
		}
		else
		{
			return 1;	// Full of quota
		}
	}

	IPyramid& getAssist(int i)
	{
		return _assists[i];
	}

	void registerEvent(int EVENT, IPyramid* pDestination, int EVENT_DESTINATION)
	{
	}

	virtual ~IPyramid() {}
};

// Families which not contains more than 3 public methods (not count Constructors & destructors)
class IPyramidTrio : public IPyramid
{
public:
	IPyramidTrio()
	{

	};
};

// Families which not contains more than 5 public methods (not count Constructors & destructors)
class IPyramidPenta : public IPyramid
{
protected:
	virtual int pyramid_cout()
	{
		return PENTA;
	}
public:
};

// Families which not contains more than 7 public methods (not count Constructors & destructors)
class IPyramidHepta : public IPyramid
{
protected:
	virtual int pyramid_cout()
	{
		return HEPTA;
	}
};

#endif /* APP_ARCH_PYRAMID_H_ */
