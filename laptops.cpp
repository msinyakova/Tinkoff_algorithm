#include <iostream>
#include <vector>

void split_sort(std::vector<int>& a, std::vector<int>&b, int left, int right)
{
	if (left >= right)
		return;
	int middle = left + (right - left) / 2;
	split_sort(a, b, left, middle);
	split_sort(a, b, middle + 1, right);

	std::vector<int> tmp(&a[left], &a[right] + 1);
	std::vector<int> help(&b[left], &b[right] + 1);
	int j = 0;					// start left buf
	int k = middle - left + 1;	// start right buf
    for (int i = left; i <= right; ++i) {
        if (j > middle - left) {    	// left buf finish  
            a[i] = tmp[k];
            b[i] = help[k];
            k++;
        } else if (k > right - left) {	// right buf finish
            a[i] = tmp[j];
            b[i] = help[j];
            j++;
        } else if (tmp[j] < tmp[k]){	// get elem from left buf
            a[i] = tmp[j];
            b[i] = help[j];
            j++;
        } else {						// get elem from right buf
        	a[i] = tmp[k];
        	b[i] = help[k];
        	k++;
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> price(n);
	std::vector<int> quality(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &price[i], &quality[i]);
	}

	split_sort(price, quality, 0, price.size() - 1);

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (quality[i] < max) {
			printf("Happy Alex\n");
			return 0;
		}				
		max = quality[i];
	}
	printf("Poor Alex\n");

	return 0;
}