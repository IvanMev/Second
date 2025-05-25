#include "CppUnitTest.h"
#include "C:\Users\Ivan\source\repos\LinkedListSolution\LinkedListSolution\LinkedList.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
    TEST_CLASS(LinkedListTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            LinkedList list;
            Assert::IsTrue(list.isEmpty());
            Assert::AreEqual((size_t)0, list.getSize());
        }

        TEST_METHOD(TestInitializerListConstructor)
        {
            LinkedList list = { 1, 2, 3, 4, 5 };
            Assert::AreEqual((size_t)5, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
            Assert::AreEqual(5, list[4]);
        }

        TEST_METHOD(TestCopyConstructor)
        {
            LinkedList original = { 10, 20, 30 };
            LinkedList copy(original);

            Assert::AreEqual((size_t)3, copy.getSize());
            Assert::AreEqual(10, copy[0]);
            Assert::AreEqual(20, copy[1]);
            Assert::AreEqual(30, copy[2]);
        }

        TEST_METHOD(TestMoveConstructor)
        {
            LinkedList original = { 100, 200 };
            LinkedList moved(std::move(original));

            Assert::AreEqual((size_t)2, moved.getSize());
            Assert::AreEqual(100, moved[0]);
            Assert::AreEqual(200, moved[1]);
            Assert::IsTrue(original.isEmpty());
        }

        TEST_METHOD(TestInsertAtBeginning)
        {
            LinkedList list;
            list.insert(100, 0);
            list.insert(200, 0);

            Assert::AreEqual((size_t)2, list.getSize());
            Assert::AreEqual(200, list[0]);
            Assert::AreEqual(100, list[1]);
        }

        TEST_METHOD(TestInsertAtEnd)
        {
            LinkedList list = { 1, 2 };
            list.insert(3, 2);

            Assert::AreEqual((size_t)3, list.getSize());
            Assert::AreEqual(3, list[2]);
        }

        TEST_METHOD(TestInsertInMiddle)
        {
            LinkedList list = { 1, 3 };
            list.insert(2, 1);

            Assert::AreEqual((size_t)3, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
            Assert::AreEqual(3, list[2]);
        }

        TEST_METHOD(TestInsertInvalidPositionThrows)
        {
            LinkedList list = { 1, 2 };
            auto func = [&] { list.insert(3, 3); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(TestRemoveFromBeginning)
        {
            LinkedList list = { 1, 2, 3 };
            list.remove(0);

            Assert::AreEqual((size_t)2, list.getSize());
            Assert::AreEqual(2, list[0]);
            Assert::AreEqual(3, list[1]);
        }

        TEST_METHOD(TestRemoveFromEnd)
        {
            LinkedList list = { 1, 2, 3 };
            list.remove(2);

            Assert::AreEqual((size_t)2, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
        }

        TEST_METHOD(TestRemoveFromMiddle)
        {
            LinkedList list = { 1, 2, 3 };
            list.remove(1);

            Assert::AreEqual((size_t)2, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(3, list[1]);
        }

        TEST_METHOD(TestRemoveInvalidPositionThrows)
        {
            LinkedList list = { 1 };
            auto func = [&] { list.remove(1); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(TestContains)
        {
            LinkedList list = { 10, 20, 30 };

            Assert::IsTrue(list.contains(10));
            Assert::IsTrue(list.contains(20));
            Assert::IsTrue(list.contains(30));
            Assert::IsFalse(list.contains(40));
        }

        TEST_METHOD(TestModifyExistingValue)
        {
            LinkedList list = { 1, 2, 3 };
            list.modify(2, 20);

            Assert::AreEqual(20, list[1]);
        }

        TEST_METHOD(TestModifyNonExistingValueThrows)
        {
            LinkedList list = { 1, 2 };
            auto func = [&] { list.modify(3, 30); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestLeftShiftOperator)
        {
            LinkedList list;
            list << 3 << 2 << 1;

            Assert::AreEqual((size_t)3, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
            Assert::AreEqual(3, list[2]);
        }

        TEST_METHOD(TestRightShiftOperator)
        {
            LinkedList list;
            list >> 1 >> 2 >> 3;

            Assert::AreEqual((size_t)3, list.getSize());
            Assert::AreEqual(1, list[0]);
            Assert::AreEqual(2, list[1]);
            Assert::AreEqual(3, list[2]);
        }

        TEST_METHOD(TestAssignmentOperator)
        {
            LinkedList original = { 5, 10, 15 };
            LinkedList copy;
            copy = original;

            Assert::AreEqual((size_t)3, copy.getSize());
            Assert::AreEqual(5, copy[0]);
            Assert::AreEqual(10, copy[1]);
            Assert::AreEqual(15, copy[2]);
        }

        TEST_METHOD(TestMoveAssignmentOperator)
        {
            LinkedList original = { 7, 14 };
            LinkedList moved;
            moved = std::move(original);

            Assert::AreEqual((size_t)2, moved.getSize());
            Assert::AreEqual(7, moved[0]);
            Assert::AreEqual(14, moved[1]);
            Assert::IsTrue(original.isEmpty());
        }

        TEST_METHOD(TestSubscriptOperator)
        {
            LinkedList list = { 100, 200, 300 };

            Assert::AreEqual(100, list[0]);
            Assert::AreEqual(200, list[1]);
            Assert::AreEqual(300, list[2]);

            list[1] = 250;
            Assert::AreEqual(250, list[1]);
        }

        TEST_METHOD(TestSubscriptOperatorOutOfRangeThrows)
        {
            LinkedList list = { 1 };
            auto func = [&] { return list[1]; };
            Assert::ExpectException<std::out_of_range>(func);
        }

        TEST_METHOD(TestToString)
        {
            LinkedList list = { 1, 2, 3 };
            std::string expected = "1 -> 2 -> 3";
            Assert::AreEqual(expected, list.toString());

            LinkedList empty;
            Assert::AreEqual(std::string(""), empty.toString());
        }
    };
}