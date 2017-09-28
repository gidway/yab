// Copyright 2017 (C) Gidway, PL :: gidway.net

#pragma once

namespace gidway {

class Size;

template <typename _SizeType = int, _SizeType _Empty = 0>
class _size_base
{
public: // types

	using sizetype = _SizeType;

public: // constructors

	virtual ~_size_base (void) {}

	explicit _size_base (void) {}

	template <typename T>
	_size_base (const T __value)
		: _value(static_cast<_SizeType>(__value))
	{
	}

	template <typename T>
	_size_base (const T & __value)
		: _value(static_cast<_SizeType>(__value))
	{
	}

public: // interface

	/**
	 */
	virtual _SizeType value (void) const {
		return _value;
	}

public: // operators

	template <typename S, S E>
	inline bool operator == (const _size_base<S, E> & __sb) const {
		return (value() == static_cast<sizetype>(__sb.value()));
	}

	template <typename T>
	inline bool operator == (const T & __value) const {
		return (value() == static_cast<sizetype>(__value));
	}

public: // statics methods
	/**
	 */
	static const _size_base<_SizeType, _Empty> & empty() noexcept {
		static const _size_base<_SizeType, _Empty> _sb;
		return _sb;
	}

protected:

	sizetype _value { static_cast<_SizeType>(_Empty) };
}; // class _size_base<T, E>

/**
 */
class Size
	: public _size_base<unsigned>
{
public:
	using _base = _size_base<unsigned>;
	using _base::_size_base;

	virtual ~Size (void) = default;
}; // class Size

template <typename S, typename T, S E>
inline operator _size_base<S, E> (T __v) {
	return _size_base<S, E>(__v);
}

} // namespace gidway
