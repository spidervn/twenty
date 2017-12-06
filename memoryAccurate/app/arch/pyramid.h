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

/*
@TODO:
	- Good Naming for Vertex; Ally class
*/

class IPyramidArchitecture;

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
	friend class IPyramidArchitecture;
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

	// Py only support one Parent ?
	int addVertex(IPyramid* py)
	{
		if (py->pMaster != NULL)
		{
			return 2;	// Already has master
		}
		/*
		else if (std::is_same<decltype(py->_pAllyPrototype), decltype(this)>::value)
		{
			return 4;	// Unsupported Ally
		}
		*/
		else if (_vertex.size() < pyramid_cout())
		{
			_vertex.push_back(py);

			IPyramid* pEnum = this;
			while (pEnum != NULL)
			{
				declarePopulation(this);
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

	template<class T>
	T* vertex()
	{
		for (int i=0;i<_vertex.size();i++)
		{
			if (std::is_same<T*,decltype(_vertex[i])>::value)
			{
				return (T*)_vertex[i];
			}
		}

		return NULL;
	}

	template <class T>
	T* vertexHigher()
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

// Deprecated
class IPyramidArchitecture
{
protected:
	void tiePyramid(IPyramid* pHigher, IPyramid* pLower)
	{
		pHigher->addVertex(pLower);
	}
public:
	virtual void designPyramid()=0;
};


#endif /* APP_ARCH_PYRAMID_H_ */
