
#include <iostream>
using namespace std;

int Binary(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return Binary(arr, l, mid - 1, x);
		return Bianry(arr, mid + 1, r, x);
	}
    else
	    return -1;
}

int main()
{
	int n;
    int arr[100];
    cout << "How many numbers ? ";
    cin >> n;
    cout << "Enter "<<n<<" Numbers : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
	int x;
    cout << "What number you want to search in array ? " ;
    cin >>x;
	int result = Binary(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not in array"
		: cout << "Element is at index " << result;
	return 0;
}
