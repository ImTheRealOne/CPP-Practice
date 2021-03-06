// 16 25 lastRecentUsedCache.cpp : Defines the entry point for the console application.
/*

LRU Cache: Design and build a "least recently used" cache, which evicts the least recently used
item. The cache should map from keys to values (allowing you to insert and retrieve a value associated
with a particular key) and be initialized with a max size. When it is full, it should evict the least
recently used item.


*/


//

#include "stdafx.h"
#include <iostream>
#include "Cache.h"

int main()
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int num4 = 4;
	int num5 = 5;
	int num6 = 6;
	int num7 = 7;
	

	Cache cache(5);

	cache.add(num1, &num1);
	cache.add(num2, &num2);
	cache.add(num3, &num3);
	cache.add(num4, &num4);
	
	cache.getValue(num1);
	cache.printCacheMap();
	cache.printList();
	cache.add(num5, &num5);

	cache.add(num6, &num6);

	cache.add(num7, &num7);
	cache.add(num1, &num1);



    return 0;
}

