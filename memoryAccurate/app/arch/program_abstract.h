/*
 * program_abstract.h
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#ifndef APP_ARCH_PROGRAM_ABSTRACT_H_
#define APP_ARCH_PROGRAM_ABSTRACT_H_

#include <vector>
#include <string>

// Define any program, from simplest to most complex in whole universal
class IProgram
{
public:
	virtual ~IProgram() {};
	virtual int main() = 0;
};

class ISequence : public IProgram
{
	// Define a program run based on sequence of programs 
private:
	std::vector<IProgram*> _sequence;
public:
	virtual ~ISequence() {};
	ISequence(IProgram* arrProgram[], int n) {
		_sequence.clear();
		for (int i=0;i<n;i++) {
			_sequence.push_back(arrProgram[i]);
		}
	};

	void add(IProgram* p)
	{
		//_sequence.push_back(p);
	}

	void remove(IProgram* p)
	{
		//_sequence.remove(p);
	}

	virtual int main()
	{
		for (int i=0;i<_sequence.size();i++) {
			_sequence[i]->main();
		}
		return 0;
	}
};

class IParallel : public IProgram
{
	// Define a program run based on parallel of programs
private:	
	std::vector<IProgram*> _parallel;
public:
	virtual ~IParallel() {}
	IParallel(IProgram* arr[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			_parallel.push_back(arr[i]);
		}
	}

	void add(IProgram* p)
	{
		//_parallel.push_back(p);
	}

	void remove(IProgram* p)
	{
		//_parallel.remove(p);
	}

	virtual int main()
	{
		for (int i = 0; i < _parallel.size(); ++i)
		{
			// New thread for each 
		}
	}
};

class IUnknown : public IProgram 
{
private:
	std::vector<IProgram*> _vprogs;
public:
	virtual ~IUnknown()	 {};
	IUnknown(IProgram* arr[], int n)
	{
		_vprogs.clear();
		for (int i = 0; i < n; ++i)
		{
			_vprogs.push_back(arr[i]);
		}
	}

	void add(IProgram* p)
	{
		//_parallel.push_back(p);
	}

	void remove(IProgram* p)
	{
		//_parallel.remove(p);
	}
};

class CUnknownProg : public IUnknown
{
public:
	CUnknownProg(IProgram* arr[], int n): IUnknown(arr,n) {};

	virtual int main() { return 0; }
};

#endif /* APP_ARCH_PROGRAM_ABSTRACT_H_ */
