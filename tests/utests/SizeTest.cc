// Copyright 2017 (C) Gidway, PL :: gidway.net

#include <gtest/gtest.h>

#include <utils/size.hh>

/**
 * Any of size*object types must be tested in separate unit cases,
 * because are used differences types as base of value.
 */
class SizeTest : public ::testing::Test {
};

TEST_F(SizeTest, _default_de_constructor) {
	/*
	 */
	::gidway::Size _size;
}

TEST_F(SizeTest, _value_by_constructor) {
	/*
	 * Tested are assign constructor
	 * and convertion operator (on expect_eq macros)
	 */
	constexpr auto EXPECTED_VALUE = 13;

	::gidway::Size _size(EXPECTED_VALUE);

	EXPECT_EQ(_size, EXPECTED_VALUE);
	EXPECT_EQ(EXPECTED_VALUE, _size);
}

TEST_F(SizeTest, _compare_by_objects) {
	/*
	 */
	constexpr auto EXPECTED_VALUE = 100;

	::gidway::Size _size_lower((EXPECTED_VALUE / 2));
	::gidway::Size _size(EXPECTED_VALUE);
	::gidway::Size _size_higher((EXPECTED_VALUE * 2));

	{
		EXPECT_FALSE(_size < _size);
		EXPECT_FALSE(_size > _size);
		EXPECT_FALSE(_size != _size);
		//
		EXPECT_FALSE(!_size);
	}
	{
		EXPECT_TRUE(_size > _size_lower);
		EXPECT_TRUE(_size < _size_higher);
	}
	{
		EXPECT_TRUE(_size_lower != _size_higher);
		EXPECT_TRUE(_size_higher != _size_lower);
		EXPECT_TRUE(_size != _size_lower);
		EXPECT_TRUE(_size != _size_higher);
	}
	{
		EXPECT_TRUE(_size == _size);
		//
		EXPECT_FALSE(_size == _size_lower);
		EXPECT_FALSE(_size == _size_higher);
		EXPECT_FALSE(_size_lower == _size_higher);
		EXPECT_FALSE(_size_higher == _size_lower);
	}
}

TEST_F(SizeTest, _compare_by_values) {
	/*
	 */
	constexpr auto TESTED_VALUE = 64;
	constexpr auto NOT_EXPECTED_VALUE = 666;
	constexpr auto LOWER_VALUE  = (TESTED_VALUE / 2);
	constexpr auto HIGHER_VALUE = (TESTED_VALUE * 2);

	::gidway::Size _size(TESTED_VALUE);

	{
		EXPECT_EQ(_size, TESTED_VALUE);
		EXPECT_NE(NOT_EXPECTED_VALUE, _size);
	}
	{
		EXPECT_FALSE(_size < TESTED_VALUE);
		EXPECT_FALSE(_size > TESTED_VALUE);
		EXPECT_FALSE(_size != TESTED_VALUE);
		EXPECT_TRUE(_size == TESTED_VALUE);
	}
	{
		EXPECT_FALSE(TESTED_VALUE < _size);
		EXPECT_FALSE(TESTED_VALUE > _size);
		EXPECT_FALSE(TESTED_VALUE != _size);
		EXPECT_TRUE(TESTED_VALUE == _size);
	}
	{
		EXPECT_TRUE(LOWER_VALUE < _size);
		EXPECT_TRUE(_size > LOWER_VALUE);
		//
		EXPECT_FALSE(LOWER_VALUE > _size);
		EXPECT_FALSE(_size < LOWER_VALUE);
	}
	{
		EXPECT_TRUE(HIGHER_VALUE > _size);
		EXPECT_TRUE(_size < HIGHER_VALUE);
		//
		EXPECT_FALSE(HIGHER_VALUE < _size);
		EXPECT_FALSE(_size > HIGHER_VALUE);
	}
}

TEST_F(SizeTest, _empty_instance) {
	/*
	 * Size object as default is empty (zero value)
	 * So we check if is the same as empty instance.
	 */
	constexpr int EXPECTED_EMPTY_VALUE = 0;
	typedef ::gidway::_size_base<int, EXPECTED_EMPTY_VALUE> _SizeTested;
	_SizeTested _size;
	EXPECT_EQ(_size, _SizeTested::empty());
	EXPECT_EQ(_size, _size.empty());
	EXPECT_EQ(_SizeTested::empty().value(), EXPECTED_EMPTY_VALUE);
}

TEST_F(SizeTest, _operator_assign) {
	/*
	 */
	constexpr ::gidway::Size::sizetype ASSIGNED_FIRST_VALUE = 13;
	constexpr ::gidway::Size::sizetype ASSIGNED_SECOND_VALUE = 69;
	::gidway::Size _size;
	//
	EXPECT_EQ(_size, ::gidway::Size::empty());
	EXPECT_EQ(_size.value(), ::gidway::Size::empty().value());
	//
	{
		_size = ASSIGNED_FIRST_VALUE;
		//
		EXPECT_NE(_size, ::gidway::Size::empty());
		EXPECT_NE(_size.value(), ::gidway::Size::empty().value());
		EXPECT_EQ(_size, ASSIGNED_FIRST_VALUE);
	}
	//
	{
		_size.value(ASSIGNED_SECOND_VALUE);
		//
		EXPECT_NE(_size, ::gidway::Size::empty());
		EXPECT_NE(_size.value(), ::gidway::Size::empty().value());
		EXPECT_NE(_size, ASSIGNED_FIRST_VALUE);
		EXPECT_EQ(_size, ASSIGNED_SECOND_VALUE);
	}
	//
	EXPECT_EQ(_size.value(ASSIGNED_FIRST_VALUE), ASSIGNED_FIRST_VALUE);
}
