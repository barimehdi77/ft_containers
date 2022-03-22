/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:35:47 by mbari             #+#    #+#             */
/*   Updated: 2022/03/22 22:50:34 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector/vector.hpp"
#include <vector>

#ifndef	PH
#define	PH	ft
#endif

int main(){
	// // *************************************************************************
	// 							//NOTE - Vector
	// // *************************************************************************

	//NOTE - Constructor
	{

		std::cout << "------------- Library  -------------" << std::endl;
		PH::vector<int> first1;
		PH::vector<int> second (4,100);
		PH::vector<int> third (second.begin(),second.end());
		PH::vector<int> fourth (third);
		int myints[] = {16,2,77,29};
		PH::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		std::cout << "The contents of fifth are:";
		for (PH::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

	}
	{

	//NOTE - Assign content (operator=)
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> foo1 (3,0);
	PH::vector<int> bar1 (5,0);
	bar1 = foo1;
	foo1 = PH::vector<int>();
	std::cout << "Size of foo: " << int(foo1.size()) << '\n';
	std::cout << "Size of bar: " << int(bar1.size()) << '\n';

	}
	{

	//NOTE - Return iterator to beginning
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	for (int i=1; i<=5; i++) myvector1.push_back(i);
	std::cout << "myvector contains:";
	for (PH::vector<int>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	}
	{


	//NOTE - Return iterator to end
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	for (int i=1; i<=5; i++) myvector1.push_back(i);
	std::cout << "myvector contains:";
	for (PH::vector<int>::iterator it = myvector1.begin() ; it != myvector1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	}
	{

	// NOTE - Return reverse iterator to reverse beginning
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1 (5);  // 5 default-constructed ints
	int i1=0;
	PH::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
	for (; rit1!= myvector1.rend(); ++rit1)
		*rit1 = ++i1;
	std::cout << "myvector contains:";
	for (PH::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	}

	{
	// NOTE - Return reverse iterator to reverse end
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1 (5);
	PH::vector<int>::reverse_iterator rit1 = myvector1.rbegin();
	int i1=0;
	for (rit1 = myvector1.rbegin(); rit1!= myvector1.rend(); ++rit1)
		*rit1 = ++i1;
	std::cout << "myvector contains:";
	for (PH::vector<int>::iterator it1 = myvector1.begin(); it1 != myvector1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	}
	{
	// NOTE - Return size
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myints1;
	std::cout << "0. size: " << myints1.size() << '\n';
	for (int i=0; i<10; i++) myints1.push_back(i);
	std::cout << "1. size: " << myints1.size() << '\n';
	myints1.insert (myints1.end(),10,100);
	std::cout << "2. size: " << myints1.size() << '\n';
	myints1.pop_back();
	std::cout << "3. size: " << myints1.size() << '\n';
	}
	{
	// NOTE - Return maximum size
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	for (int i=0; i<100; i++) myvector1.push_back(i);
	std::cout << "size: " << myvector1.size() << "\n";
	std::cout << "capacity: " << myvector1.capacity() << "\n";
	std::cout << "max_size: " << myvector1.max_size() << "\n";
	}
	{

		// NOTE - Change size
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector1;
		for (int i=1;i<10;i++) myvector1.push_back(i);
		myvector1.resize(9);
		myvector1.resize(12,100);
		myvector1.resize(12);
		std::cout << myvector1.size() << std::endl;
		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector1.size();i++)
			std::cout << ' ' << myvector1[i];
		std::cout << '\n';
	}
	{

	// NOTE - Return size of allocated storage capacity
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	for (int i=0; i<100; i++) myvector1.push_back(i);
	std::cout << "size: " << (int) myvector1.size() << '\n';
	std::cout << "capacity: " << (int) myvector1.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector1.max_size() << '\n';
	}
	{

	// NOTE - Test whether vector is empty
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	int sum1 (0);
	for (int i=1;i<=10;i++) myvector1.push_back(i);
	while (!myvector1.empty())
	{
		sum1 += myvector1.back();
		myvector1.pop_back();
	}
	std::cout << "total: " << sum1 << '\n';
	}
	{

	// NOTE - Request a change in capacity
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int>::size_type sz1;
	PH::vector<int> foo1;
	sz1 = foo1.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo1.push_back(i);
		if (sz1!=foo1.capacity()) {
		sz1 = foo1.capacity();
		std::cout << "capacity changed: " << sz1 << '\n';
		}
	}
	PH::vector<int> bar1;
	sz1 = bar1.capacity();
	bar1.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar1.push_back(i);
		if (sz1!=bar1.capacity()) {
		sz1 = bar1.capacity();
		std::cout << "capacity changed: " << sz1 << '\n';
		}
	}
	}
	{

	// NOTE - Access element
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1 (10);
	PH::vector<int>::size_type sz1 = myvector1.size();
	for (unsigned i=0; i<sz1; i++) myvector1[i]=i;
	for (unsigned i=0; i<sz1/2; i++)
	{
		int temp1;
		temp1 = myvector1[sz1-1-i];
		myvector1[sz1-1-i]=myvector1[i];
		myvector1[i]=temp1;
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz1; i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';

	}
	{

	// NOTE - Access element
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1 (10);
	for (unsigned i=0; i<myvector1.size(); i++)
		myvector1.at(i)=i;
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector1.size(); i++)
		std::cout << ' ' << myvector1.at(i);
	std::cout << '\n';
	}
	{

	// NOTE - Access first element
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	myvector1.push_back(78);
	myvector1.push_back(16);
	myvector1.front() -= myvector1.back();
	std::cout << "myvector.front() is now " << myvector1.front() << '\n';
	}
	{


	// NOTE - Access last element
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> myvector1;
	myvector1.push_back(10);
	while (myvector1.back() != 0)
	{
		myvector1.push_back ( myvector1.back() -1 );
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector1.size() ; i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	}
	{

	// NOTE - Assign vector content
	std::cout << "------------- Library -------------" << std::endl;
	PH::vector<int> first1;
	PH::vector<int> second1;
	PH::vector<int> third1;
	first1.assign (7,100);
	PH::vector<int>::iterator it1;
	it1=first1.begin()+1;
	second1.assign (it1,first1.end()-1);
	int myints1[] = {1776,7,4};
	third1.assign (myints1,myints1+3);
	std::cout << "Size of first: " << int (first1.size()) << '\n';
	std::cout << "Size of second: " << int (second1.size()) << '\n';
	std::cout << "Size of third: " << int (third1.size()) << '\n';
	}

	// {
	// // NOTE - Add element at the end
	// std::cout << "------------- Library -------------" << std::endl;
	// PH::vector<int> myvector1;
	// int myint1;
	// std::cout << "Please enter some integers (enter 0 to end):\n";
	// do {
	// 	std::cin >> myint1;
	// 	myvector1.push_back (myint1);
	// } while (myint1);
	// std::cout << "myvector stores " << int(myvector1.size()) << " numbers.\n";

	// }
	{
		// NOTE - Delete last element
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector1;
		int sum1 (0);
		myvector1.push_back (100);
		myvector1.push_back (200);
		myvector1.push_back (300);
		while (!myvector1.empty())
		{
			sum1+=myvector1.back();
			myvector1.pop_back();
		}
		std::cout << "The elements of myvector add up to " << sum1 << '\n';
	}
	{
		// NOTE - Clear content
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector1;
		myvector1.push_back (100);
		myvector1.push_back (200);
		myvector1.push_back (300);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); i++)
			std::cout << ' ' << myvector1[i];
		std::cout << '\n';
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		myvector1.clear();
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		myvector1.push_back (1101);
		myvector1.push_back (2202);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); i++)
			std::cout << ' ' << myvector1[i];
		std::cout << '\n';
	}
	{

		// NOTE - Insert elements
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector1(3, 100);
		std::cout << "myvector size : " << myvector1.size() << std::endl;
		std::cout << "myvector capacity: " << myvector1.capacity() << std::endl;
		PH::vector<int>::iterator it1;
		it1 = myvector1.begin();
		it1 = myvector1.insert ( it1, 200 );
		myvector1.insert(it1, 2, 300);
		it1 = myvector1.begin();
		PH::vector<int> anothervector1 (2,400);
		std::cout << "myvector size : " << myvector1.size() << std::endl;
		std::cout << "myvector capacity : " << myvector1.capacity() << std::endl;
		myvector1.insert (it1+2,anothervector1.begin(),anothervector1.end());
		std::cout << "myvector size : " << myvector1.size() << std::endl;
		std::cout << "myvector capacity : " << myvector1.capacity() << std::endl;
		int myarray1 [] = { 501,502,503 };
		myvector1.insert (myvector1.begin(), myarray1, myarray1+3);
		std::cout << "myvector contains:";
		for (it1=myvector1.begin(); it1<myvector1.end(); it1++)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}
	{
		PH::vector<int> vec1;
		vec1.push_back(10);
		vec1.push_back(20);
		vec1.push_back(30);
		vec1.push_back(40);
		PH::vector<int>::iterator it1 = vec1.insert(vec1.begin(), 3);
		vec1.insert(it1, 2);
		int i1 = 2;
		it1 = vec1.insert(vec1.begin() + i1, 7);
		std::cout << "The vector elements are: ";
		for (PH::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
			std::cout << *it1 << " ";
	}
	{
		// NOTE - Erase elements
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector1;
		for (int i=1; i<=10; i++) myvector1.push_back(i);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); ++i)
			std::cout << ' ' << myvector1[i];
		std::cout << std::endl;
		myvector1.erase (myvector1.begin() - 1);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); ++i)
			std::cout << ' ' << myvector1[i];
		std::cout << std::endl;
		myvector1.erase (myvector1.begin(),myvector1.begin()+3);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); ++i)
			std::cout << ' ' << myvector1[i];
		std::cout << std::endl;
	}
	{
		// NOTE - Erase elements
		std::cout << "------------- Library -------------" << std::endl;
		std::vector<int> myvector1;
		for (int i=1; i<=10; i++) myvector1.push_back(i);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		myvector1.erase (myvector1.begin() - 1);
		myvector1.erase (myvector1.begin(),myvector1.begin()+3);
		std::cout << myvector1.size() << std::endl;
		std::cout << myvector1.capacity() << std::endl;
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector1.size(); ++i)
			std::cout << ' ' << myvector1[i];
		std::cout << std::endl;
	}
	{


		// NOTE - Swap content
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> foo1(3, 100);   // three ints with a value of 100
		PH::vector<int> bar1(5, 200);   // five ints with a value of 200
		std::cout << "Size foo1 before " << foo1.size() << std::endl;
		std::cout << "Capa foo1 before " << foo1.capacity() << std::endl;
		std::cout << "Size bar1 before " << bar1.size() << std::endl;
		std::cout << "Capa bar1 before " << bar1.capacity() << std::endl;
		foo1.swap(bar1);
		std::cout << "Size foo1 after " << foo1.size() << std::endl;
		std::cout << "Capa foo1 after " << foo1.capacity() << std::endl;
		std::cout << "Size bar1 after " << bar1.size() << std::endl;
		std::cout << "Capa bar1 after " << bar1.capacity() << std::endl;
		std::cout << "foo contains:";
		for (unsigned i=0; i<foo1.size(); i++)
			std::cout << ' ' << foo1[i];
		std::cout << '\n';
		std::cout << "bar contains:";
		for (unsigned i=0; i<bar1.size(); i++)
			std::cout << ' ' << bar1[i];
		std::cout << '\n';
	}
	{


		// NOTE - Get allocator
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> myvector;
		int * p;
		unsigned int i;
		p = myvector.get_allocator().allocate(5);
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	{

		// NOTE - Relational operators for vector
		PH::vector<int> foo (1,200);
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> bar (0);
		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{


		// NOTE - Exchange contents of vectors
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> foo (3,100);   // three ints with a value of 100
		PH::vector<int> bar (5,200);   // five ints with a value of 200
		// foo(bar);//NOTE:
		std::cout << "foo contains:";
		for (PH::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "bar contains:";
		for (PH::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		//NOTE - compare it and const-it
		std::cout << "------------- Library -------------" << std::endl;
		PH::vector<int> foo (3,100);   // three ints with a value of 100
		PH::vector<int> bar (5,200);   // five ints with a value of 200
		std::cout << "foo contains:";
		for (PH::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
		std::cout << "bar contains:";
		for (PH::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}
