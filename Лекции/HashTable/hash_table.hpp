/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing base hash table interface
*
* (cc) Petar Armyanov, FMI, 2026
*******************************************************************/
#pragma once

#ifndef _HASH_TABLE_HEADER_INCLUDED__
#define _HASH_TABLE_HEADER_INCLUDED__

namespace fmi::sdp
{
    template<typename KeyType>
    class HashTable
    {
    public:
        virtual ~HashTable() = default;

        virtual size_t size() const = 0;
        bool empty() const { return size() == 0; }
        virtual double load() const = 0;

        virtual bool contains(const KeyType& what) const = 0;

        virtual KeyType& get(const KeyType& what) = 0;
        virtual const KeyType& get(const KeyType& what) const = 0;

        virtual void insert(const KeyType& what) = 0;
        virtual bool remove(const KeyType& what) = 0;
    };
}

#endif _HASH_TABLE_HEADER_INCLUDED__
