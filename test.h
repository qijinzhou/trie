#pragma once
#if defined(_MSC_VER)

// Microsoft Unit Test Framework for C++
#include <CppUnitTest.h>
// Test definitions
#define BEGIN_TEST_CLASS(name)		TEST_CLASS(##name){
#define END_TEST_CLASS				};
#define TEST(testCase, testName)	TEST_METHOD(##testName)
// Test assertions
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
#define EXPECT_TRUE(c)		Assert::IsTrue(c)
#define EXPECT_FALSE(c)		Assert::IsFalse(c)
#define EXPECT_EQ(e, a)		Assert::AreEqual(e, a)

#else

// Google C++ Testing Framework
#include <gtest/gtest.h>

// Test class - not available
#define BEGIN_TEST_CLASS(name)
#define END_TEST_CLASS

#endif
