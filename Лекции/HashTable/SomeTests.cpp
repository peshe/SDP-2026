#include <iostream>
#include <cassert>
#include <algorithm>

#include "separate_chaining.hpp"
#include "linear_probing_table.hpp"

class Student
{
    std::string fn;
    std::string name;
    float grade;
public:
    Student(std::string fn="", std::string name="")
        : fn(std::move(fn)), name(std::move(name)), grade(2.00)
    {}

    const std::string& FN() const { return fn; }
    bool operator==(const Student& s) const {
        return name == s.name && fn == s.fn;
    }

    const std::string& getName() const { return name; }
    void setName(std::string name) { this->name = std::move(name); }

    float getGrade() const { return grade; }
    void setGrade(float gr) { grade = std::clamp(gr, 2.00f, 6.00f); }
};

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << student.FN() << ' ' << student.getName() << ' ' << student.getGrade() << '\n';
    return os;
}

namespace std
{
    size_t hash(const Student& s)
    {
        size_t fn = 0;
        const std::string& FN = s.FN();
        assert("The length of the FN is not correct" && FN.size() == 10);

        for (int i = 3; i < 10; ++i)
            fn = fn * 10 + FN[i] - '0';
        return fn;
    }
}

using namespace fmi::sdp;
void testTableStudent(HashTable<Student>& table)
{
    Student
        s1("0MI0700123", "Pesho"),
        s2("1MI0400017", "Gosho"),
        s3("2MI0800111", "Marijka");

    assert(!table.contains(s1));
    assert(!table.contains(s2));
    assert(!table.contains(s3));

    table.insert(s1);
    table.insert(s2);
    table.insert(s3);

    assert(table.contains(s1));
    assert(table.contains(s2));
    assert(table.contains(s3));

    Student scopy = s1;
    scopy.setName("Ivancho");
    assert(!table.contains(scopy));
    table.insert(scopy);
    assert(table.contains(scopy));
    assert(table.contains(s1));

    std::cout << table.get(s1);
    std::cout << table.get(s2);
    std::cout << table.get(s3);
    std::cout << table.get(scopy);
    
    s1.setGrade(5);
    assert(table.contains(s1));
    
    table.insert(s1);
    std::cout << table.get(s1);

    assert(table.remove(s1));
    assert(!table.contains(s1));
    assert(table.contains(scopy));
    assert(!table.remove(s1));

    assert(table.remove(s2));
    assert(!table.contains(s2));
    table.insert(s2);
    assert(table.contains(s2));

    table.insert(s1);
    table.insert(s2);
    table.insert(s3);
    table.insert(scopy);

    Student s4 = s2;
    s4.setName("Ivanka");
    table.insert(s4);
    
    table.remove(s1);
    std::cout << table.get(scopy);

    table.remove(s2);
    std::cout << table.get(s4);
}

int main()
{
    SeparateChainingHash<Student> sc_table;
    testTableStudent(sc_table);

    LinearProbingHash<Student> lp_table(2);
    testTableStudent(lp_table);
    std::cout << "----------\n";
    lp_table.print();

    return 0;
}
