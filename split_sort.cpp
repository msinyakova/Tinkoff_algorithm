#include <iostream>
#include <vector>

void print_arr(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i ++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}


void split_sort(std::vector<int>& buf, int left, int right)
{
	if (left >= right)
		return;
	int middle = left + (right - left) / 2;
	split_sort(buf, left, middle);
	split_sort(buf, middle + 1, right);

	std::vector<int> tmp(&buf[left], &buf[right] + 1);
	int j = 0;					// start left buf
	int k = middle - left + 1;	// start right buf
    for (int i = left; i <= right; ++i) {
        if (j > middle - left) {    	// left buf finish  
            buf[i] = tmp[k];
            k++;
        } else if (k > right - left) {	// right buf finish
            buf[i] = tmp[j];
            j++;
        } else if (tmp[j] < tmp[k]){	// get elem from left buf
            buf[i] = tmp[j];
            j++;
        } else {						// get elem from right buf
        	buf[i] = tmp[k];
        	k++;
        }
    }
}


int main()
{
	int n;
	std::cin >> n;
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	split_sort(arr, 0, arr.size() - 1);
	print_arr(arr);
	return 0;
}