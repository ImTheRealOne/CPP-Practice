#include "MergeSort.h"



MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::sort(std::vector<int> a) {

	sort(*this->vectorPtr, 0, a.size() - 1);
}

void MergeSort::sort(std::vector<int>& a, int p, int r) {
	if (a.size() <= 1)
		return;
	if (p < r) {
		int m = (p + r) / 2;
		sort(a, p, m);
		sort(a, m+1, r);

		merge(a, p, m, r);

	}

}

void MergeSort::merge(std::vector<int>& a, int p, int q, int r) {
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	
	std::vector<int> tempLeft;
	std::vector<int> tempRight;

	for (i = 0; i < n1; i++)
		tempLeft.push_back(a[p + i]);
	for (j = 0; j < n2; j++)
		tempRight.push_back(a[q + 1 + j]);

	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2) {
		if (tempLeft[i] <= tempRight[j]) {
			a[k] = tempLeft[i];
			i++;
		}
		else
		{
			a[k] = tempRight[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = tempLeft[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = tempRight[j];
		j++;
		k++;
	}



}

void MergeSort::setVector(std::vector<int> * a) {
	this->vectorPtr = a;
}