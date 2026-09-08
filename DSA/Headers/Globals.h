#pragma once
#include <string>
#include <vector>
#include <set>
using namespace std;


// Loops
void print7(int n);
void print8(int n);
void print9(int n);
void print10(int n);
void print11(int n);
void print12(int n);
void print13(int n);
void print14(int n);
void print17(int n);


// STL
void pairs();
void vectors();
void lists();
void deques();
void stacks();
void queues();
void pqs();
void sets();
void multisets();
void unorderedSets();
void maps();
void multimaps();
void unorderedmaps();


// Sorting algorithms
void sortingFunction();


// Basic Maths
int numberOfDigits(int n);
int numberOfDigits2(int n);
bool isArmstrong(int n);
void printDivisors(int n);
void printDivisors2(int n);
bool isPrime(int n);
bool isPrime2(int n);
int gcd(int n1, int n2);


// Recursion
void print(int i, int n);
void printAsc(int i, int n);
void printDesc(int n);
void printAsc2(int n);
void printDesc2(int i, int n);
int recursionSum(int n, int sum);
int recursionSum2(int n);
int recursionFactorial(int n);
void recursionArrayReverse(int arr[], int i, int size);
void recursionArrayReverse2(int arr[], int i, int size);
bool recursionCheckIfPalindrome(int i, const string& s);
int recursionFib(int n);


// Hashing
void hashingArray(int a[], int size);
void hashingCharacters(string s);
void hashingMap(int a[], int size);
void hashingCharacterMap(string s);


// Sorting
void selectionSort(int a[], int size);
void bubbleSort(int a[], int size);
void bubbleSort2(int a[], int size);
void insertionSort(int a[], int size);
void mergeSort(int a[], int left, int right);
void quickSort(int a[], int left, int right);


// Basic Arrays problems
int greatestElementInTheArray(int a[], int size);
vector<int> secondGreatestElementInTheArray(int a[], int size);
void removeDuplicates(int a[], int size);
void leftRotateAnArrayByOne(int a[], int size);
void leftRotateAnArrayByK(int a[], int size, int k);
void movingZerosToTheEnd(int a[], int size);
void unionOfTwoArrays(int a[], int size, int a1[], int a2[], int size1, int size2);
vector<int> intersectionOfTwoArrays(vector<int> v1, vector<int> v2);
int findMissingNumberInAnArray(vector<int>);
int findTheLongestConsecutiveOnes(vector<int> v);
int longestSubArrayWithLengthK(vector<int> v, int k);


// Medium array problems
vector <int> twoSum(vector <int> v, int target);
void sortArrayOfZerosOnesAndTwos(vector <int> v);
int majorityElement(vector <int> nums);
int maximumSubarray(vector<int> nums);
vector<int> rearrangeArrayElementsBySign(vector<int> nums);
void nextPermutation(vector <int> v);
vector <int> leadersInAnArray(vector <int> nums);
int longestConsecutiveSequence(vector<int> nums);
void setMatrixZeros(vector<vector <int>> matrix);
vector<vector <int>> rotateMatrixBruteSolution(vector<vector<int>> matrix);
void rotateMatrixOptimalSolution(vector<vector<int>> &matrix);
vector<int> spiralMatrix(vector<vector<int>> matrix);
int numberOfSubarraysWithSumK(vector<int> nums, int k);


// Hard array problems
vector<vector<int>> pascalsTriangle(int n);
vector<int> majorityElementTwo(vector<int> nums);
vector<vector<int>> threeSum(vector<int> nums);
vector<vector<int>> fourSum(vector<int> nums, int target);
int longestSubarrayWithSumK(vector<int> nums, int k);
int countSubarraysWithGivenXORK(vector<int> nums, int k);
vector<vector<int>> mergeIntervals(vector<vector<int>> nums);
void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n);
vector<int> findRepeatingAndMissingNumbers(vector<int> nums);
int countInversions(vector<int> nums);
int reversePairs(vector<int> nums);
int maximumProduct(vector<int> nums);


// Binary search
int binarySearch(vector<int>& nums, int target);
int lowerBound(vector<int>& nums, int target);
int upperBound(vector<int>& nums, int target);
int searchInsert(vector<int>& nums, int target);
vector<int> findFloorAndCeil(vector<int>& nums, int target);
vector<int> searchRange(vector<int>& nums, int target);
int countOccurences(vector<int>& nums, int target);
int searchInRotatedSortedArray(vector<int>& nums, int target);
bool searchInRotatedSortedArrayTwo(vector<int>& nums, int target);
int findMinimumInRotatedSortedArray(vector<int>& nums);
int findHowManyTimesTheArrayIsRotated(vector<int>& nums);