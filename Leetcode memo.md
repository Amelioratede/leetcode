# Leetcode memo

**swap(str[i], str[n - i - 1])** c++内置函数

## 2.16

**(24)**Swap two close by nodes in single linked list.

1->2->3->4 to 2->1->4->3

Using double point==> pointer of pointer.d

***

## 2.21

**(171)**Using pointer 

```c++
return (pos = 
    pos == -1 ? 0 : pos, pos) 
   	== s.size() ? 
    res : 
	titleToNumber(s, res * 26 + s[pos] - '@', pos + 1);
```

## **3.8**

**(141)if linked-list has cycle**

```c++
//fast and slow pointer approach

bool hasCycle(ListNode *head) {
   ListNode* slow=head;
   ListNode* fast=head;
    while(fast && slow && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}

//hashmap approach
bool hasCycle(ListNode *head) {
    if(head==NULL)
        return false;
    unordered_map<ListNode*,int> map;
    while(head!=NULL){
        if(map.count(head)>0)
            return true;
        else
            map[head]=1;
        head=head->next;
    }
    return false;
}
```

# 3.22 Dynamic programming 

### house robbery

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};
//O(n) O(n)
```

```C++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prev_ans2=nums[0], prev_ans=max(nums[0],nums[1]),curr_ans=prev_ans;
        
        for(int i = 2; i < n; i++){
            curr_ans = max(prev_ans, prev_ans2 + nums[i]);
            prev_ans2 = prev_ans;
            prev_ans = curr_ans;
        }
        return curr_ans;
    }
};   
//O(n) O(1)
```

### robbery two (rob first and no last)

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
		// dp1 -> 1 to n-1
		// dp2 -> 2 to n
		
        int dp1[n], dp2[n];
		
		// if we have robbed the first house, then we can't rob the second house
        dp1[0] = nums[0];
        dp1[1] = nums[0];
		
		// if we didn't rob the first house, we will definetely rob the second
        dp2[0] = 0;
        dp2[1] = nums[1];
        
        for(int i = 2; i < n; i++) {
		
			// make optimal choice at each house
            dp1[i] = max(nums[i] + dp1[i-2], dp1[i-1]);
            dp2[i] = max(nums[i] + dp2[i-2], dp2[i-1]);
        }
        
		// dp1 is for nums[1 - (n-1)] so we won't consider the last house in this case and dp1[n-2] will be max profit
		// and dp2 is for nums[2 - n] so we can take the last house
        return max(dp1[n-2], dp2[n-1]);
    }
};
```

# 3.23 merge k sorted Lists


​        
```c++
class Solution {
public:
    ListNode *mergeTwo(ListNode *a, ListNode *b)
    {
        if (a == nullptr) return b;
        if (b == nullptr) return a;    
	if (a->val < b->val)
    {
        a->next = mergeTwo(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeTwo(a, b->next);
        return b;
    }
}

ListNode *mergeK(vector<ListNode *> &lists, int i, int j)
{
    if (i == j) return lists[i];
    int mid = i + (j - i) / 2;
    
    ListNode *left = mergeK(lists, i, mid);
    ListNode *right = mergeK(lists, mid + 1, j);
    
    return mergeTwo(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    return mergeK(lists, 0, lists.size() - 1);
}
};
//solving k list using merge two list solutions!
//Divide and conquer method!!!!!!!!!!!!!!!!!
//brute force will do from 1,2 then with 3 with 4 .....will not divide into mergeK
```
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        
        ListNode* result = new ListNode(-1);
        ListNode* head = result;
        
        int min_val = 100000;
        int len = lists.size();
        if(len==1)
            return lists.back();
        
        ListNode* L[len];
        
        //setup for further usage
        bool end_loop=true;
        priority_queue <int, vector<int>, greater<int> > pq;
        int i=0;
        int tmp;
        for (std::vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it,++i){
            L[i] = *it;
            if(L[i]){
                tmp = L[i]->val;
                pq.push(tmp);
            }
        }


        int min_pos;
        while(1){
            for(int i=0; i<len ; i++){
                if(L[i]){
                    end_loop = false;
                    break;
                }  
            }
            if(end_loop)
                break; 
            
            //using min heap to store values and using map to get the corresponding ListNode
            for(int i=0; i<len ; i++){
                if(L[i]&&L[i]->val==pq.top()){
                    min_pos=i;
                    break;
                }  
            }
            // cout<<min_pos <<" ";
            pq.pop();
            result->next = L[min_pos];
            L[min_pos] = L[min_pos]->next;
            result = result->next;
            //check if we need to end the loop
            
            if(L[min_pos]){
                pq.push(L[min_pos]->val);
            }
            end_loop = true;
            
        }
        result->next = NULL;

        return head->next;
        
    }
};
////////////////My own solution ==> total n list m numeber ==> worst case=m*(3n+3n)
//////priority queue
```

# 3.23 Delete and earn Question ==> rob not near problem

```c++
class Solution {
public:
int deleteAndEarn(vector<int>& nums) {
		vector<int> freq(100001, 0);
		vector<int> dp(100001, 0);

		for (auto i : nums) freq[i]++;
		dp[1] = freq[1];

		for (int i=2; i<100001; i++)
				dp[i] = max(dp[i-2]+i*freq[i], dp[i-1]);

		return dp[100000];
}
};
//optimized
class Solution {
public:
 int deleteAndEarn(vector<int>& nums) {
    int n = 10001;
    
    if (nums.size() == 1) return nums[0];

    vector<int> map(n, 0);
    
    for (auto &num: nums) {
        map[num] += num;
    }
    
    int one = map[0];
    int two = max(one, map[1]);
    
    for (int i = 2; i < n; i++) {
        int cur = max(two, one + map[i]);
        one = two;
        two = cur;
        
    }
    
    return max(one, two);
    
}
};
```

![image-20220323175414695](../../documents/snipaste temporary images/image-20220323175414695.png)

# 3.23 Jump question

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
        if(n<=1) return 0;
        vector<int> dp(n, INT_MAX-1);
        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=1; (j<=nums[i] && i+j<n); j++){
                dp[i+j] =  min(dp[i+j],dp[i]+1);
           }
        }
        return dp[n-1];
        }
};
```

![image-20220323191909410](../../documents/snipaste temporary images/image-20220323191909410.png)

# 3.24 881







# 3.31 std::sort

**![image-20220331212240607](../../documents/snipaste temporary images/image-20220331212240607.png)**

# 4.8 leetcode78&80 subsets

![image-20220408232208083](../../documents/snipaste temporary images/image-20220408232208083.png)

Traceback algor. 

![image-20220408232431439](../../documents/snipaste temporary images/image-20220408232431439.png)

Same but using dfs method.

***

# 4.9 Using hashmap and other STL in c++(sorting hashmap value get key)(347.Top K Frequent Elements )

![image-20220409155833437](../../documents/snipaste temporary images/image-20220409155833437.png)

Use multi map 可以让原本无序的map根据value值进行排序，插入进去的时候multimap会自动排序，和priority_queue一样应该都是O(nlogn)

![image-20220409155925173](../../documents/snipaste temporary images/image-20220409155925173.png)

O(n)的方式使用将数字出现的频率作为index的形式存储在bucket vector中

![image-20220409160037268](../../documents/snipaste temporary images/image-20220409160037268.png)
![image-20220409160125793](../../documents/snipaste temporary images/image-20220409160125793.png)

# 4.11 multimap/map/priority_queue

multimap 底层是红黑树, key可以是重复的
map 也会自动实现键值排序，但是key不可以是重复的
![image-20220411140857984](../../documents/snipaste temporary images/image-20220411140857984.png)
![image-20220411140918086](../../documents/snipaste temporary images/image-20220411140918086.png)
![image-20220411140945805](../../documents/snipaste temporary images/image-20220411140945805.png)

# 4.11 二维vector数组初始化

vector<vector<int>> newOne(行数, vector<int>(列数, 0));

![image-20220411223536491](../../documents/snipaste temporary images/image-20220411223536491.png)

Leetcode 289 解决in-place 问题就是用2，3代表新的可能改变的情况。

# 4.15 DP问题找最大连续子串总和

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int tmp_max = nums[0];
        
        for(int i=1;i<n;i++){
            nums[i] = max(nums[i]+nums[i-1],nums[i]);
            if(nums[i]>tmp_max)
                tmp_max = nums[i];
        }
        
        return tmp_max;
    }
};
```

O(n) O(n)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          

# 4.21 使用vector实现hashmap

```c++
class MyHashMap {
	vector<vector<pair<int, int>>> map;
	const int size = 10000;
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		map.resize(size);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
        for(auto iter = row.begin(); iter != row.end(); iter++)
        {
            if(iter->first == key)
            {
                iter->second = value;
                return;
            }
        }
		row.push_back(make_pair(key, value));
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				return iter->second;
			}
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int index = key % size;
        vector<pair<int, int>> &row = map[index];
		for (auto iter = row.begin(); iter != row.end(); iter++)
		{
			if (iter->first == key)
			{
				row.erase(iter);
                return;
			}
		}
	}
};
```

# 5.6 Fibonacci Heap

![image-20220506195627423](../../documents/snipaste temporary images/image-20220506195627423.png)
![image-20220506195639213](../../documents/snipaste temporary images/image-20220506195639213.png)



# 5.24

In general you can't clear copying containers in O(1) because you need to destroy the copies. It's conceivable that a templated copying container could have a partial specialization that cleared in O(1) time that was triggered by a trait indicating the type of contained objects had a trivial destructor.

If you want to avoid loop.

```cpp
pages=stack<std::string>();
```

or

```cpp
stack<std::string>().swap(pages);
```



# 5.26 Minimum Size Subarray Sum

#### Approach #1 Brute force [Time Limit Exceeded]

**Intuition**

Do as directed in question. Find the sum for all the possible subarrays and update the \text{ans}ans as and when we get a better subarray that fulfill the requirements (\text{sum} \geq \text{s}sum≥s).

**Algorithm**

- Initialize \text{ans} = \text{INT\_MAX}ans=INT_MAX
- Iterate the array from left to right using *i*:
  - Iterate from the current element to the end of vector using*j*:
    - Find the \text{sum}sum of elements from index *i* to *j*
    - If sum is greater then s:
      - Update \text{ans} = \min(\text{ans}, (j - i + 1))ans=min(ans,(*j*−*i*+1))
      - Start the next i*i*th iteration, since, we got the smallest subarray with \text{sum} \geq ssum≥*s* starting from the current index.

```cpp
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
```

**Complexity Analysis**

- Time complexity: O(n^3)*O*(*n*3).
  - For each element of array, we find all the subarrays starting from that index which is O(n^2)*O*(*n*2).
  - Time complexity to find the sum of each subarray is O(n)*O*(*n*).
  - Thus, the total time complexity : O(n^2 * n) = O(n^3)*O*(*n*2∗*n*)=*O*(*n*3)
- Space complexity: O(1)*O*(1) extra space.

#### Approach #2 A better brute force [Accepted]

**Intuition**

In Approach #1, you may notice that the sum is calculated for every surarray in O(n)*O*(*n*) time. But, we could easily find the sum in O(1) time by storing the cumulative sum from the beginning(Memoization). After we have stored the cumulative sum in \text{sums}sums, we could easily find the sum of any subarray from *i* to *j*.

**Algorithm**

- The algorithm is similar to Approach #1.
- The only difference is in the way of finding the sum of subarrays:
  - Create a vector sums of size of nums
  - Initialize sums[0]=nums[0]
  - Iterate over the sums vector:
    - Update sums[i] = sums[i-1] + nums[i]
  - Sum of subarray from i*i* to j*j* is calculated as: sum=sums[*j*]−sums[*i*]+nums[*i*], , whereinsums[*j*]−sums[*i*] is the sum from (*i*+1)th element to the *j*th element.

```cpp
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    vector<int> sums(n);
    sums[0] = nums[0];
    for (int i = 1; i < n; i++)
        sums[i] = sums[i - 1] + nums[i];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = sums[j] - sums[i] + nums[i];
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
```

**Complexity analysis**

- Time complexity: O(n^2).
  - Time complexity to find all the subarrays is O(n^2).
  - Sum of the subarrays is calculated in O(1) time.
  - Thus, the total time complexity: O(n^2 * 1) = O(n^2)*O*(*n*2∗1)=*O*(*n*2)
- Space complexity: O(n)extra space.
  - Additional O(n) space for sums vector than in Approach #1.

#### Approach #3 Using Binary search [Accepted]

**Intuition**

We could further improve the Approach #2 using the binary search. Notice that we find the subarray with sum>=s starting with an index *i* in *O*(*n*) time. But, we could reduce the time to *O*(log(*n*)) using binary search. Note that in Approach #2, we search for subarray starting with index *i*, until we find sum=sums[*j*]−sums[*i*]+nums[*i*] that is greater than s. So, instead of iterating linearly to find the sum, we could use binary search to find the index that is not lower than s−sums[i] in the sums, which can be done using **lower_bound function in C++ STL** or could be implemented manually.

**Algorithm**

- Create vector sums of size n+1*n*+1 with : sums[0]=0, sums[*i*]=sums[*i*−1]+nums[*i*−1]
- Iterate from *i*=1 to *n*:
  - Find the value to_find in sum required for minimum subarray starting from index *i* to have sum greater than *s*, that is: to_find=s+sums[*i*−1]
  - Find the index in sums such that value at that index is not lower than the to_find value, say bound
  - If we find the to_find in sums, then:
    - Size of current subarray is given by: bound−(sums.begin()+*i*−1)
    - Compare ans with the current subarray size and store minimum in ans

```cpp
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int ans = INT_MAX;
    vector<int> sums(n + 1, 0); //size = n+1 for easier calculations
    //sums[0]=0 : Meaning that it is the sum of first 0 elements
    //sums[1]=A[0] : Sum of first 1 elements
    //ans so on...
    for (int i = 1; i <= n; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = 1; i <= n; i++) {
        int to_find = s + sums[i - 1];
        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        if (bound != sums.end()) {
            ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
```

**Complexity analysis**

- Time complexity:*O*(*n*log(*n*))
  - For each element in the vector, find the subarray starting from that index, and having sum greater than s*s* using binary search. Hence, the time required is O*(*n*) for iteration over the vector and O*(log(*n*)) for finding the subarray for each index using binary search.
  - Therefore, total time complexity = *O*(*n*∗log(*n*))
- Space complexity: *O*(*n*). Additional *O*(*n*) space for sums vector

#### Approach #4 Using 2 pointers [Accepted]

**Intuition**

Until now, we have kept the starting index of subarray fixed, and found the last position. Instead, we could move the starting index of the current subarray as soon as we know that no better could be done with this index as the starting index. We could keep 2 pointer,one for the start and another for the end of the current subarray, and make optimal moves so as to keep the sum greater than s*s* as well as maintain the lowest size possible.

**Algorithm**

- Initialize left pointer to 0 and sum to 0
- Iterate over the nums:
  - Add \text{nums}[i]nums[*i*] to \text{sum}sum
  - While sum is greater than or equal to *s*:
    - Update \text{ans}=ans=min(ans,*i*+1−left), where *i*+1−left is the size of current subarray
    - It means that the first index can safely be incremented, since, the minimum subarray starting with this index with sum≥*s* has been achieved
    - Subtract nums[left] fromsum and increment left

```cpp
int minSubArrayLen(int s, vector<int>& nums)
{
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}
```

**Complexity analysis**

- Time complexity: *O*(*n*). Single iteration of *O*(*n*).
  - Each element can be visited atmost twice, once by the right pointer(*i*) and (atmost)once by the left pointer.
- Space complexity: O*(1) extra space. Only constant space required for left, sum, ans and *i*.

# 5.28 count binary number

**Time Complexity : O(1)
Space Complexity : O(1)**



```cpp
class Solution {
	public:
	int hammingWeight(uint32_t n) { // function to count the number of 1s in a 32-bit integer
        return __builtin_popcount(n); // built-in function to count the number of 1s in a 32-bit integer
	}
};
```



**Time Complexity : O(1)
Space Complexity : O(1)**



```cpp
class Solution {
	public:
	int hammingWeight(uint32_t n) { // function to count the number of 1s in a 32-bit integer
        // bitset<32>() is a class that can be used to convert an integer to a bitset of 32 bits 
        // bitset<32>().count() is a function that counts the number of 1s in a bitset 
        return bitset<32>(n).count(); 
	}
};
```

# 5.31 set and unordered_set

**Differences :**

```md
                |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
```

```cpp
// class Solution {
// public:
//     bool hasAllCodes(string s, int k) {
//         unordered_set<string> s_set = {};
//         if(s.size()<=k) return false;
        
//         for(int i=0;i<s.size()-k+1;i++){
//             string tmp(s,i,k);
//             s_set.insert(tmp);
//         }
        
//         return s_set.size()==(1<<k) ?  true:false;
//     }
// };

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) {
            return 0;
        }
        
        int cur = 0;
        for (int i = 0; i < k - 1; ++i) {
            cur = 2 * cur + (s[i] == '1');
        }
        
        vector<bool> cache(1 << k, false);
        for (int i = k - 1; i < s.size(); ++i) {
            cur = 2 * cur + (s[i] == '1');
            cache[cur] = true;
            cur &= ~(1 << (k - 1));
        }
        for (bool val : cache) {
            if (!val) {
                return false;
            }
        }
        return true;
    }
};
```

# 6.1 merge K-list or using priority queue

```cpp
**//if u like this approach u can upvote **
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int l=lists.size();
        if(l==0)return NULL;
        return help(lists,0,l-1);
    }
	
	//merge two list
    ListNode* merge(ListNode* list1, ListNode* list2) {
         ListNode*res;
        if(list1==NULL)return list2;
         if(list2==NULL)return list1;
        if(list1->val<=list2->val){
            res=list1;
            res->next=merge(list1->next,list2);
        }
        else{
            res=list2;
            res->next=merge(list1,list2->next);
        }
        return res;
    }
	
//Take every list as element and apply merge-sort
    ListNode* help(vector<ListNode*>& lists ,int s, int e){
        if(s==e)return lists[s];
        int m=(s+e)/2;
        ListNode* h1=help(lists,s,m);
        ListNode* h2=help(lists,m+1,e);
        return merge(h1,h2);
    }
};
```

# 6.1 Sliding window to check permutation of s1 in s2

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
      	vector<int> freq1(26);
       	vector<int> freq2(26);
        int window = s1.size();
        int l = 0;
        for(int i = 0; i < s1.size(); i++){
            freq1[s1[i] - 'a'] = freq1[s1[i] - 'a'] + 1; 
        }
        for(int r = 0; r < s2.size(); r++){
            freq2[s2[r] - 'a'] = freq2[s2[r] - 'a'] + 1;
            window--;
            if(window == 0){
                if( freq2 == freq1){
                    return true;
                }else{
                    freq2[s2[l] - 'a'] = freq2[s2[l] - 'a'] - 1;
                    l++;
                    window++;
                }
            }
      	}
        return false;
    }
    
};
```

# 6.4 n-queen using backtracking algor

```cpp
/* C++ program to solve N Queen Problem using
   backtracking */
 
#include <bits/stdc++.h>
#define N 4
using namespace std;
 
/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}
 
/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
      then return true */
    if (col >= N)
        return true;
 
    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < N; i++) {
        /* Check if the queen can be placed on
          board[i][col] */
        if (isSafe(board, i, col)) {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
 
            /* recur to place rest of the queens */
            if (solveNQUtil(board, col + 1))
                return true;
 
            /* If placing queen in board[i][col]
               doesn't lead to a solution, then
               remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    /* If the queen cannot be placed in any row in
        this column col  then return false */
    return false;
}
 
/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise, return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
 
    printSolution(board);
    return true;
}
 
// driver program to test above function
int main()
{
    solveNQ();
    return 0;
}
 
// This code is contributed by Aditya Kumar (adityakumar129)
////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string> > sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
		    if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
		    if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    // Recursive Function (solve) - It basically tries all possible placement of queen for the current row & recurses for it's next row
    void solve(vector<string>& board, int row) {
	// Base condition. 
    // We reached the last row, so we have a solution so we add it to the solution vector
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    // Try placing a queen on each column for a given row. 
        // Explore next row by placing Q at each valid column for the current row
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }
};
```







# 6.6 reverse linked list

I don;t think this will work on reversing the linked list.

```cpp
//this will not work
ListNode* reverse(ListNode* headA, int len){
        if(len<2){
            return;
        }
        ListNode* cur=headA;
        ListNode* nxt=headA->next;
        ListNode* res;
        
        while(cur->next){
            cout << cur->val << " " << nxt->val << endl;
            cur->next = nxt->next;
            nxt->next = cur;
            nxt = cur->next;
        }
    }
//////////////////////////// reverse linked list
void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
```

![Lightbox](https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif)



# 6.8 reverse string(vector)

```cpp
//use O(n) space
string tmp;
for(int i=0;i<size_s;i++){
	tmp.push_back(s[size_s-i-1]);
}

//using O(1) space
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
 
}
```

# 6.9 Longest Substring Without Repeating Characters

Commonly used tables are:

- `int[26]` for Letters 'a' - 'z' or 'A' - 'Z'
- `int[128]` for ASCII
- `int[256]` for Extended ASCII

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we will store a senitel value of -1 to simulate 'null'/'None' in C++
        vector<int> chars(128, -1);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];

            int index = chars[r];
            if (index != -1 and index >= left and index < right) {
                left = index + 1;
            }
            res = max(res, right - left + 1);

            chars[r] = right;
            right++;
        }
        return res;
    }
};


int lengthOfLongestSubstring(string s) {
        int ans=0;
        int start=0;      // Index Substring starts from 
        unordered_map<char,int> u;
		
        for(int i=0;i<s.length();i++){
            if(u.find(s[i])==u.end()){ 
                u[s[i]]=i;     // new character
            }
            else{
                if(u[s[i]]<start){
                    u[s[i]]=i;   // existing char but before the start
                }
                else{
                    start=u[s[i]]+1;
                    u[s[i]]=i;
                }
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
```

# 6.10 Count Number of Rectangles Containing Each Point

```c++
std::sort(vector1.begin(),
          vector1.end(),
          //lambda expression
          [] (const std::vector<double> &a, const std::vector<double> &b)
          {
              return a[3] < b[3];
          });
```

```cpp
std::lower_bound function

Vector contains : 10 20 30 30 30 40 50

lower_bound for element 30 at position : 2
lower_bound for element 35 at position : 5
lower_bound for element 55 at position : 7
Return the last element position of a sorted array which is exactly less than or equal to the val;

lower_bound(.begin(),.end(),x)
            
```

```cpp
////////////////////////////////vector
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> umap(101);
        for (auto r: rectangles) {
            umap[r[1]].push_back(r[0]);
        }
        
        for (int i = 0; i < 101; i++) {
            sort(begin(umap[i]), end(umap[i]));
        }
        
        vector<int> res;
        for (auto &p: points) {
            int sum = 0;
            for (int i = p[1]; i < 101; i++) {
                auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
                sum += end(umap[i]) - lb;
            }
            res.push_back(sum);
        }
        return res;
    }
};

/////////////////////////////////////////////////map
class Solution {
		public:
			vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
				int n = r.size();
				sort(r.begin(),r.end());
				unordered_map<int,vector<int>> m;
				for(int i=0; i<n; i++){
					m[r[i][1]].push_back(r[i][0]);
				}

				vector<int> res;
				for(int i=0; i<p.size(); i++){
					int x = p[i][0];
					int y = p[i][1];
					int cnt = 0;
					for(int h=y; h<=100; h++){
						if(m.find(h)!=m.end()){
							int lb = lower_bound(m[h].begin(),m[h].end(),x)-m[h].begin();
							cnt += m[h].size()-lb;
						}
					}
					res.push_back(cnt);
				}
				return res;

			}
		};
```

# 6.11 Minimum Operations to Reduce X to Zero

Unordered_map\<int,vector\<int\>\>

**By transferring the operation to remove leftmost or right most reversely to finding the remaining sum of the middle subarray of nums[] to sum-x as target!!!!**

We need to make `prefix_sum + suffix_sum = x`. But instead of this, finding a subarray whose sum is `sum(nums) - x` will do the job. Now we only need to maximize the length of this subarray to minimize the length of `prefix + suffix`, which can be done greedily. By doing this, we can get the minimum length, i.e., the minimum number of operations to reduce `x` to exactly `0` (if possible).



If you haven't heard the term "sliding window" before, visit [this link](https://stackoverflow.com/questions/8269916/what-is-sliding-window-algorithm-examples).



1. Let us take a sliding window whose ends are defined by `start_idx` and `end_idx`.
2. If the sum of this sliding window (subarray) exceeds the target, keep reducing the window size (by increasing `start_idx`) until its sum becomes `<= target`.
3. If the sum becomes equal to the target, compare the length, and store if it exceeds the previous length.
4. Return `-1` if the sum of the sliding window never becomes equal to `target`.

```cpp
class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
    }
};
```

# 6.11 vector 拼接

vec3.insert(vec3.end(),vec1.begin(),vec1.end());



# 7.2 from int * int to longlong

```cpp
long long l_res = (long long)max_v* (long long)max_h;
# by this we get int to longlong avoid 9999999*10000000 error problem
```

# 7.31 unordered_set usage problem (4sum)

set cannot do hash with vector\<int\> type of data

**because unordered_set is using std::hash template to compute hash for its entries and there is no std::hash for pairs. You have to define custom hash to use unordered_set.**

```cpp
    struct vector_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &v) const
    {
        return std::hash<T1>()(v.size());    
    }
};
```

```cpp
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res={};
        vector<vector<int>> f_res={};
        vector<int> cur={};
        unordered_set<vector<int>,VectorHash> mset; // !!!!!!!!!!!!!!
        
        DFS(nums,target,cur,res,0);
        
        
        for(auto r:res){
            mset.insert(r);
        }
        for(unordered_set<vector<int>>::iterator it=mset.begin();it!=mset.end();it++){
            f_res.push_back(*it);
        }
        return f_res;
    }
    
    void DFS(vector<int>& nums, int target, vector<int>& cur, vector<vector<int>>& res, int k){
        
        if(cur.size()==4){
            if(target==0) res.push_back(cur);
            return;
        }
        if(nums.size()==0) return;
        
        vector<int> num(nums);
        
        for(int i=k;i<nums.size();i++){
            int val= num[i];
            num.erase(num.begin()+i);
            
            cur.push_back(val);
            DFS(num,target-val,cur,res,i);
            cur.pop_back();
            
            num.insert(num.begin()+i,val);
        }
        return;
        
    }
};
```

# 7.31 creating a segment tree to realize a new data structure

```cpp
class NumArray {
    inline static int n;
    int* segTree;
public:
    NumArray(vector<int>& nums) {
        n = size(nums);
        segTree = (int*)malloc(4 * n * sizeof(int));
        build(nums, 1, 0, n - 1);
    }
    
    void build(vector<int>& nums, int segIdx, int l, int r) {
        if(l == r) segTree[segIdx] = nums[l];      // can't split further - assign corresponding index of segTree as nums[l]
        else {
            int mid = (l + r) / 2;                 // divide array into two halves (left and right child of current node of segment tree)
            build(nums, 2*segIdx, l, mid);         // calculate result for left child
            build(nums, 2*segIdx + 1, mid + 1, r); // calculate result for right child
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1];  // merge result into parent - parent val = sum of left & right child
        }
    }
    
    void update(int index, int val, int segIdx = 1, int l = 0, int r = n - 1) {
        if(l == r) segTree[segIdx] = val;           // update segment tree index corresponding to the array index to be updated
        else {
            int mid = (l + r) / 2;
            if (index <= mid) update(index, val, 2*segIdx, l, mid);       // if node holding [nums[index]] segment lies in left child, recurse for it
            else update(index, val, 2*segIdx + 1, mid + 1, r);            // other wise recurse the right child
            segTree[segIdx] = segTree[2*segIdx] + segTree[2*segIdx + 1];  // child nodes got updated - so parent need to be updated again as sum of left + right child nodes
        }
    }
    
    int sumRange(int left, int right, int segIdx = 1, int l = 0, int r = n - 1) {
        if(left > right) return 0;   
        if(l == left && r == right) return segTree[segIdx];  // case - 1
        int mid = (l + r) / 2;
		// case - 2 and 3
		// Here, we are picking min(right, mid) & max(left, mid+1) to ensure that [left, right] is always subrange of [l, r] for recursive call 
		// otherwise base condition would never be reached in some cases
        return  sumRange(left, min(right, mid), 2*segIdx, l, mid) + 
                sumRange(max(left, mid + 1), right, 2*segIdx + 1, mid + 1, r);
    }
};
```

***Time Complexity :***



- Initial construction: **`O(N)`**, where `N` is the number of elements in *`nums`*.
- `update()`: **`O(logN)`** for each call
- `sumRange()`: **`O(logN)`** for each call



***Space Complexity :*** **`O(N)`**, required to maintain the *`segTree`* array

```cpp
class SegmentTree {
    SegmentTree *left, *right;
    int L, R, val;
public:
    SegmentTree(vector<int>& nums, int l, int r): L(l), R(r), left(NULL), right(NULL) {
        build(nums);
    }
    void build(vector<int>& nums) {
        if(L == R) val = nums[L];
        else {
            int mid = (L + R) / 2;
            left = new SegmentTree(nums, L, mid);
            right = new SegmentTree(nums, mid + 1, R);
            val = left -> val + right -> val;
        }
    }
    void update(int i, int new_val) {
        if(L == R) val = new_val;
        else {
            int mid = (L + R) / 2;
            if(i <= mid) left -> update(i, new_val);
            else right -> update(i, new_val);
            val = left -> val + right -> val;
        }
    }
    int sum(int l, int r) {
        if(l > r) return 0;
        if(l == L && r == R) return val;
        int mid = (L + R) / 2;
        return left -> sum(l, min(mid, r)) + right -> sum(max(l, mid + 1), r);
    }
};
class NumArray {
    SegmentTree *tree;
public:
    NumArray(vector<int>& nums) {
        tree = new SegmentTree(nums, 0, size(nums) - 1);
    }
    
    void update(int index, int val) {
        tree -> update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree -> sum(left, right);
    }
};
```

# 8.1 two pointers removing duplicate and return net array

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;
        for(int right =1; right< nums.size(); right++){
           if(nums[left] != nums[right])
               left++;
               nums[left] = nums[right];
           }
    return left+1;
    }
};




int removeDuplicates(vector<int>& nums){
	nums.erase(unique(nums.begin() ,nums.end()),nums.end() ); 
	return nums.size() ;
}
```

# 8.2 max heap && min heap

```cpp
priority_queue <``int``, vector<``int``>, greater<``int``> > pq; //min_heap
priority_queue <int> pq; //max_heap
using namespace std;
  

// User defined class, Point
class Point
{
   int x;
   int y;
public:
   Point(int x, int y)
   {
      this->x = x;
      this->y = y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
  
// To compare two points
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};
  
// Driver code
int main ()
{
    // Creates a Min heap of points (order by x coordinate)
    priority_queue <Point, vector<Point>, myComparator > pq;
  
    // Insert points into the min heap
    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1, 5));
  
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        Point p = pq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        pq.pop();
    }
  
    return 0;
}
```

# finding the kth val in matrix

```cpp
//binary search
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int mid){
        int count = 0, n = matrix.size(), i = n-1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid) i--;
            else{
                count += (i+1);
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), i = matrix[0][0], j = matrix[n-1][n-1];
        while(i < j){
            int mid = i + (j-i)/2;
            int posi = solve(matrix, mid);
            if(posi < k) i = mid+1;
            else j = mid;
        }
        return i;
    }  
};
//heap(priority queue)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq; int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        return pq.top();   
    }
};
```

# 8.6 combination sum IV

```c++
//bottom up DP
int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j:nums)
            {
                if(i>=j)
                    dp[i]+=dp[i-j];
            }
        }
        
        return dp[target];
        
    }

//Memoizing the recursion: DP- Top down approach
int bt(vector<int> nums,int target,vector<int>&cache) 
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(cache[target]!=-1)
            return cache[target];
        int res=0;
        for(int i:nums)
        {
            res+=bt(nums,target-i,cache);
        }
        return cache[target]=res;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> cache(target+1,-1);
        
        return bt(nums,target,cache);
        
    }

```

# 4Sum two pointers

```cpp
 //Approach is given below.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //ans vector to store final ans.
        vector<vector<int>> ans;

        //sorting the nums array
        sort(nums.begin(),nums.end());

        int n = nums.size();

        for(int i=0; i<n; ++i){
            long long remain = target - nums[i];

            for(int j = i+1; j < n; ++j){
                int left = j+1, right = n-1;
                long long remain2 = remain - nums[j];

                while(left < right){
                    if((nums[left] + nums[right]) < remain2) left++;
                    else if((nums[left] + nums[right]) > remain2) right--;
                    else{
                        //x stores the element at position left & it is done to compare and eliminate duplicates in below while loop.
                        int x = nums[left]; 
                        //y stores the element at position right & it is done to compare and eliminate duplicates in below while loop.
                        int y = nums[right];

                        //push quadruplet with sum equal to target inside ans array.
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]}); 

                        //skipping duplicates encountered while iterating from left.
                        while(left < right && nums[left] == x) ++left;

                        //skipping duplicates encountered while iterating from right.
                        while(left < right && nums[right] == y) --right;

                    }         
                }

                //skipping duplicates while iterating through 'j' loop.
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }

            //skipping duplicates while iterating through 'i' loop.
            while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }

        return ans;
    }
};

/*
Approach:
* First we will sort the array. 
* We will be using four pointers(i.e. i,j,left and right) to traverse through whole array.

* fixing two pointers i and j then using two pointers approach to find the 
  remaining sum(i.e. target-(nums[i] + nums[j])) between [left,right].
  
* if (element at left + element at right) is equals to remaining sum(i.e target-(nums[i] + nums[j]))
  we push the elements at pointer i,j,left and right into ans array and if not we increment left 
  or decrement right depending upon sum like we do in binary search.
  
* But one thing we have to make sure that we are not pushing the duplicates into ans vector.

* We are taking care of that by skipping duplicates while there is no duplicate left.
*/
```

# 8.7 remove nth node from end from linked list using two pointer(slow fast)

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};
```

# C++ 生成 1到n vector

```cpp
3.使用 std::generate_n
我们也可以使用 std::generate_n 函数通过重复调用生成器函数来生成连续值。这可以在 C++ 中如下实现。

#include <iostream>
#include <vector>
#include <algorithm>
 
struct increment {
    int value;
    increment(): value(0) {}
    int operator() () { return ++value; }
};
 
int main()
{
    const int n = 10;
    std::vector<int> v(n);
 
    std::generate_n(v.begin(), n, increment());
 
    for (int &i: v) {
        std::cout << i << ' ';
    }
 
    return 0;
}

```

# BAD pair j-i != nums[j]-nums[i]

```cpp
// j-nums[j]!=i-nums[i]
long long countBadPairs(vector<int>& a,long cnt=0) {
    unordered_map<int,int> mp;
    for(int i=0;i<size(a);i++){
        cnt+= i- mp[i-a[i]];
        mp[i-a[i]]++;
    }
    return cnt;
}
```

# 8.10 List to BST

```cpp
class Solution {
private:
    TreeNode* ToBST(vector<int>&nums, int low, int high){
        if(low>high)
            return NULL;
        int mid = (low+high)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = ToBST(nums, low, mid-1);
        temp->right = ToBST(nums, mid+1, high);
        return temp;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ToBST(nums, 0, nums.size()-1);
    }
};
```

# 8.12 validate BST

```cpp
//first way is to do inorder sort to get the list and the check is ascending
//second is to save the low,high value of this point and chech if break or not.
class Solution {
public:
    bool helper(TreeNode* root,long low ,long high){
        // Empty trees are valid BSTs.
        if(root == NULL){
            return true;
        }
        
        // Condition of Binary Search Tree 
        // left side node values of the root should be less value than the root and right side should be greater
        // If that is true check recursivley for the root child's
        
        if((root->val < high) && (root->val > low)){
          return (helper(root->left, low, root->val) && helper(root->right, root->val, high));

        }else{
            //if this root node violates the min/max constraint
            return false;
        }
        
    }
    
    bool isValidBST(TreeNode* root) {
        bool ans = helper(root, LONG_MIN, LONG_MAX);
        return ans;
    }
};
```

# 8.13 Shortest Unsorted Continuous Subarray

```cpp
sort(v.begin(),v.end(),greater<>());


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int ans = 0;  
        
        // Two pointers
        int i = 0;
        int j = nums.size() - 1;

        int curr_max=INT_MAX;
        int curr_min=INT_MIN;
        
        // Initialize end to -1, if we have all sorted in ascending order, then end-start+1 = -1+0+1 = 0 
        int start=0,end=-1;
        
        while(j >= 0){
            // Check if the "num[start]" is greater than the minimum element so far
            if(nums[i] >= curr_min) curr_min = nums[i];
            else end = i; // m contains the 

            // Check if the "num[end]" is less than the maximum element so far
            if(nums[j] <= curr_max) curr_max = nums[j];
            else start = j;

            ++i;
            --j;
        }
        return end - start + 1;
    }
};
```

# 8.14 swap

```cpp
for(int k=0;k<=(j-i)/2;k++){
    swap(s[i+k],s[j-k]);
}
```

# Longest increasing subsequence

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int i{1}; i<n; i++){
            for(int j{0}; j<i; j++){
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        return *max_element(dp.begin(), dp.end()); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
};
```

**tail method:**

Time Complexity = O(nlogn)
Space Complexity = O(n)

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> tail;
        
        for(int num : nums){
            if(tail.empty() || num > tail.back()){
                tail.push_back(num);
            }
            else{
                tail[firstGreatEqual(tail, num)] = num;
            }
        }
        
        return tail.size();
    }
private:
    int firstGreatEqual(vector<int>& t, int tr){
		// For finding the index of target element.
		// Lower_Bound solves via Binary Search.
        return lower_bound(t.begin(), t.end(), tr) - t.begin();
    }
};
```

# 8.18 c++八股文

**指针&引用（X空值引用，√空值指针）**

define & typedef

define & inline 限制

override & overload 规则`

new & malloc ============> operator and function

1.自由存储是C++中通过new与delete动态分配和释放对象的抽象概念，而堆（heap）是C语言和操作系统的术语，是操作系统维护的一块动态分配内存。
2.new所申请的内存区域在C++中称为自由存储区。藉由堆实现的自由存储，可以说new所申请的内存区域在堆上。
3.堆与自由存储区还是有区别的，它们并非等价。



python

Big data/Stream data related technologies with Apache Spark (Core, SQL, and Streaming) using Python is required. Proficiency with Hadoop, MapReduce, HDFS etc.





Christakos, Constantine



# 8.20  topological sort using DFS to find if acyclic. 函数内置写法

```cpp
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Initializing a 2d graph , result vector and indegree array
        vector<vector<int>> graph(numCourses);
        vector<int> result, indegree(numCourses);
        
        //Indegree
        for(auto& prereq : prerequisites)
            graph[prereq[1]].push_back(prereq[0]),
            indegree[prereq[0]]++;
        
        //dfs call ----------------------------------------------------!!!!!!!!!!!!
        function<void(int)> dfs = [&](int current) {
            //Adding the current course into the result 
            result.push_back(current);            
            //Making sure that the current course that we added is marked as visited
            indegree[current] = -1;                     
            
            //if any next course has a indegree of 0 ie if it has no prerequisites requirement than make dfs call for that course
            for(auto nextCourse : graph[current])          
                if(--indegree[nextCourse] == 0)     
                    dfs(nextCourse);                
        };
        
        // If the indegree becomes 0 of a course then again add them into DFS and start DFS call from that course .
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) dfs(i);                   
        
        //In the end return `result` if it contains all `numCourses` else return  []
        if(size(result) == numCourses) return result;
        return {};
    }
};
```

**Time Complexity :** *`O(N + E)`* [O(E) to form adjacency list and O(N + E) for our DFS ].
**Space Complexity :** *`O(N + E)`*, [Used by recursive stack and prerequisites as adjacency list graph in `graph`]

------

# Kagn's to schedule courses with prerequisite(BFS+Queue)

```cpp
class Solution
{
public:
    bool kahnAlgo(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            // will push all the nodes with the indegree 0 in the queue as we have completed all the prerequisites for it.
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            // one by one we will take every element of the queue and will traverse the adjacency list of it 
            // and will remove that node and will reduce the indegree of the adjacent nodes which are
            // prerequisites for it.
            int curr = q.front();
            q.pop();

            for (auto a : adj[curr])
            {
                indegree[a] -= 1;
                // and will push the node having 0 indegree in the queue.
                if (indegree[a] == 0)
                    q.push(a);
            }
            // and after processing current node, will push it in the ans.
            ans.push_back(curr);
            count++;
        }

        // checking for DAG.
        if (count != n)
            return false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses); // Adjacency matrix.
        vector<int> indegree(numCourses, 0); // indegree array.

        // traversing all the nodes of the graph.
        for (int i = 0; i < n; i++)
        {
            // filling adjacency matrix for all the nodes of the graph.
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            // also filling indegree value for all nodes.
            indegree[prerequisites[i][0]] += 1;
        }

        vector<int> ans;

        // if graph is DAG and Kahn's algo is applied then return the ans.
        if (kahnAlgo(adj, numCourses, indegree, ans))
            return ans;

        // otherwise return the empty vector.
        return {};
    }
};
```

# check if DAG has cycle DFS

```cpp
class Solution {
public:
    int color[2001] = {0};
    // 0 -> white or unvisited
    // 1 -> gray or visiting
    // 2-> black or visited
    bool DFS(int v, vector<int> adj[], vector<int>&res) {
    if(color[v]==1) { // when you meet the same node twice which traversing the route , it has a cycle
        return false; // break from cycle
    }
	color[v] = 1;

	for(int u = 0; u < adj[v].size(); ++u ) {    
    	if(color[adj[v][u]]==0) { // visit only unvisited nodes
             if(!DFS(adj[v][u], adj, res)) { // if cycle discovered , break free and return false
                 return false;
             }
		}
        if(color[adj[v][u]]==1) {
             return false;
         }
		
	}
    color[v] = 2;
    res.push_back(v);
	return true;
}    

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
	vector<int> adj[numCourses];
	vector<int> res;
	for(int i = 0; i < n; ++i) {
		adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
	}
	
	for(int v = 0; v < numCourses; ++v) {
        if(color[v]==0) { 
            if (!DFS(v, adj, res))  return {}; 
        }
	}
	return res;
    }
};
```

# algo for topological sorting

## 1.kahn's

## 2.kosaraju's

## 3.tarjan's

**Kahn's algorithm works by keeping track of the number of incoming edges into each node (indegree).** 

# 8.19 C++ 项目

- 编程语言
  - [C++面试&C++学习指南知识点整理](https://github.com/youngyangyang04/TechCPP)
- 项目
  - [基于跳表的轻量级KV存储引擎](https://github.com/youngyangyang04/Skiplist-CPP)
  - [Nosql数据库注入攻击系统](https://github.com/youngyangyang04/NoSQLAttack)

## 项目 

### 自己写一套STL 

对于应届生的话，在学习stl的同时，可以实现一套自己的mini STL，即熟悉了stl的原理，也锻炼的编码能力，代码传到github上 可以作为自己的一个项目。

[推荐看这个](https://github.com/Alinshans/MyTinySTL)

### web server 

如果对网络编程不太了解，建议写一个web server，虽然这个项目已经烂大街，但依然有很多可以优化的地方，代码传到github上，链接贴在简历里，面试官一定会看，只要代码写的不错，一定是加分项。

[推荐看这个](https://github.com/qinguoyi/TinyWebServer)

### 视频推荐

可以看[牛客的C++求职项目](https://www.nowcoder.com/courses/cover/live/504)  ，可以看这位录友做本[项目的心得](https://t.zsxq.com/mq3j2be)

### kv 存储引擎

[详细看这里](https://t.zsxq.com/fUzbMfA)  

这个项目可以和这两位录友讨论：

- [跳表项目建议](https://t.zsxq.com/6uZbmYv) 
- [跳表项目讨论](https://t.zsxq.com/EaYRnY3)

### 国外的一些实验 

[TCP协议，操作系统内核，CSAPP的配套实验等](https://t.zsxq.com/q7YfuRJ)  

- [一起做csapp lab的同学](https://t.zsxq.com/02yrRzfem)

## 分布式

[mit 6.824 分布式系统](https://mit-public-courses-cn-translatio.gitbook.io/mit6-824/)

### 如何看开源项目

[看这里](https://t.zsxq.com/eaeubuV)



数据库三范式 

⼀、简单归纳  

1. 第⼀范式（1NF）：字段不可分；  

2. 第⼆范式（2NF）：有主键，⾮主键字段依赖主键；  

3. 第三范式（3NF）：⾮主键字段不能相互依赖。  

   ⼆、解释  

   1. 1NF：原⼦性。字段不可再分,否则就不是关系数据库;； 
   2. 2NF：唯⼀性 。⼀个表只说明⼀个事物； 
   3. 3NF：每列都与主键有直接关系，不存在传递依赖。 

# 8.21

- `s` consists of English letters, digits, symbols and spaces. ==> vector\<int\> (128,0)

```
lower_bound(nums.begin(),nums.end(),target)
upper_bound(nums.begin(),nums.end(),target)
```

# 8.22 rotate string leftshift or rightshift

```cpp
//////////////////////////////////////////////////////////////////// O(n) O(1)
#include<bits/stdc++.h>
using namespace std;
 
// In-place rotates s towards left by d
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
 
// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}
 
// Driver code
int main()
{
    string str1 = "GeeksforGeeks";
    leftrotate(str1, 2);
    cout << str1 << endl;
 
    string str2 = "GeeksforGeeks";
    rightrotate(str2, 2);
    cout << str2 << endl;
    return 0;
}

//////////////////////////////////////////////////////////////////// O(n) O(n)

string leftrotate(string str1, int n)
{
 
    // creating extended string and index for new rotated
    // string
    string temp = str1 + str1;
    int l1 = str1.size();
 
    string Lfirst = temp.substr(n, l1);
 
    //      now returning  string
    return Lfirst;
}
// Rotating the string using extended string
string rightrotate(string str1, int n)
{
 
    return leftrotate(str1, str1.size() - n);
}
```

# 8.23 longlong_min

```cpp
1. CHAR_MIN : 

Minimum value for an object of type char
Value of CHAR_MIN is either -127 (-27+1) or less* or 0
2. CHAR_MAX :  

Maximum value for an object of type char
Value of CHAR_MAX is either 127 (27-1) or 255 (28-1) or greater*    
3. SHRT_MIN :  

Minimum value for an object of type short int
Value of SHRT_MIN is -32767 (-215+1) or less*
4. SHRT_MAX :  

Maximum value for an object of type short int
Value of SHRT_MAX is 32767 (215-1) or greater*
5. USHRT_MAX :  

Maximum value for an object of type unsigned short int    
Value of USHRT_MAX is 65535 (216-1) or greater*
6. INT_MIN :  

Minimum value for an object of type int    
Value of INT_MIN is -32767 (-215+1) or less*
7. INT_MAX : 

Maximum value for an object of type int    
Value of INT_MAX is 32767 (215-1) or greater*
8. UINT_MAX :  

Maximum value for an object of type unsigned int    
Value of UINT_MAX is 65535 (216-1) or greater*
9. LONG_MIN :  

Minimum value for an object of type long int    
Value of LONG_MIN is -2147483647 (-231+1) or less*
10. LONG_MAX :  

Maximum value for an object of type long int    
Value of LONG_MAX is 2147483647 (231-1) or greater*
11. ULONG_MAX :  

Maximum value for an object of type unsigned long int    
Value of ULONG_MAX is 4294967295 (232-1) or greater*
12. LLONG_MIN :  

Minimum value for an object of type long long int    
Value of LLONG_MIN is -9223372036854775807 (-263+1) or less*
13. LLONG_MAX :  

Maximum value for an object of type long long int    
Value of LLONG_MAX is 9223372036854775807 (263-1) or greater*
14. ULLONG_MAX :  

Maximum value for an object of type unsigned long long int    
Value of ULLONG_MAX is 18446744073709551615 (264-1)

CHAR_MIN : -128
CHAR_MAX : 127
SHRT_MIN : -32768
SHRT_MAX : 32767
USHRT_MAX : 65535
INT_MIN : -2147483648
INT_MAX : 2147483647
UINT_MAX : 4294967295
LONG_MIN : -9223372036854775808
LONG_MAX : 9223372036854775807
ULONG_MAX : 18446744073709551615
LLONG_MIN : -9223372036854775808
LLONG_MAX : 9223372036854775807
ULLONG_MAX : 18446744073709551615

vector<long long> B={};
for(int i=0;i<N/2;i++){
	B.push_back((ll)A[i]*(ll)A[N-i-1]);
}


```

# 8.23 palindrome for linked list

```cpp
//first way is to use stack, and check again O(n) O(n)
//second is to use fast slow pointer to get to the middle point of the linked list
//then reverse the rear part of the linked list to check if same with the gear part. 
//O(n) O(1)
void reverse(struct Node**); 
bool compareLists(struct Node*, struct Node*); 
  
// Function to check if given linked list is 
// palindrome or not 
bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
      
    // To handle odd size list 
    struct Node* midnode = NULL; 
      
    // initialize result 
    bool res = true; 
  
    if (head != NULL && head->next != NULL)
    {
          
        // Get the middle of the list. Move slow_ptr by 1 
        // and fast_ptr by 2, slow_ptr will have the middle 
        // node 
        while (fast_ptr != NULL && fast_ptr->next != NULL) 
        { 
            fast_ptr = fast_ptr->next->next; 
  
            // We need previous of the slow_ptr for 
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it 
        // somewhere so that we can restore the 
        // original list
        if (fast_ptr != NULL)
        { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and 
        // compare it with first half 
        second_half = slow_ptr; 
          
        // NULL terminate first half 
        prev_of_slow_ptr->next = NULL; 
          
        // Reverse the second half 
        reverse(&second_half); 
          
        // compare 
        res = compareLists(head, second_half); 
  
        // Construct the original list back 
        reverse(&second_half); // Reverse the second half again 
  
        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half. 
        if (midnode != NULL)
        { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
} 
  
// Function to reverse the linked list 
// Note that this function may change 
// the head 
void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
      
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
// Function to check if two input
// lists have same data
bool compareLists(struct Node* head1, 
                  struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2)
    { 
        if (temp1->data == temp2->data) 
        { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    // Will reach here when one is NULL 
    // and other is not 
    return 0; 
} 
```

# unordered_set 不可以存vector,pair 这种因为内置hash问题

# 8.24 triplets 三元组问题

Given an array **A[]** consisting of **N** integers. The task is to count the number of triples (A[i], A[j], A[k]), where **i**, **j,** and **k** denote the respective indices, such that one of the integers can be written as the summation of the other two integers.

**Examples:**

**Input:** A[] = {1, 2, 3, 4, 5}
**Output:** 4

- Compute the value of the **maximum element, mx** of the array.
- Build a frequency array, **freq** of size **mx + 1** and store the frequency of all the elements of the array **A[]**.
- Initialise a count variable and consider the above four cases one by one:
  - If the triplet is **(0, 0, 0)**, add freq[0]C3 to **count**.
  - If the triplet is **(0, x, x)**, add freq[0]C1 * freq[x]C2 to **count**.
  - If the triplet is **(x, x, 2x)**, add freq[x]C2 * freq[2x]C1 to **count**.
  - If the triplet is **(x, y, x + y)**, add freq[x]C1 * freq[y]C1 * freq[x + y]C1 to **count**.
- Return **count**.

### C++ Code For Hashing Method

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int count_Triplets(int A[], int n){
        int max_val = 0;
        for (int i = 0; i < n; i++)
            max_val = max(max_val, A[i]);
        int freq[max_val + 1]={0};
        for (int i = 0; i < n; i++)
            freq[A[i]]++;
 
        int count = 0;  
    
        count += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;
 
        for (int i = 1; i <= max_val; i++){
            count += freq[0] * freq[i] * (freq[i] - 1) / 2;
        }
 
        for (int i = 1; 2 * i <= max_val; i++){
            count += freq[i] * (freq[i] - 1) / 2 * freq[2 * i];
        }
 
        for (int i = 1; i <= max_val; i++) {
            for (int j = i + 1; i + j <= max_val; j++)
                count += freq[i] * freq[j] * freq[i + j];
        }
 
        return count;
    }
 
 
int main() {
	// Your code goes here;
	int A[] = {1, 2, 3, 4, 5};
	int N = 5;
	cout << count_Triplets(A, N);
	return 0;
}
```

# 8.24 triplet 变形问题i<j<k a[i]+a[j]+a[k]=0

```cpp
// C++ program to find triplets in a given
// array whose sum is zero
#include<bits/stdc++.h>
using namespace std;
  
// function to print triplets with 0 sum
void findTriplets(int arr[], int n)
{
    bool found = false;
  
    for (int i=0; i<n-1; i++)
    {
        // Find all pairs with sum equals to
        // "-arr[i]"
        unordered_set<int> s;
        for (int j=i+1; j<n; j++)
        {
            int x = -(arr[i] + arr[j]);
            if (s.find(x) != s.end())
            {
                printf("%d %d %d\n", x, arr[i], arr[j]);
                found = true;
            }
            else
                s.insert(arr[j]);
        }
    }
  
    if (found == false)
        cout << " No Triplet Found" << endl;
}
  
// Driver code
int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    findTriplets(arr, n);
    return 0;
}
//也可以用前面 0 0 0/0 x -x/x y -(x+y)freq 的方法
```

# 8.24 triplet 变形问题i<j<k a[i]<a[j]<a[k] 存在问题

```cpp
//has increasing triplet subsequence
bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;
        for (auto num : nums) {
            if (num < one)
                one = num;
            else if (one < num && num < two)
                two = num;
            else if (two < num)
                return true;
        }
        return false;
    }
//count numbers of it

```

# 8.24 triplet 变形问题i<j<k a[i]>a[j]>a[k]

```cpp
Find the greater_left array. greater_left[i] represents the number of elements greater than a[i] and in left side of it ( from 0 to i-1 ).
Find the smaller_right array. smaller_right[i] represents the number of elements smaller than a[i] and in right side to it ( from i+1 to n-1 )
The final answer will be the sum of the product of greater_left[i] and smaller_right[i] for every index.
```

# 8.24 triplet 变形问题Find maximum sum of triplets in an array such than i < j < k and a[i] < a[j] < a[k] 求和问题

```cpp
 for (int i = 1; i < n - 1; ++i) {
        int max1 = 0, max2 = 0;
 
        // find maximum value(less than arr[i])
        // from 0 to i-1
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
                max1 = max(max1, arr[j]);
 
        // find maximum value(greater than arr[i])
        // from i+1 to n-1
        for (int j = i + 1; j < n; ++j)
            if (arr[j] > arr[i])
                max2 = max(max2, arr[j]);
 
        // store maximum answer
        if(max1 && max2)
             ans=max(ans,max1+arr[i]+max2);
    }
// optimize using binary search
```



# 8.24 triplet 变形问题三元组(i,j,k)满足i<j<k且a[i]-a[j]=2a[j]-a[k]

# 8.27 substring with largest variance

```cpp
int largestVariance(string s) {
    int result = 0;
    for (char highFreqChar = 'a'; highFreqChar <= 'z'; ++highFreqChar) {
        for (char lowFreqChar = 'a'; lowFreqChar <= 'z'; ++lowFreqChar) {
            if (highFreqChar == lowFreqChar) continue;

            int highFreq = 0;
            int lowFreq = 0;
            bool lowFreqAbandoned = false;

            for (const char& ch : s) {
                if (ch == highFreqChar) ++highFreq;
                if (ch == lowFreqChar) ++lowFreq;



                if (lowFreq > 0) {
                    result = max(result, highFreq - lowFreq);
                } else {
                    // Edge case: there are no `lowFreqChar` in current interval.
                    // In case if we re-started Kadane algo calculation - 
                    // we can "extend" current interval with 1 previously abandoned 'lowFreqChar'
                    if (lowFreqAbandoned) {
                        result = max(result, highFreq - 1);
                    }
                } 
                if (lowFreq > highFreq) {
                    // Kadane's algo calculation re-start: abandon previous chars and their freqs.
                    // Important: the last abandoned char is the `lowFreqChar` - this can be used on further iterations.
                    lowFreq = 0;
                    highFreq = 0;
                    lowFreqAbandoned = true;
                }

            }
        }
    }
    return result;
}
```

# 8.28

```cpp
max_element(nums.begin(),nums.end());
accumulate(nums.begin(),nums.end(),0);
```

```cpp
vector<int> lst;
swap(lst[idx], lst[i]);

int arr[];
swap(&arr[idx],&arr[i]);
```

# 8.29 quicksort two kinds of partition way

```cpp
for (int j = low; j <= high - 1; j++) 
{ 
// If current element is smaller than the pivot 
if (arr[j] < pivot) 
{ 
i++; // increment index of smaller element 
swap(&arr[i], &arr[j]); 
} 
} 
swap(&arr[i + 1], &arr[high]); 
return i+1;

if (low < high) 
{ 
    /* pi is partitioning index, arr[p] is now 
    at right place */
    int pi = partition(arr, low, high); 

    // Separately sort elements before 
    // partition and after partition 
    quickSort(arr, low, pi - 1); 
    quickSort(arr, pi + 1, high); 
} 
////////////////////////////////////////////////////
Alg. PARTITION (A, p, r)
x ← A[p]
i ← p – 1
j ← r + 1
while TRUE
	do repeat j ← j – 1
		until A[j] ≤ x
	do repeat i ← i + 1
		until A[i] ≥ x
	if i < j
		then exchange A[i] ↔ A[j]
	else return j
    
QUICKSORT(A, p, r)
    if p < r
        then q ← PARTITION(A, p, r)
        QUICKSORT (A, p, q)//key difference
        QUICKSORT (A, q+1, r)

```

