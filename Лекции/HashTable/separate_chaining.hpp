/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing a hash table
* implementing separate chaining (external hashing) CRS.
*
* (cc) Petar Armyanov, FMI, 2026
*******************************************************************/
#pragma once

#ifndef _SEPARATE_CHAINING_HASH_HEADER_INCLUDED__
#define _SEPARATE_CHAINING_HASH_HEADER_INCLUDED__

#include <vector>
#include <deque>
#include <stdexcept>

#include "hash_table.hpp"

namespace fmi::sdp
{
    template <typename KeyType>
    class SeparateChainingHash : public HashTable<KeyType>
    {
    public:
        SeparateChainingHash(size_t initial_size = 32)
            : count(0)
            , table(initial_size ? initial_size : 1)
        {}

        virtual size_t size() const override
        {
            return count;
        }

        virtual double load() const override
        {
            return (double)count / table.size();
        }

        virtual bool contains(const KeyType& what) const override
        {
            return find(what, table[std::hash(what) % table.size()]) >= 0;
        }

        virtual void insert(const KeyType& what) override
        {
            size_t index = std::hash(what) % table.size();
            int pos = find(what, table[index]);
            if (pos < 0) {
                table[index].push_front(what);
                ++count;
            }
            else {
                table[index][pos] = what;
            }
        }

        virtual KeyType& get(const KeyType& what) override
        {
            size_t index = std::hash(what) % table.size();
            int pos = find(what, table[index]);
            if (pos >= 0) {
                return table[index][pos];
            }
            else {
                throw std::invalid_argument("No such key in the table");
            } 
        }

        virtual const KeyType& get(const KeyType& what) const override
        {
            return const_cast<SeparateChainingHash*>(this)->get(what);
        }

        virtual bool remove(const KeyType& what) override
        {
            size_t index = std::hash(what) % table.size();
            int pos = find(what, table[index]);
            if (pos >= 0) {
                table[index].erase(table[index].begin() + pos);
                --count;
                return true;
            }

            return false;
        }

        void resize(size_t newSize)
        {
            std::vector<std::deque<KeyType>> newTable(newSize);
            table.swap(newTable);
            count = 0;
            for (std::deque<KeyType>& bucket : newTable) {
                for (KeyType& value : bucket) {
                    insert(value);
                }
            }
        }

    private:
        static int find(const KeyType& what, const std::deque<KeyType>& bucket)
        {
            for (size_t i = 0; i < bucket.size(); ++i) {
                if (bucket[i] == what) return (int)i;
            }
            return -1;
        }

    private:
        size_t count;
        std::vector<std::deque<KeyType>> table;
    };
}

#endif _SEPARATE_CHAINING_HASH_HEADER_INCLUDED__
