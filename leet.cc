1.	Two Sum
	1.	
















Easy
1.	Two Sum
	1. Brute�����ܼ�
	2. Hash�ķ�����Ҫ�ص㸴ϰ
		1.	��Ҫ���:
		std::map<int,int> myhash;
		std::map<int,int>::iterator it; //������Ϊit��iterator
		
		2.	��Ҫ֪ʶ��:
			1.	map��<int,int>,ע��,Ҫ�ڵ�һ��int,Ҳ����key,���������element��ֵ.
				���ڵڶ���int,Ҳ����value,����element��index.
				��Ϊfind����ֻ����key,��������value.
				���ҵ�pair��,Ҫ��iterator->second������value,Ҳ���Ǳ����index.
			
			2.	��key�����ڵ�ʱ��,������map[key] = value�ķ�ʽ�����µ�key
				����,map.at(key) = value�ǲ����Ե�!�ᵼ��runtime error
				at()����ֻ��������ȡ,�����������Ԫ��,�ô���Ȼ����exception����
			
			3.	map.end()��element past last element,����last element.��elementʵ�ʲ�����,������dereference. ֻ��ͨ��iterator����.
			
			4.	
		
		Hashtable�Ĳο�����:
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
	1.	���������ǻ�overflow,���о��ǿ����ø���(����ý��),int�����ֵ��2147483647
	2.	��򵥵Ľⷨ��ֱ��long,Ȼ������INT_MAX / INT_MIN�ıȽ�
	3.	���������long,��ô��򵥵İ취��:
		ԭ�ȵ��ж������� if (result*10 + result%10 > INT_MAX)
		��ô�͸ĳ� if (result > (INT_MAX - result%10) / 10)
		�Ͳ���overflow��
		��������
	4.	while (x) ���Դ��� while (x != 0)
		
8.	String to Integer
	1.	�ǳ���Ҫע���һ��,ʮ����0��ASCII CODE��48,����������,��Ҫ��ȥ48
	2.	�ڵ���һλ�����ֵ�ʱ��,һ��Ҫ�ѿ��������ŵı���(������Ĳο���������status)��Ϊ��
	2.	��д�Ĳο�����
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
	1.	��ǰ�����ȡ���ķ���,�����100030001��test case
	
	2.	
	
	3.	�ο���ȷ����:
	
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