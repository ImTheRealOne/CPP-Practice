#include "Main.h"
#include "Header.h"
Main::Main()
{
}


Main::~Main()
{
}



int main() {

	sortAbstract *alg;

	bubbleSort bubble;
	std::vector<int> a{ 4,2,3,6,1 };
	alg = &bubble;
	alg->sort(a);

	insertionSort insert;
	alg = &insert;
	alg->sort(a);



	QuickSort quikSort;
	alg = &quikSort;
	std::vector<int> * vectorPtr = &a;
	quikSort.setVector(vectorPtr);
	alg->sort(a);
	alg->print(a);

	BinSort bSort;
	alg = &bSort;
	a.push_back(55);
	a.push_back(23);
	a.push_back(44);
	a.push_back(52);
	a.push_back(51);
	a.push_back(79);
	bSort.sort(a);


	std::cout << "Merge Sort " << std::endl;
	MergeSort mergeSort;
	alg = &mergeSort;
	mergeSort.setVector(vectorPtr);
	alg->sort(a);
	alg->print(a);


	

	system("pause");
	return 0;
}

