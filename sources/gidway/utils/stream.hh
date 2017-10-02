// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

#include <logs/debug.hh> // debuglog

namespace gidway {

template <class TCollection, typename TPos, typename TRet>
class iterator { // FIXME _const (only)
	mutable TCollection * _collection;
	mutable TPos _pos;
public:
	using iterator_type = ::gidway::iterator<TCollection, TPos, TRet>;

	virtual ~iterator (void) = default;

	iterator (const TCollection * __collection, const TPos __pos)
		: _collection(const_cast<TCollection*>(__collection))
		, _pos(__pos)
	{
	}

	iterator (const iterator_type & __it)
		: _collection(__it._collection)
		, _pos(__it._pos)
	{
	}

	const iterator_type & operator ++ (void) const {
		debugtrace // debuglog
		++_pos;
		debuglog << logs::value("_pos", _pos) << logs::end;
		return *this;
	}

	virtual inline const TRet & get (void) const {
		debugtrace // debuglog
		return (*_collection).at(_pos);
	}

	const TRet & operator * (void) const {
		debugtrace // debuglog
		return get();
	}

	bool operator == (const iterator_type & it) const {
		debugtrace // debuglog
		return (_pos == it._pos);
	}

	bool operator != (const iterator_type & it) const {
		debugtrace // debuglog
		return (not operator==(it));
	}

}; // class iterator

namespace streams {
namespace no_allocation {
/**
 * This stream are based on raw pointers and data allocated before.
 * Is more like soft wrapper on pointer to array without any extra allocation.
 */
template <class TAllocation, class TSize = unsigned long long>
class not_allocated
{
	const TSize _begin;
	const TSize _end;
	const TAllocation * _allocation {nullptr};

public:
	using iterator = ::gidway::iterator<not_allocated<TAllocation, TSize>, TSize, TAllocation>;
	using item_type = TAllocation;
	using size_type = TSize;

	virtual ~not_allocated (void) = default;

	not_allocated (
			const TAllocation * __allocation,
			const TSize __begin,
			const TSize __end)
		: _allocation(__allocation)
		, _begin(__begin)
		, _end(__end)
	{
	}

	const iterator begin (void) const {
		const iterator it (this, _begin);
		return it;
	}

	const iterator end (void) const {
		const iterator it (this, _end);
		return it;
	}

	const TAllocation & at (const TSize __index) const {
		debugtrace // debuglog
		debuglog << "__index=" << (int)__index << logs::end;
		static const auto _sizeof = sizeof(TAllocation);
		debuglog << "_sizeof=" << (int)_sizeof << logs::end;
		const TAllocation * _ret = & _allocation[(_sizeof * ((decltype(_sizeof))__index))];
		debugtrace // debuglog
		return *_ret;
	}

}; // class not_allocated

template <class TChar>
class _not_allocated_chars
	: public not_allocated<TChar, unsigned long long>
{
protected:
	virtual ~_not_allocated_chars (void) = default;
	_not_allocated_chars (void) = default;
public:
	using _not_allocated = not_allocated<TChar, unsigned long long>;
	using _not_allocated::not_allocated;
	using _not_allocated::size_type;
}; // class _not_allocated_chars

template <class TChar = char>
class chars_base
	: public _not_allocated_chars<TChar>
{
	using _base = _not_allocated_chars<TChar>;
public:
	static constexpr auto end_stream = '\0';

	virtual ~chars_base (void) = default;

	chars_base (const TChar * __chars)
		: _base::_not_allocated_chars(__chars
				, (typename _base::size_type)0
				, (typename _base::size_type)0) // FIXME
	{
	}

}; // class chars / not_allocated

using uchars = chars_base<unsigned char>;
using schars = chars_base<signed char>;
using chars  = chars_base<>;

} // namespace no_allocation
} // namespace streams
} // namespace gidway
