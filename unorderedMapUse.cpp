#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<map>

using namespace std;

void IntroToUnorderedMap(){
    unordered_map<string,int> ourmap; // map of string key, int value
    pair<string,int> p("abc",1); // internally, map stores a pair, so insert pair
    pair<string,int> q("abc",4);
    ourmap.insert(p);
    ourmap.insert(q); // this does not add or change the value present at already existing key###
    ourmap["def"] = 2; // this is another way to insert, it will create the key and add val

    ourmap["abc"] = 3; // this can be used to update the value as well

    // to access keys:
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("def") << endl;
    
    cout << ourmap["ab"] << endl; // this creates a new key as "ab" key does not exist, value = 0
    //cout << ourmap.at("bc") << endl; // THIS GIVES ERROR THAT THE KEY DOES NOT EXIST
    
    if(ourmap.count("abc") > 0 ){ // count function can only return 1 or 0, used to check if key exists
        cout << "key exists" << endl;
    }

    cout << "Size of map = " << ourmap.size() << endl; // to give size

    ourmap.erase("abc"); // to delete a key
    cout << "Size of map = " << ourmap.size() << endl;

    unordered_map<string,int>::iterator it; // declaration of iterator
    it = ourmap.begin(); // to initialise the it to ourmap
    // usage of it:
    while(it != ourmap.end()){
        cout << "Key: " << it->first << " Value:" << it->second << endl;
        it++;
    }

    // find function returns it
    it = ourmap.find("def");
    ourmap.erase(it); // give it to erase function
    //ourmap.erase(it, it +3); erases from it to it+2, leaves it+3, but does not work on unorder map, as it+3 is invalid for unordered map
}

// find highest freq of an element in an array
int highestFrequency(int arr[], int n) {
    unordered_map<int,int> freq;
    int max = arr[0];
    for(int i = 0; i < n; ++i){
        freq[arr[i]] ++;
        
    }
    for(int i =0; i < n; ++i){
        if(freq[arr[i]] > freq[max]){
            max = arr[i];
        }
    }
    return max;
}
// remove duplicate elements from an array:

vector<int> removeDuplicate(int arr[], int size){
    vector<int> ans;
    unordered_map<int,bool> unique; // here val is dummy i.e not used
    for(int i = 0; i<size; ++i){
        if(unique.count(arr[i]) == 0){
            unique[arr[i]];
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

// print intersection of 2 arrays

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> intersection;
    for(int i = 0; i < n; ++i){
        intersection[arr1[i]]++;
    }
    for(int i = 0; i<m; ++i){
        if(intersection.count(arr2[i]) > 0 && intersection[arr2[i]]-- > 0){
            cout << arr2[i] << endl;
        }
    }
}

// returns the no of pairs whose sum is 0
int pairSum(int *arr, int n) {
	unordered_map<int,int> hash;
    for(int i = 0; i < n; ++i){
        hash[arr[i]]++;
    }
	int count = 0;
	for(int i = 0; i<n;++i ){
		if( arr[i] != 0 && hash.count(0-arr[i]) > 0){
			count+= hash[0-arr[i]];
			hash[arr[i]]--;
		}
		else if(arr[i] == 0){
			int freq = hash[0];
			count += (freq-1) * freq / 2;
			hash.erase(0);	
		}
	}
	return count;
}

// remove duplicate from string

string uniqueChar(string str) {
	string ans;
	unordered_map<char,int> freq;
	for(int i =0; i<str.length(); ++i){
		if( freq[str[i]]  == 0){
			ans += str[i];
			freq[str[i]]++;
		}
	}
	return ans;
}
// return longest consecutive num series in array, if same len, return the series wose start appears first in array
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    if (n==0) return vector<int>();
    vector<int> ans(2,0); // should be INT_MIN
    map<int,int> myset;
    for(int i = 0; i<n;++i){
        myset[*(arr+i)] = i;
    }
    auto it = myset.begin();
    int start,end,prev;
    start = end = prev = it->first;
    it++;
    while(it != myset.end()){
        if(it->first== prev+1){
            prev++;
        }
        else{
            end = prev;
            if(end-start > (ans[1]-ans[0])){
                ans[0] = start;
                ans[1] = end;
            }
            if(end-start == (ans[1]-ans[0]) && myset[start] < myset[ans[0]]){
                ans[0] = start;
                ans[1] = end;
            }
            prev = start = it->first;
        }
        it++;
    }
    if(end-start >= (ans[1]-ans[0])){ // edge case
                ans[0] = start;
                ans[1] = end;
    }
    return ans;
}

// return count of pairs whose diff = k
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> hash;
    for(int i = 0; i < n; ++i){
        hash[arr[i]]++;
    }
	int count = 0;
	for(int i = 0; i<n;++i ){
		if( hash.count(k+arr[i]) > 0){
			if(k!=0){
				count+= hash[k+arr[i]];
				hash[arr[i]]--;
			}
			else{
				int freq = hash[arr[i]];
				count+= (freq-1) * freq / 2;
				hash.erase(arr[i]);	
			}
		}
	}
	return count;
}

// Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,pair<int,int>> sum;
    int cSum = 0;
    int end, start;
    start = end = 0;
    pair<int,int> ans = make_pair(0,0);
    for(int i = 0; i<n;++i){
        cSum += arr[i];
        if(cSum == 0 && start == 0){ // edge case
            end = i;
            if(end-start > (ans.second-ans.first)){
                ans.second = end+1;
                ans.first = start;
            }
            continue;
        }
        sum[cSum].first++;
        if(sum[cSum].first == 1){
            sum[cSum].second = i;
        }
        if(sum[cSum].first>1){
            end = i;
            start = sum[cSum].second;
            if(end-start > (ans.second-ans.first)){
                ans.second = end;
                ans.first = start;
            }
        }
    }
    return ans.second - ans.first;
}

int main(){
    //IntroToUnorderedMap();
    /*int arr[] = {1,3,45,6,64,3,23,1,2,2,3,3,44};
    vector<int> ans = removeDuplicate(arr,13);
    for(int i = 0; i <ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;*/
    
    /*int arr1[]= {7,7,7};
    int arr2[] = {7,7,7,7};
    printIntersection(arr1,arr2,3,4);*/
    
    /*int arr[]= {3, 7, 2, 1, 9, 8, 41};
    vector<int> output = longestConsecutiveIncreasingSequence(arr,7);
    cout << output[0] << ' ' << output[1] << endl;*/
    return 0;
}
