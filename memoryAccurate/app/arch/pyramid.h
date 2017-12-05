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
	IPyramid* pParent;
	std::vector<IPyramid*> _vertex;
	// 	Network
	// 	SubPyramids
	//	Neighbors
	//	Ecosystem
	//  AddNetwork
	//
protected:

	static const int TRIO = 3;
	static const int PENTA = 5;
	static const int HEPTA = 7;

	virtual int pyramid_cout()
	{
		return TRIO;
	}

public:
	IPyramid()
	{
		pParent = NULL;
	}

	IPyramid(IPyramid* parent)
	{
		pParent = parent;
	}

	int addVertex(IPyramid* py)
	{
		if (py->pParent != NULL)
		{
			return 2;	// Already has parent
		}
		else if (_vertex.size() < pyramid_cout())
		{
			_vertex.push_back(py);
			return 0;					// Success
		}
		else
		{
			return 1;	// Full of quota
		}
	}

	IPyramid& vertex(int i)
	{
		return _vertex[i];
	}

	template <class T>
	T* vertex()
	{
		return NULL;
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
