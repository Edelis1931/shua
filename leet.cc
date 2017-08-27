1.	Two Sum
	1.	
















Easy
1.	Two Sum
	1. Brute方法很简单
	2. Hash的方法需要重点复习
		1.	重要语句:
		std::map<int,int> myhash;
		std::map<int,int>::iterator it; //定义名为it的iterator
		
		2.	重要知识点:
			1.	map是<int,int>,注意,要在第一个int,也就是key,放入数组的element的值.
				而在第二个int,也就是value,放入element的index.
				因为find函数只能找key,而不能找value.
				在找到pair后,要用iterator->second来返回value,也就是保存的index.
			
			2.	在key不存在的时候,可以用map[key] = value的方式加入新的key
				但是,map.at(key) = value是不可以的!会导致runtime error
				at()函数只能用来读取,不能用来添加元素,好处仍然是有exception保护
			
			3.	map.end()是element past last element,不是last element.该element实际不存在,不可以dereference. 只能通过iterator访问.
			
			4.	
		
		Hashtable的参考程序:
		class Solution {
		public:
			vector<int> twoSum(vector<int>& nums, int target) {
				
				map <int,int> myhash;
				for (int i = 0; i < nums.size(); i++){
					myhash[nums.at(i)] = i;
				}
				
				map <int,int>::iterator it;
				
				for (int i = 0; i < nums.size(); i++){
					it = myhash.find(target - nums.at(i));
					if (it != myhash.end()){
						int j = it->second;
						if (i == j){
							continue;
						}
						vector<int> result;
						result.push_back(min(i,j));
						result.push_back(max(i,j));
						return result;
					}
				}
				vector<int> noresult;
				return noresult;
			}
		};

6.	ZigZag Conversion
	1.	
	2.	
	3.	

7.	Reverse Integer
	1.	最大的问题是会overflow,还有就是可能用负数(这个好解决),int的最大值是2147483647
	2.	最简单的解法是直接long,然后加入和INT_MAX / INT_MIN的比较
	3.	如果不能用long,那么最简单的办法是:
		原先的判断条件是 if (result*10 + result%10 > INT_MAX)
		那么就改成 if (result > (INT_MAX - result%10) / 10)
		就不会overflow了
		其他不变
	4.	while (x) 可以代替 while (x != 0)
		
8.	String to Integer
	1.	非常需要注意的一点,十进制0的ASCII CODE是48,在做运算是,需要减去48
	2.	在当第一位是数字的时候,一定要把控制正负号的变量(在下面的参考程序里是status)设为正
	2.	我写的参考程序
	class Solution {
	public:
		int myAtoi(string str) {

			int i = 0;
			int size = str.size();

			if (size == 0){
				return 0;
			}

			int result = 0;
			int status = 0; //0 - not starting collecting yet; 1 - collection started, positive; 2- collection started, negative
			while(str.at(i) == ' '){
				i++;
			}

			if (str.at(i) == '+'){
				status = 1;
				i++;
			}else if (str.at(i) == '-'){
				status = 2;
				i++;
			}else if (str.at(i) <= '9' && str.at(i) >= '0'){
				status = 1;
				;
			}else{
				return 0;
			}

			while(i < size){
				if (str.at(i) <= '9' && str.at(i) >= '0'){
					if (status == 1 && result > (INT_MAX - int(str.at(i)) + 48)/10){
						return INT_MAX;
					}else if(status == 2 && result > (INT_MAX - int(str.at(i)) + 48)/10){
						return INT_MIN;
					}else{
						result = result*10 + int(str.at(i) - 48);
						i++;
					}
				}else{
					if (status == 1){return result;}
					if (status == 2){return result*-1;}
				}
			}
			if (status == 1){return result;}
			if (status == 2){return result*-1;}
		}
};

9.	Palindrome Number
	1.	用前后除法取数的方法,会挂在100030001等test case
	
	2.	
	
	3.	参考正确程序:
	
	class Solution {
	public:
		bool isPalindrome(int x) {
			
			if (x < 0) return false;
			
			int len = 0;
			int temp = x;
			
			while (temp > 0){
				temp /= 10;
				len++;
			}
			
			int mypow = pow(10, len - 1);
			
			while (x > 0){
				int head = x / mypow;
				int end = x % 10;
				if (head != end){
					return false;
				}
				x = (x % mypow) / 10;
				mypow /= 100;
			}
			
			return true;
		}
	};

10.	