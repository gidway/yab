// Copyright 2017 (C) Gidway, PL :: gidway.net
#pragma once

namespace gidway {

template <typename _SizeType = int, _SizeType _Empty = 0>
class _size_base
{
public: // types

	using _this = _size_base<_SizeType, _Empty>;
	using sizetype = _SizeType;

public: // constructors

	virtual ~_size_base (void) {}

	explicit _size_base (void) {}

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
	inline bool operator == (const _this & __sb) const {
		return (value() == static_cast<sizetype>(__sb.value()));
	}

	template <typename T>
	inline bool operator == (const T & __value) const {
		return (value() == static_cast<sizetype>(__value));
	}

	template <typename T>
	inline _this & operator () (const T & __value) {
		return value(__value);
	}

	template <typename T>
	inline _this & value (const T & __value) {
		_value = static_cast<_SizeType>(__value);
		return *this;
	}

	inline operator _SizeType () const {
		return static_cast<_SizeType>(value());
	}

	inline _this & operator = (const _SizeType __v) {
		return value(__v);
	}

	template <typename T>
	inline bool operator < (const T & __v) const {
		return (value() < static_cast<_SizeType>(__v));
	}

	template <typename T>
	inline bool operator > (const T & __v) const {
		return (value() > static_cast<_SizeType>(__v));
	}

	template <typename T>
	inline bool operator != (const T & __v) const {
		return (not this->operator==(__v));
	}

	template <typename T>
	inline bool operator ! () const {
		return (not static_cast<bool>(value()));
	}

	inline bool operator < (const _this & __sb) const {
		return (this->operator<(__sb.value()));
	}

	inline bool operator > (const _this & __sb) const {
		return (this->operator>(__sb.value()));
	}

	inline bool operator != (const _this & __sb) const {
		return (not this->operator==(__sb));
	}

	inline _this & operator ++ (void) {
		++_value;
		return *this;
	}

public: // statics methods
	/**
	 */
	static const _this & empty() noexcept {
		static const _this _sb;
		return _sb;
	}

protected:
	sizetype _value { static_cast<_SizeType>(_Empty) };

}; // class _size_base<T, E>

/**
 */
using USizeBig = _size_base<unsigned long long, 0ull>;
using USizeShort = _size_base<unsigned short, static_cast<unsigned short>(0u)>;
using USize = _size_base<unsigned, 0u>;
//
using ISizeBig = _size_base<signed long long, 0ull>;
using ISizeShort = _size_base<signed short, static_cast<unsigned short>(0u)>;
using ISize = _size_base<signed, 0u>;
//
using Size = USizeBig;

} // namespace gidway
