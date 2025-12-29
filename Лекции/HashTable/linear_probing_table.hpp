/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing a hash table
* implementing linear probing (open addressing) CRS.
*
* (cc) Petar Armyanov, FMI, 2026
*******************************************************************/
#pragma once

#ifndef _LINEAR_PROBING_HASH_HEADER_INCLUDED__
#define _LINEAR_PROBING_HASH_HEADER_INCLUDED__

#include <vector>
#include <stdexcept>

#include "hash_table.hpp"

namespace fmi::sdp
{
    template <typename KeyType>
    class LinearProbingHash : public HashTable<KeyType>
    {
    public:
        LinearProbingHash(size_t initial_size = 32)
            : count(0)
            , table(initial_size ? initial_size : 1)
            , deleted(initial_size ? initial_size : 1, false)
            , free(initial_size ? initial_size : 1, true)
        {
        }

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
            int pos = findPosition(what);
            return pos >= 0;
        }

        virtual void insert(const KeyType& what) override
        {
            if (load() > MAX_LOAD_FACTOR) {
                resize(2 * size());
            }

            int pos = findPosition(what);
            if (pos >= 0) {
                table[pos] = what;
            }
            else {
                size_t index = std::hash(what) % table.size();
                for (size_t step = 0; step < table.size(); ++step) {
                    size_t position = (index + step) % table.size();
                    if (free[position]) {
                        table[position] = what;
                        free[position] = false;
                        deleted[position] = false;
                        ++count;
                        return;
                    }
                }
            }
        }

        virtual KeyType& get(const KeyType& what) override
        {
            int pos = findPosition(what);
            if (pos >= 0) {
                return table[pos];
            }
            else {
                throw std::invalid_argument("No such key in the table");
            }
        }

        virtual const KeyType& get(const KeyType& what) const override
        {
            return const_cast<LinearProbingHash*>(this)->get(what);
        }

        virtual bool remove(const KeyType& what) override
        {
            int pos = findPosition(what);
            if (pos >= 0) {
                free[pos] = true;
                deleted[pos] = true;
                --count;
                return true;
            }
            else {
                return false;
            }
        }

        void resize(size_t newSize)
        {
            assert(newSize > count);
            if (newSize <= count) return;

            std::vector<KeyType> newTable(newSize);
            std::vector<bool> newDeleted(newSize, false);
            std::vector<bool> newFree(newSize, true);

            table.swap(newTable);
            deleted.swap(newDeleted);
            free.swap(newFree);
            count = 0;

            for (size_t ind = 0; ind < newTable.size(); ++ind) {
                if (!newFree[ind] && !newDeleted[ind]) {
                    insert(newTable[ind]);
                }
            }
        }

#ifndef _NDEBUG
        void print()
        {
            for (size_t ind = 0; ind < table.size(); ++ind) {
                if (!free[ind] && !deleted[ind]) {
                    std::cout << table[ind];
                }
            }
        }
#endif // !_NDEBUG

    private:
        int findPosition(const KeyType& what) const
        {
            size_t index = std::hash(what) % table.size();
            for (size_t step = 0; step < table.size(); ++step) {
                size_t position = (index + step) % table.size();
                if (!free[position] && table[position] == what)
                    return (int)position;
                if (free[position] && !deleted[position])
                    return -1;
            }
            return -1;
        }

    private:
        size_t count;
        std::vector<KeyType> table;
        std::vector<bool> deleted;
        std::vector<bool> free;

        static double constexpr MAX_LOAD_FACTOR = 0.7;
    };
}

#endif _LINEAR_PROBING_HASH_HEADER_INCLUDED__
