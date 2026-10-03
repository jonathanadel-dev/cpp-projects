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


// Single non duplicate
int singleNonDuplicate(vector<int>& nums) {

	int n = nums.size();
	int low = 0, high = n - 1;

	while (low < high) {
		int middle = (low + high) / 2, lowCount = 0, highCount = 0;

		if (middle % 2 == 1)
			middle--;

		if (nums[middle] == nums[middle + 1]) {
			low = middle + 2;
		}
		else {
			high = middle;
		}
	}

	return nums[low];

}


// Find peak element
int findPeakElement(vector<int>& nums) {

	int n = nums.size();

	if (n == 1) return 0;
	if (nums[0] > nums[1]) return 0;
	if (nums[n - 1] > nums[n - 2]) return n - 1;

	int low = 1, high = n - 2;

	while (low <= high) {
		int middle = (high + low) / 2;
		if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]) {
			return middle;
		}
		else if (nums[middle] < nums[middle + 1]) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}

	return -1;

}


// Find the floor square root
int findFloorSquareRoot(int n) {

	int low = 1, high = n, ans = -1;

	while (low <= high) {

		int middle = (high + low) / 2;
		int product = middle * middle;

		if (product <= n) {
			ans = middle;
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}

	}

	return ans;

}


// Find the nth root of m
int findNthRoot(int n, int m){

	int low = 1, high = m;
	while (low <= high) {
		int middle = (high + low) / 2;
		long long product = 1;

		for (int i = 0; i < n; i++) {
			product *= middle;
			if (product > m) break;
		}

		if (product == m) {
			return middle;
		}
		else if (product < m) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}

	return -1;

}


// Minimum eating speed
int minEatingSpeed(vector<int>& piles, int h) {

	sort(piles.begin(), piles.end());

	int n = piles.size();
	int low = 1, high = piles[n - 1], ans = INT_MAX;

	while (low <= high) {
		int middle = (high + low) / 2;
		long long hours = 0;

		// Calculate total number of hours
		for (int i = 0; i < n; i++) {
			int hour = (middle + piles[i] - 1) / middle;
			hours += hour;
		}

		if (hours <= h) {
			ans = min(ans, middle);
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}

	}

	return ans;

}


// Minimum days to collect bouquets
int minDaysToCollectBouquets(vector<int>& bloomDay, int m, int k) {

	int n = bloomDay.size();
	int low = *min_element(bloomDay.begin(), bloomDay.end());
	int high = *max_element(bloomDay.begin(), bloomDay.end());
	int ans = -1;

	function<bool(int)> isCollected = [&](int days) {

		int bouquetsCollected = 0;
		int flowersCollected = 0;

		for (int i = 0; i < n; i++) {
			if (days >= bloomDay[i]) {
				flowersCollected++;
				if (flowersCollected == k) {
					bouquetsCollected++;
					flowersCollected = 0;
				}
			}
			else {
				flowersCollected = 0;
			}
		}

		return bouquetsCollected >= m;

		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isCollected(middle)) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Smallest divisor
int smallestDivisor(vector<int>& nums, int threshold) {

	int n = nums.size(), ans = INT_MAX;
	int low = 1, high = *max_element(nums.begin(), nums.end());

	auto isSmallerThanThreshold = [&](int x) {
		int result = 0;
		for (int i = 0; i < n; i++) {
			result += (nums[i] + x - 1) / x;
		}
		return result <= threshold;
		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isSmallerThanThreshold(middle)) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Ship within days
int shipWithinDays(vector<int>& weights, int days) {

	int n = weights.size(), ans = INT_MAX;
	int low = *max_element(weights.begin(), weights.end());
	int high = accumulate(weights.begin(), weights.end(), 0);

	auto isEnough = [&](int x) {
		int daysRequired = 1;
		int capacity = x;
		for (int i = 0; i < n; i++) {
			if (weights[i] > capacity) {
				capacity = x - weights[i];
				daysRequired++;
			}
			else {
				capacity -= weights[i];
			}
		}
		return daysRequired <= days;
		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isEnough(middle)) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Kth missing number
int findKthMissingNumber(vector<int>& arr, int k) {

	int n = arr.size();
	int low = 0, high = n - 1;

	while (low <= high) {
		int middle = (high + low) / 2;
		int missings = arr[middle] - 1 - middle;
		if (missings < k) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}

	return low + k;

}



// Aggressive cows
int aggressiveCows(vector<int>& nums, int k) {

	sort(nums.begin(), nums.end());

	int n = nums.size();
	int low = 1, ans = -1;
	int high = nums[n - 1] - nums[0],

		auto isFit = [&](int x) {

		int cows = k - 1, lastCowIndex = 0;

		for (int i = 1; i < n; i++) {
			if (nums[i] - nums[lastCowIndex] >= x) {
				cows--;
				lastCowIndex = i;
			}
			if (cows == 0) break;
		}

		return cows == 0;

		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isFit(middle)) {
			ans = middle;
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}

	return ans;

}


// Minimized max sum in subarrays
int minimizedMaxSumInSubarrays(vector<int>& nums, int k) {

	int n = nums.size(), ans = INT_MAX;
	int low = nums[0];
	int high = accumulate(nums.begin(), nums.end(), 0);

	auto isLargestMinimized = [&](int x) {
		int subarraysLeft = k;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + nums[i] <= x) {
				sum += nums[i];
			}
			else {
				subarraysLeft--;
				if (subarraysLeft == 0 || nums[i] > x) {
					return false;
				}
				sum = nums[i];
			}
		}
		return true;
		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isLargestMinimized(middle)) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

}


// Book allocation
int bookAllocation(vector<int>& nums, int m) {

	int n = nums.size();
	int low = -1, high = 0, ans = -1;

	if (m > n) return -1;

	for (auto book : nums) {
		low = max(low, book);
		high += book;
	}

	auto isMaximum = [&](int x) {
		int students = m;
		int pages = 0;
		for (auto bookPages : nums) {
			if (pages + bookPages <= x) {
				pages += bookPages;
			}
			else {
				students--;
				if (students == 0) return false;
				pages = bookPages;
			}
		}
		return true;
		};

	while (low <= high) {
		int middle = (high + low) / 2;
		if (isMaximum(middle)) {
			ans = middle;
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}

	return ans;

};



// Minimize maximum distance
double minimiseMaxDistance(vector<int>& arr, int k) {

	int n = arr.size();

	double low = 0.0;
	double high = 0.0;


	for (int i = 1; i < n; i++) {
		high = max(high, (double)(arr[i] - arr[i - 1]));
	}


	auto canPlace = [&](double maxDist) {

		int stations = 0;

		for (int i = 1; i < n; i++) {
			double gap = arr[i] - arr[i - 1];

			stations += (int)ceil(gap / maxDist) - 1;

			if (stations > k)
				return false;
		}

		return true;
	};


	while (high - low > 1e-6) {

		double mid = low + (high - low) / 2.0;

		if (canPlace(mid)) {
			high = mid;
		}
		else {
			low = mid;
		}
	}

	return high;
}