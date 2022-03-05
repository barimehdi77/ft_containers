/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:01:34 by mbari             #+#    #+#             */
/*   Updated: 2022/03/05 20:25:21 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "tree.hpp"
#include "utils.hpp"

namespace ft
{
	template <	class Key,												// map::key_type
				class T,												// map::mapped_type
				class Compare = std::less<Key>,							// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
				>
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef	Compare										value_comp;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		private:
			typedef Node<value_type>								Node_type;
			typedef Node_type*										Node_ptr;
			typedef Tree<value_type, value_comp, allocator_type>	Tree_type;
			typedef Tree_type*										Tree_ptr;


		public:
			typedef typename Tree_type::iterator				iterator;
			typedef typename Tree_type::const_iterator			const_iterator;
			// typedef reverse_iterator<>							reverse_iterator;
			// typedef reverse_iterator<>							const_reverse_iterator;

		private:
			Tree_type		_tree;
			allocator_type	_alloc;
			value_comp		_comp;


		public: /*             Iterators                         */
			iterator		begin()				{ return (this->_tree.begin()); };
			const_iterator	begin() const		{ return (this->_tree.begin()); };
			iterator		end()				{ return (this->_tree.end()); };
			const_iterator	end() const			{ return (this->_tree.end()); };

		public: /*             Capacity                         */
			bool		empty() const { return (this->_tree.empty()); };
			size_type	size() const { return (this->_tree.size()); };
			size_type	max_size()	const	{ return (this->_tree.max_size()); };


		public: /*             Modifiers                         */
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				iterator node = iterator(this->_tree.search(val.first));
				if (node != end())
					return (ft::pair<iterator,bool>(node, false));

				Node_ptr inserted_node = this->_tree.insert(val);
				return (ft::pair<iterator,bool>(iterator(inserted_node), true));
			};
			iterator insert (iterator position, const value_type& val)
			{
				Node_ptr node = position.base();
				if (val.first > predecessor(node)->key.first && val.first < successor(node)->key.first)
					position = iterator(this->_tree.insertInPossition(node, val));
				else
					position = insert(val).first;
				return position;
			};
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				// for (const_iterator it = end(); first != last; first++)
				// 	insert(it, *first);
				while (first != last)
				{
					this->_tree.insert(*first);
					first++;
				};
			};

			void erase (iterator position) { this->_tree.remove(*position); };
			size_type erase (const key_type& k)
			{
				size_type s = size();
				this->_tree.remove(*find(k));
				return (s - size());
			};
			void erase (iterator first, iterator last)
			{
				iterator position;
				while(first != last)
				{
					// std::c÷out << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The aftr erase ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
					position = first;
					first++;
					std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The befor erase ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
					print();
					std::cout << "\n\n\n\n\n┃━━━━━━━━━━━━━━━━━━━━━━━━━┃ Printing The after erase ┃━━━━━━━━━━━━━━━━━━━━━━━━┃\n\n\n\n\n" << std::endl;
					erase(position);
					print();
				}
			};
			void clear() { erase(begin(), end()); };

		public: /*             Operations                         */
			iterator		find (const key_type& k)		{ return (iterator(this->_tree.search(k))); }
			const_iterator	find (const key_type& k) const	{ return (const_iterator(this->_tree.search(k))); }

		public:
			void print() { this->_tree.print(); };
	};

};

#endif
