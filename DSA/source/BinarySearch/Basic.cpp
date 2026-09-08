#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;


// Binary search
int binarySearch(vector<int>& nums, int target) {

	auto iterativeApproach = [&]() {
		
		int n = nums.size();
		int index = -1, low = 0, high = n - 1;

		while (low <= high) {

			int mid = (low + high) / 2;

			if (nums[mid] == target) {
				return index = mid;
				break;
			}
			else if (nums[mid] > target) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}

		}

		return index;

	};

	auto recursiveApproach = [&]() {
	
		int n = nums.size();

		function<int(int, int)> search = [&](int low, int high) -> int {

			if (low > high) {
				return -1;
			}

			int mid = (low + high) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
				return search(low, mid - 1);
			}
			else {
				return search(mid + 1, high);
			}

			return -1;

		};

		return search(0, n - 1);

	};

	return iterativeApproach();

}


// Lower bound
int lowerBound(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0;
	int high = n - 1;
	int ans = n;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (nums[mid] >= target) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}


// Upper bound
int upperBound(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0, high = n - 1, ans = n;

	while (low <= high) {
		int middle = (high + low) / 2;
		if (nums[middle] <= target) {
			low = middle + 1;
		}
		else {
			ans = middle;
			high = middle - 1;
		}
	}

	return ans;

}


// Search insert
int searchInsert(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0, high = n - 1, ans = n;

	while (low <= high) {
		int middle = (high + low) / 2;
		if (nums[middle] >= target) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Find floor and ceil
vector<int> findFloorAndCeil(vector<int>& nums, int target) {

	vector<int> ans;
	int n = nums.size();
	int low = 0, high = n - 1, floorIndex = -1, ceilIndex = -1;

	while (high >= low) {
		int middle = (high + low) / 2;
		if (nums[middle] < target) {
			floorIndex = middle;
			low = middle + 1;
		} else if (nums[middle] > target) {
			ceilIndex = middle;
			high = middle - 1;
		}
		else {
			floorIndex = middle;
			ceilIndex = middle;
			break;
		}
	}

	ans.push_back(floorIndex == -1 ? -1 : nums[floorIndex]);
	ans.push_back(ceilIndex == -1 ? -1 : nums[ceilIndex]);

	return ans;

}


// Search first and last occurences of an element
vector<int> searchRange(vector<int>& nums, int target) {

	vector<int> ans;
	int n = nums.size();
	int startingIndex = -1, endingIndex = -1;

	function<void(int, int)> binarySearch = [&](int low, int high) {

		if (low > high) return;

		int middle = (low + high) / 2;
		if (nums[middle] > target) {
			binarySearch(low, middle - 1);
		}
		else if (nums[middle] < target) {
			binarySearch(middle + 1, high);
		}
		else {
			startingIndex = startingIndex == -1 ? middle : min(middle, startingIndex);
			endingIndex = endingIndex == -1 ? middle : max(middle, endingIndex);
			binarySearch(low, startingIndex - 1);
			binarySearch(endingIndex + 1, high);
		}

	};

	binarySearch(0, n - 1);

	ans.push_back(startingIndex);
	ans.push_back(endingIndex);

	return ans;

}


// Count occurences
int countOccurences(vector<int>& nums, int target) {

	int n = nums.size();
	int startingIndex = -1, endingIndex = -1, count = 0;

	function<void(int, int)> binarySearch = [&](int low, int high) {

		if (low > high) return;

		int middle = (low + high) / 2;
		if (nums[middle] > target) {
			binarySearch(low, middle - 1);
		}
		else if (nums[middle] < target) {
			binarySearch(middle + 1, high);
		}
		else {
			int oldS = startingIndex, oldE = endingIndex;
			startingIndex = startingIndex == -1 ? middle : min(middle, startingIndex);
			endingIndex = endingIndex == -1 ? middle : max(middle, endingIndex);

			if (oldS == -1) {
				count += 1;
			}
			else {
				count += oldS - startingIndex;
				count += endingIndex - oldE;
			}

			binarySearch(low, startingIndex - 1);
			binarySearch(endingIndex + 1, high);
		}

	};

	binarySearch(0, n - 1);

	return count;

}


// Search in rotated sorted array
int searchInRotatedSortedArray(vector<int>& nums, int target) {

	int n = nums.size();
	int ans = -1;

	function<void(int, int)> binarySearch = [&](int low, int high) {

		if (low > high) return;
		int middle = (low + high) / 2;
		if (nums[middle] == target) {
			ans = middle;
			return;
		}

		if (nums[low] <= nums[middle]) {
			if (target >= nums[low] && target < nums[middle]) {
				return binarySearch(low, middle - 1);
			}
			else {
				return binarySearch(middle + 1, high);
			}
		}
		else {
			if (target > nums[middle] && target <= nums[high]) {
				return binarySearch(middle + 1, high);
			}
			else {
				return binarySearch(low, middle - 1);
			}
		}

		};

	binarySearch(0, n - 1);

	return ans;

}


// Search in rotated sorted array II
bool searchInRotatedSortedArrayTwo(vector<int>& nums, int target) {

	int n = nums.size();
	int low = 0, high = n - 1;

	while (low <= high) {
		int middle = (low + high) / 2;
		if (nums[middle] == target) {
			return true;
		}
		else {

			while (nums[middle] == nums[low] && nums[middle] == nums[high]) {
				if (low < middle) {
					low++;
				}
				if (high > middle) {
					high--;
				}
				if (low == middle && middle == high) {
					return false;
				}
			}

			if (nums[low] <= nums[middle]) {
				if (target >= nums[low] && target < nums[middle]) {
					high = middle - 1;
				}
				else {
					low = middle + 1;
				}
			}
			else {
				if (target > nums[middle] && target <= nums[high]) {
					low = middle + 1;
				}
				else {
					high = middle - 1;
				}
			}

		}
	}

	return false;

}


// Find minimum in rotated sorted array
int findMinimumInRotatedSortedArray(vector<int>& nums) {
	int n = nums.size();
	int low = 0, high = n - 1;

	while (low < high) {
		int middle = (low + high) / 2;
		if (nums[middle] > nums[high]) {
			low = middle + 1;
		}
		else {
			high = middle;
		}
	}
	return nums[low];
}



// Find how many times the array is rotated
int findHowManyTimesTheArrayIsRotated(vector<int>& nums) {

	int n = nums.size();
	int low = 0, high = n - 1;

	while (low < high) {
		int middle = (low + high) / 2;
		if (nums[middle] > nums[high]) {
			low = middle + 1;
		}
		else {
			high = middle;
		}
	}
	return low;

}