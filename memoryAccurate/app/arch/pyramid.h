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
#include <map>
#include <typeinfo>
#include <type_traits>

class IPyramid
{
private:
	IPyramid* pMaster;
	std::vector<IPyramid*> _vertex;
	// 	Network
	// 	SubPyramids
	//	Neighbors
	//	Ecosystem
	//  AddNetwork
	//
	std::map<int,IPyramid*> _populations;
protected:

	static const int TRIO = 3;
	static const int PENTA = 5;
	static const int HEPTA = 7;


	virtual int pyramid_cout()
	{
		return TRIO;
	}

	void declarePopulation(IPyramid* p)
	{
		_vertex.push_back(p);

		const std::type_info&
		t1 = typeid(*p);
		int type_code = t1.hash_code();
		_populations[type_code] = p;
	}

public:
	IPyramid()
	{
		pMaster = NULL;
	}

	IPyramid(IPyramid* master)
	{
		pMaster = master;
	}

	IPyramid* pyramidHierarchy()
	{
		// Return all related-hierarchy for this pyramid
		// An array of 
		return NULL;
	}

	// Py only support one Parent ?
	int addVertex(IPyramid* py)
	{
		if (py->pMaster != NULL)
		{
			return 2;	// Already has master
		}
		else if (_vertex.size() < pyramid_cout())
		{
			_vertex.push_back(py);

			IPyramid* pEnum = pMaster;
			while (pEnum->pMaster != NULL)
			{
				declarePopulation(pEnum->pMaster);
				pEnum = pEnum->pMaster;
			}
			return 0;	// Success
		}
		else
		{
			return 1;	// Full of quota
		}
	}

	IPyramid* vertex(int i)
	{
		return _vertex[i];
	}

	template <class T>
	T* vertex()
	{
		// Find by type
		if (std::is_same<T,decltype(*pMaster)>::value)
		{
			return (T*)pMaster;
		}
		else 
		{
			int typehash = typeid(T).hash_code();
			if (_populations.count(typehash) > 0)
			{
				return (T*)_populations[typehash];
			}
		}
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
