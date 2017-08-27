[WOCAO]:非常难的难题/难点
[LID]:亮点,非常重要的知识点,可能不局限于此题,而是面向所有的题目

---------------------------------------------------------------------------

>-------------------------------------------------------------------------<

INT_MIN	-2147483648
INT_MAX 2147483647

>-------------------------------------------------------------------------<

root->right不能用right代替

>-------------------------------------------------------------------------<
static int a; //Zero Initialized
int b; //Zero Initialized

int main()
{
    int i;  //Undefined Behavior, Might be Initialized to anything  <- 根据compiler不同,这个值可能会变.在有些compiler里(比如lintcode,cpp.sh),i仍然会被设定成0,但要注意避免这个情况.
    static int j; //Zero Initialized
    return 0;
}

>-------------------------------------------------------------------------<

queue的一些function:
push(x):推入数据x
pop():消灭最old的元素,是void,无return
front():retrieve最old的元素
back():retrieve最new的元素
empty():check if it's empty
无clear();没有clear函数,
要clear queue,可以:
void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}

>-------------------------------------------------------------------------<

关于vector的clear:
A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function. A typical alternative that forces a reallocation is to use swap:
vector<T>().swap(x);   // clear x reallocating 

>-------------------------------------------------------------------------<

创建一个2D的vector:
int row
int col
vector<vector<int>> result;
result.resize(row, vector<int>(col, 0));
不要写成: result.resize(row, vector<col,0>);

>------------------------------------------------------------------------<

std::string::substr

std::string str="We think in generalities, but we live in details.";
                                         // (quoting Alfred N. Whitehead)
std::string str2 = str.substr (3,5);     // "think"
std::size_t pos = str.find("live");      // position of "live" in str
std::string str3 = str.substr (pos);     // get from "live" to the end
std::cout << str2 << ' ' << str3 << '\n';


Output:
think live in details.

substr(a,b):从位置a开始(位置是从0开始算起的),取b个,包括位置a
substr(a):从位置a开始(位置是从0开始算起的),取到末尾

>------------------------------------------------------------------------<

unordered_set




|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
---------------------------------------------------------------------------
1[1]. strStr & Coding Style
2. Binary Search
	60[2]. Search Insert Position
		1). if语句中要用==，不要用=，这里出了错
		
	28[3].	Search a 2D Matrix
		1).	余数是%,除法是 / ，这题只需要 row = mid / n, col = mid % n 就可以了
		2).	
		
	14[4]. First Position of Target
		1).	如果array里有duplicate，要找第一个，记住在move start和end的时候，一定不要写if (array.at(mid) == target){return mid;}
	
	447[5]. Search in a Big Sorted Array
		1).	非常重要的一点：一定要考虑array-get(k) < target中有一种情况是(-1)(out of range).
		2).	counter case(这个case完美解释了为什么mid会飞出bound): [1,2,3,4,5,6],6，如果没有判断 reader->get(mid) == -1 这个条件，第一次start会到5的位置，第二次mid会直接飞出去
	
	159[6].Find Minimum in Rotated Sorted Array
		1).	此类问题非常重要的一点:一定不要忘了是Array.at(start),而不是start.这个问题已经犯了很多次了.
		2).	思路:如果start < mid,说明start到mid这段是递增的,也就是说pivot不在[start,mid],那么就把start = mid,搜索后半部
				如果mid < end,说明mid到end这段是递增的,也就是说pivot不在[mid,end],那么就把end = mid,搜索前半部
				上述两种情况,理论上应该只有一种会发生
		3). 考虑counter case:1.这个array没有被rotate,也就是直接一个01234567的array 2.array里只有一个数
	
	75[7].	Find Peak Element
		1).	思路就是二分法,然后如果切到上升就start=mid,切到下降就end=mid
		2).	犯了一个sb错误:A.at(mid - 1)写成了A.at(mid) - 1
	
	74[8]. First Bad Version
		1).	简单的二分法
	
	62[9]. Search in Rotated Sorted Array
		1).	普通2分查找判断条件：
			if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
			
			旋转数组2分查找判断条件：
			if (A[start] < A[mid]) {
                // situation 1, red line
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                // situation 2, green line
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
		2).	又忘了A.at(mid)，直接错写成了mid
		3).	2016-05-30重做:重大思路错误
			while (start + 1 < end){
            mid = start + (end - start)/2;
            	if (A.at(mid) == target){
					return mid;
				}else if (A.at(mid) < target){ // 1
					if (target < A.at(tail)){
						start = mid;
					}else{
						end = mid;
					}						   // 2
				}else{//A.at(mid) > target
					if (target > A.at(tail)){
						end = mid;
					}else{
						start = mid;
					}
				}
			}
			//1 - //2这段程序,只考虑了mid和target同时在下半区的情况,却没有考虑两者同时在上半区的情况.这个思路是不对的.
		4).	2016-05-31根据1)的思路重做所碰到的问题:
		关于start(头)和end(尾)是[]还是{}的问题
		是 >= start 并且 <= end
		如果一定要写成[x,y)的形式,那就是 >= start并且 < start,而不是 >= start 并且 < end
		
	61[10].	Search for a Range
		1).	思路很straightforward,就是找first target和last target,写两遍2分查找
		2).	在第二个2分查找之前,记得重置start和end指针,否则结果肯定会出错
		3).	重要的一点:
			找first position的时候,while(start+1)<end结束之后,先看start指针,再看end
			找last position的时候,while(start+1)<end结束之后,先看end指针,再看start
			这是为了防止start和end出现相同值的情况
			比如数列是:[5,5,5,5,5,5,5,5,5,5,5]
			
3. Binary Tree
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
	97[11].	Maximum Depth of Binary Tree
		1).	reference variable 是 vector<int> &tempvector 而不是 &vector<int> tempvector，非常重要！
		2).	如果希望helper能干涉主function里的东西(比如vector),用reference&
		3). 此题时间复杂度O(N)，空间复杂度O(logN)
	
	93[12].	Balanced Binary Tree
		1).	只比较root的左右depth差肯定是不行的,因为这样不能保证在subtree里没有unbalance的情况
		2).	此题我的思路:对root进行inorder的traverse,然后check每一个点的情况.
		3).	[LID]关于inorder traverse的return问题.
		2016-05-30重做时采用的错误写法:
		int depth(TreeNode *root){
			if (!root){return 0;}
			return (max(depth(root->left),depth(root->right)) + 1);
		}
		bool iot (TreeNode *root){
			if (!root){return root;}
			iot(root->left);
			if (abs(depth(root->left) - depth(root->right)) > 1){
				return false;
			}
			iot(root->right);
			return true;
		}
		bool isBalanced(TreeNode *root) {
			if (!root){return true;}
			return iot(root);
		}
		在这个解法中,我试图直接把iot当作最后的结果return.但实际上,这样写,会造成即使在中间发现了不balance,仍然会return,并且走完整个io traverse.因为中途return一个false,并不会影响之后的traverse.而一旦进入了后期,之前的false就相当于被遗忘了,最后的结果是全部走完,并且return true;
		
		正确的写法(加入一个status,一旦找到imblance立刻catch住):
		int status = 0;
		int depth(TreeNode *root){
			if (!root){return 0;}
			return (max(depth(root->left),depth(root->right)) + 1);
		}
		void iot (TreeNode *root){
			if (!root){return;}
			iot(root->left);
			if (abs(depth(root->left) - depth(root->right)) > 1){
				status = 1;
			}
			iot(root->right);
		}
		bool isBalanced(TreeNode *root) {
			if (!root){return true;}
			iot(root);
			if (status == 1){
				return false;
			}else{
				return true;
			}
		}
		
		但此code的复杂度应该非常高，因为每次走root都会算一遍depth，有没有更好的解法？(我认为我的code的时间复杂度是O(N^2),太高了)
		4).	http://blog.csdn.net/jhbxlx/article/details/38451585 need to read，并在下一遍刷提过程中加强练习。
		

	
	66[13].	Binary Tree Preorder Traversal
		1).	需要Helper!!!在Helper里完成Traversal
		2).	如果要return vector,display的部分(实际操作是vector.push_back)也在help里完成，并通过&reference的形式传回vector
		3).	vector在主程序里declare，主程序：define vector, myhelper(root,vector), return vector;
		4).	2016-05-31添加:如果在主程序里定义result vector,就用reference&传入helper.否则可以把result vector作为class variable定义,这样所有的function都可以用
		
	475[14].Binary Tree Maximum Path Sum II
		1).	思路：该node下面的最大值 = max(maxPathSum2(root->left),maxPathSum2(root->right))
		2).	如果下面的最大值>0， 返回最大值 + 该node的值。如果最大值<=0，直接返回该node的值。
		3).	2016-06-03重做:一个重要但容易被忽略的问题:
        
		我第一遍是这么写的:
		if (max(maxPathSum2(root->left), maxPathSum2(root->right)) >= 0){
            return max(maxPathSum2(root->left),maxPathSum2(root->right)) + root->val;
        }else{
            return root->val;
        }
		结果TLE了,因为重复使用了maxPathSum2,所以造成了额外的计算,这是一个不好的习惯.
		
		正确的写法:
		int lower_max = max(maxPathSum2(root->left),maxPathSum2(root->right));
        if (lower_max >= 0){
            return lower_max + root->val;
        }else{
            return root->val;
        }
		这样写避免额外的计算
	
	448[15].Inorder Successor in Binary Search Tree(WOCAO)
		1).	不需要helper
			2016-06-04添加:
			关于p如果没有右儿子的描述:一路往上找,直到找到一个它的祖宗,这个祖宗是该祖宗爹的左儿子,return这个祖宗的爹
			
		2).	思路：如果p有右孩子，就在右孩子树里找最左点
			否则
			如果p是parent的左孩子，返回parent
			如果p是parent的右孩子，返回p所在第一个左树的parent
			
			2016-06-04备注:一定要注意,parent的左儿子和parent的右儿子情况是不一样的!!!!!
			
			以下内容是否则之后的部分:(2016-06-04备注:下面语句的精髓度超乎想像,必须反复琢磨牢记)
			
			TreeNode next=null;
			while(root.val!=p.val){
				if(p.val<root.val){
					next=root;
					root=root.left; 
				}
				else{
					root=root.right; 
				} 
			}
			return next;
			
			注意(非常重要)：next起始是NULL，只有在出现往左走的时候，才会保存。也就是说，如果一路往右走是没有next node的，也就是return null。而往右走不需要保存，应为总要回到parent之前的那个node。注意往右走所找的node是parent之前，不是parent！！因为这题是inorder traverse,在进入右侧之前，parent已经被display过了。
		3).	next起始是NULL next起始是NULL next起始是NULL
		4).	While是错误的，不能大写，是while
		5). 此题难度十分卧槽
		
	95[16].	Validate Binary Search Tree
		2016-04-06重做笔记:
		1> 之前的内容里的做法是通过inorder traversal然后看是不是有后面小于前面的情况.这次尝试用正常的递归来做,碰到了问题.
		2> 首先,尝试用root和左右数比较,如果大小于的关系出错,就报错.但这种方法是有问题的,因为BST的一个重要性质是:右边的所有node都要比root要大.这个性质可以造成如下反例:{10,5,15,#,#,6,20}.所以需要把变量遗传下去,为每个儿子设定最大值和最小值.
		3> root左边的儿子,不怕他小,怕他大,怕他会超过root,比老子还牛逼
		   root右边的儿子,不怕他大,怕他小,怕他比老子还怂
		----------
		2016-04-06重做代码:
		以下代码逻辑基本正确,但不能处理如果root是INT_MAX或INT_MIN的情况
		bool isValidBST(TreeNode *root) {  
			return rec(root, INT_MIN, INT_MAX);  
		}  
		bool rec(TreeNode* root, int min, int max){
			if(!root){return true;}  
			if (root->val <= min || root->val >= max){return false;}  
			return rec(root->left, min, root->val) && rec(root->right, root->val, max);  
		}
		
		以下改动后的代码,可以处理root是极值的特殊情况
		bool isValidBST(TreeNode *root) {  
			return rec(root, INT_MIN, INT_MAX);  
		}  
		bool rec(TreeNode* root, int min, int max){
			if(!root){return true;}  
			if (root->val == INT_MAX && root->right != NULL){return false;}
			if (root->val == INT_MIN && root->left != NULL) {return false;}
			if (root->val < min || root->val > max){return false;}  
			return rec(root->left, min, root->val - 1) && rec(root->right, root->val + 1, max);  
		}
		
		反例分析:{10,5,15,#,#,6,20},注意,取值范围是(x,y),不是[x,y]也不是(x,y]也不是
		10的范围:(MIN,MAX)
		5的范围:(MIN,10)  <-  5一直是左儿子,从来没有当过右儿子,所以最小值是MIN
		15的范围:(10,MAX)
		6的范围:(10,15)  <-	 不符合范围
		20的范围:(15,MAX)  <-  20一直是右儿子,从来没有当过左儿子,所以最大值是MAX
		----------
		之前的内容:
		1).	if (a = b) = 和 == 又用错了
		2).	Counter case是binary tree只有一个root，然后root的值是INT_MIN，validate的时候需要加上这个情况
		3).	INT_MIN,INT_MAX C++的int上下限，要牢记
		
	94[17].	Binary Tree Maximum Path Sum(WOCAO)
		1).	这道题就是我曾经在纸上画的那道二叉树，可以查看参考程序
		2).	最大path应该是以下4种情况之一
			1.	Node Only
			2.	L-sub + Node
			3.	R-sub + Node
			4.	L-sub + Node + R-sub
			Keep trace the four path and pick up the max one in the end
			然后把这4个值中的最大值,和global max进行比较(因为maxpath可能是sub-tree中的某个点,如果所有的node都是负数)
			
		3).	参考程序
		http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-maximum-path-sum.html
		
		class Solution {
		public:
			int maxPathSum(TreeNode *root) {
				int maxSum = INT_MIN;
				int ps1_root = findMaxPathSum(root, maxSum);
				return maxSum;
			}
			
			int findMaxPathSum(TreeNode *root, int &maxSum) {
				if(!root) return 0;
				
				int left_arm = 0, right_arm = 0;
				if(root->left) 
					left_arm = max(findMaxPathSum(root->left,maxSum),0);  //@1
				if(root->right)
					right_arm = max(findMaxPathSum(root->right,maxSum),0);
				
				//以下部分就是在4个找出最大的和global max进行比较
				int head_n_arm = max(left_arm, right_arm) + root->val; //情况2或情况3中大的那个数
				int double_arms = left_arm + right_arm + root->val;	//情况4
				maxSum = max(maxSum,max(head_n_arm, double_arms));
				//以上部分就是在4个找出最大的和global max进行比较
				
				return head_n_arm;	//注意，不是left_arm和right_arm，这个return非常重要，要反复复习
			}
		};
		--------------------
		2016-06-05更新:
		1).	left_arm和right_arm是不会往回走的,因为他们只会发展自己的左右儿子,不会往parent发展
		2).	所以return值是head_n_arm,这个相当于head+只有左半边,或者head+只有右半边,是不会出现经过head的一长条路径的
		3).	所以@1处,可以确保左半臂的值,一定就是左半臂的值,绝对不会干扰到右半边
		
		2016-06-05,忘记使用helper,结果失败了:
		class Solution {
		public:
			int result;
			int maxPathSum(TreeNode *root) {
				if (!root){return 0;}
				int a = root->val;    // value 1 -- node
				int b = 0;  //value 2 -- left arm, no head
				int c = 0;  //value 3 -- right arm,no head
				int d = 0;  //value 4 -- largest arm + head
				int e = 0;  //value 5 -- double arms
				int result = 0;
				if (root->left){
					b = max(maxPathSum(root->left),0);
				}
				if (root->right){
					c = max(maxPathSum(root->right),0);
				}
				d = max(b,c) + a;
				e = b + c + a;
				result = (max(d,e));
				return result;
			}
		};
		
		在修改之后成功的代码:
		class Solution {
		public:
			int maxPathSum(TreeNode *root){
				int result = INT_MIN;
				int temp = helper(root,result);
				return result;
			}
			int helper(TreeNode *root,int& result) {
				if (!root){return 0;}
				int a = root->val;    // value 1 -- node
				int b = 0;  //value 2 -- left arm, no head
				int c = 0;  //value 3 -- right arm,no head
				int d = 0;  //value 4 -- largest arm + head
				int e = 0;  //value 5 -- double arms
				if (root->left){
					b = max(helper(root->left,result),0);
				}
				if (root->right){
					c = max(helper(root->right,result),0);
				}
				d = max(b,c) + a;
				e = b + c + a;
				result = max(result,max(d,e));
				return d;
			}
		};
		
		--------------------
		4).	如果取长名字，一定要注意left,right什么的不要写错了
		

		
	88[18].	Lowest Common Ancestor
		1). 
		2016-08-06重做:
		在阅读了思路以后,写出了如下代码:
		TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
			if (root == NULL || root == A || root == B){
				return root;
			}
			TreeNode *leftside = lowestCommonAncestor(root->left, A, B);
			TreeNode *rightside = lowestCommonAncestor(root->right,A, B);
			if (root->left && root->right){
				return root;
			}
			if (!root->left && root->right){
				return root->right;
			}
			if (root->left && !root->right){
				return root->left;
			}
			if (!root->left && !root->right){
				return NULL;
		}
		在以上这段代码中,我实际并没有用到leftside和rightside,所以实际上这两个函数的返回值跟我也没有任何关系.拿掉这两句话,对结果是没有影响的
		这是一个需要注意的地方
		
		成功代码:思路非常简单,一看就懂,来自九章
		TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
			if (root == NULL || root == A || root == B){
				return root;
			}
			TreeNode *leftside = lowestCommonAncestor(root->left, A, B);
			TreeNode *rightside = lowestCommonAncestor(root->right, A, B);
			if ((leftside != NULL) && (rightside != NULL)){
				return root;
			}
			if (leftside != NULL){
				return leftside;
			}
			if (leftside != NULL){
				return rightside;
			}
			return NULL;
		}
		2).	目前我只理解了九章的解法2，第二遍花式解题时需要回看解法1
	
	69[19].	Binary Tree Level Order Traversal
		1).	这道题是BFS的基础,原理很简单,但实践起来需要细节.在下次重做的时候,不要看代码,自己写,这道题没什么思路上的问题
		
		2016-06-08重做,以下内容均为06-08添加:
		2).	这道题代码只用了一个Queue,那么难点在于:
			-->如何控制每一轮取用的个数,如何防止在同一轮中,拿完所有的老子,又错误的开始拿儿子(拿多了)
			-->解决的办法是:用while控制总循环,然后内部加入一个for循环,在每次加入儿子之前,现统计当前queue的长度,也就是总共老子的个数.这样保证每次只拿走所有的老子,而不会误拿儿子
			-->segement每次return完之后,记得要clear()
		3).	注意queue的functions:
			-->是queue,不是Queue,没有大写
			-->加入元素是push,不是push_back;
			-->temp = queue.front();queue.pop();这两句话合起来相当于取出queue中最老的element.注意pop()是void.
		4).	成功代码:
		vector<vector<int>> levelOrder(TreeNode *root) {
			if (!root){
				vector<vector<int>> empty_return;
				return empty_return;
			}
			queue<TreeNode*> myqueue;
			vector<vector<int>> result; //final output
			TreeNode* temp;
			myqueue.push(root);
			vector<int> segment; //output for each round
			
			while(!myqueue.empty()){
				int size = myqueue.size();
					for (int i = 0; i < size; i++){
						TreeNode* temp = myqueue.front();
						myqueue.pop();
						segment.push_back(temp->val);
						if(temp->left){myqueue.push(temp->left);}
						if(temp->right){myqueue.push(temp->right);}
					}
				result.push_back(segment);
				segment.clear();
			}
			return result;
		}
	
	86[20].	Binary Search Tree Iterator
		https://leetcode.com/discuss/20001/my-solutions-in-3-languages-with-stack
		1).	维护一个栈，从根节点开始，每次迭代地将根节点的左孩子压入栈，直到左孩子为空为止。
			这个题的思路很简单,可以用这个binary tree做实验加深了解:
			{4,1,6,0,3,5,8,#,#,2,#,#,#,7,9}
			
			code:(网上找的):
			
			class BSTIterator {
				stack<TreeNode *> myStack;
			public:
				BSTIterator(TreeNode *root) {
					pushAll(root);
				}
				/** @return whether we have a next smallest number */
				bool hasNext() {
					return !myStack.empty();
				}
				/** @return the next smallest number */
				int next() {
					TreeNode *tmpNode = myStack.top();
					myStack.pop();
					pushAll(tmpNode->right);
					return tmpNode->val;
				}
			private:
				void pushAll(TreeNode *node) {
					for (; node != NULL; myStack.push(node), node = node->left);
				}
			};
		2). 2016-06-20 自己做的时候碰到的问题:
			1)
			BSTIterator(TreeNode *root) {
				while (root){
					result.push(root);
					root = root->left;
				}
			}
			
			错写成了:
			BSTIterator(TreeNode *root) {
				if (root){
					result.push(root);
					root = root->left;
				}
			}
			
			2)
			while (root){
				result.push(root);
				root = root->left;
			}
			记住是push写在前面,root->left写在后面.
	
	
4.	Dynamic Programming I
	
	114[21].Unique Paths
		int uniquePaths(int m, int n) {
			
			int matrix[n][m];
			for (int i = 0; i < n; i++){
				matrix[i][0] = 1;
			}
			for (int j = 0; j < m; j++){
				matrix[0][j] = 1;
			}
			int i = 1;
			int j = 1;
			for (i = 1; i < n; i++){
				for (j = 1; j < m; j++){
					matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
				}
			}
			return matrix[i-1][j-1];
		}
	
		此题思路简单,但有三点需要注意:
		1).	最后return的是matrix[n-1][m-1].如果要用i,j来return,也是[i-1][j-1],而不是[i][j].因为在for语句中,当for语句跳出时,i的值已经变成了n,而j的值已经变成了m.
		2). int i,j的scope问题,以及他们分别对应的n和m,不要写混了
	
	115[22].Unique Paths II
		此题注意点不难,但很tricky:
		1). 此题的初始化一定要注意,是只要碰到一个1,后面直接全部归0,这一点非常非常非常重要
		2). 在初始化之后,遍历的过程其实比较简单,就是当obstacleGrid.[i][j] == 1的时候,obstacleGrid.[i][j] = 0; 而不需要考虑上边是不是1,左边是不是1,上左是不是同时是1等等情况,具体这个可以细想.
		3). 记得几个countercase:左上角或右下角是1,直接return 0;
		4). = 和 == 的问题,老问题,但一直在犯,一定要注意
        
    111[23].Climbing Stars
        此题实为斐波那契数列
        1). result.at(i) = result.at(i-1) + result.at(i-2) 不要错写成result.at(i) = result.at(0) + result.at(1);
        2). 注意counter case,n = 0,1,2都是counter case
        
    
    110[24].Minimum Path Sum
        1). 在initialize的时候,注意同样也要update sum
            int sum = grid.at(0).at(0);
            for (int i = 1; i < col; i++){
                grid.at(0).at(i) += sum;
                sum = grid.at(0).at(i);  //  <------这一句 一定 不要忘!
            }
        2). 不要搞混2个at的row和col
	
	109[25].Triangle
        1). int i;
            for (; i < depth; i++){}
            在跳出循环的时候,i的值是depth,而不是depth - 1,这个非常重要,一定要牢记
        2). 犯错点:
            int result = INT_MAX;
            for (int k = 0; k < triangle.at(i-1).size(); k++){
                if (triangle.at(i-1).at(k) < result){
                    result = triangle.at(i-1).at(k);
                }
            }
        写成了:
            int result = INT_MAX;
            for (int k = 0; k < triangle.at(i-1).size(); k++){
                if (triangle.at(i-1).at(k) < INT_MAX){
                    result = triangle.at(i-1).at(k);
                }
            }
		
	116[26].Jump Game
        1). 新建一个和given vector同样size的vector,然后首位放1,挨个看每个值可以覆盖到哪里
        2). 以下是n^2程序的, 注意下面这个地方:
                bool canJump(vector<int> A) {
                int size = A.size();
                vector<int> result(size,0);
                result.at(0) = 1;
                for (int i = 0; i < size; i++){
                    if (result.at(i) == 1){
                        for (int j = 1; j < A.at(i) + 1; j++){
                            if (i + j < size){  //<------------- 这个地方
                                result.at(i + j) = 1;
                            }
                        }
                    }
                }
                return (result.at(size-1) == 1);
                }
            标明的地方是因为覆盖范围可能超过vector的最大范围,这时候要加入判断条件,防止out of range
            
            举例:
            {2,4,8,3,1}
            8的覆盖范围就超过了vector的最大值,要防止out of range的问题
            
    117[27].Jump Game II
        1). DP的方法会造成TLE,DP的代码:
        DP的思路: 双重循环,第一重循环i从0到size-1,第二重循环j从0到i-1,检测第二重循环中,所有可以到达i的A[j]的最小值,同时加1
        2). 为了使代码不TLE,成功通过,需要用贪心算法
        贪心算法代码:
        public int jump(int[] A) {  
            if(A==null || A.length==0)  
                return 0;  
            int lastReach = 0;  
            int reach = 0;  
            int step = 0;  
            for(int i=0;i<=reach&&i<A.length;i++)  
            {  
                if(i>lastReach)  
                {  
                    step++;
                    lastReach = reach;  
                }  
                reach = Math.max(reach,A[i]+i);  
            }  
            if(reach<A.length-1)  
                return 0;  
            return step;  
        }  
        贪心算法流程:
        有3个变量,步数,可以到的最远距离,到过的最远距离,起始都是0
        1.  看当前位置最远可以到多远,记下来
        2.  i++,如果i超过到过的最远距离,更新当前可以到的最远距离->到过的最远距离.同时在移动指针的过程中,记录每个位置的可以到的最大位置,取最大值.为下一次更新做准备
        3.  每移动一次到过的最大距离,步数 + 1
        
    76[28]. Longest Increasing Subsequence
        1). 建一个等长初始值全部为0的vector result
        2). 双循环DP,外层循环i从0到end-1,内循环j从0到i,找所有A.at(i)>A.at(j)的result.at(j)+1的最大值
        3). 非常重要的一点:
            相邻2个数的大小关系并不是触发循环的条件.每个i都要并且只要和它之前的所有j相比,而不用比较A.at(i)和A.at(i-1)
        4). 非常非常非常非常重要的一点:
            最后return的不是result.at(size-1),而是result这个vector里的最大值!!!!一定要切记
            比如{1,3,6,7,9,4,10,5,6}的result vector是:
                {0,1,2,3,4,2,5,3,4}
            可见,LIS并不一定会发生在最后一位,而有可能是之前的数.
        5). return的值别忘了加上1
    
5.	Dynamic Programming II
    119[29]. Edit Distance
        http://blog.csdn.net/huaweidong2011/article/details/7727482
        1). 以下内容取自上面这个链接:
            对于如下两个strings：
            X的长度为n; Y的长度为m
            我们定义D（i，j）为 X 的前i个字符 X[1...i] 与 Y 的前j个字符 Y[1...j] 之间的距离，其中0<i<n, 0<j<m，因此X与Y的距离可以用D(n,m)来表示。
            
            Initialization:
            D(i,0) = i <-> D(1,0) = 1, D(2,0) = 2, D(3,0) = 3, D(4,0) = 4, D(5,0) = 5...
            D(0,j) = j <-> D(0,1) = 1, D(0,2) = 2, D(0,3) = 3, D(0,4) = 4, D(0,5) = 5...
            
            Recurrence Relation:
            For each i = 1...M
                For each j = 1...N
                    D(i,j) = min(D(i-1,j) + 1, D(i,j-1) + 1, D(i-1,j-1) + 2) if X(i) != Y(j)
                             min(D(i-1,j) + 1, D(i,j-1) + 1, D(i-1,j-1) + 0) if X(i) == Y(j)
                             
        2). 这题如果读懂了上面的思路,思路其实不难,但实践的时候,有非常多的细节,很容易犯错:
            class Solution {
            public:    
                int minDistance(string word1, string word2) {
                    
                    int size1 = word1.size();
                    int size2 = word2.size();
                    
                    if (size1 == 0 && size2 == 0){
                        return 0;
                    }else if(size1 == 0){
                        return size2;
                    }else if(size2 == 0){
                        return size1;
                    }
                    
                    vector<vector<int>> result; //--- 1
                    result.resize(size1 + 1, vector<int>(size2 + 1, 0)); //--- 1
                    
                    //initialization
                    for (int i = 0; i < size1 + 1; i++){ //--- 2
                        result.at(i).at(0) = i;
                    }
                    
                    for (int i = 0; i < size2 + 1; i++){ //--- 2
                        result.at(0).at(i) = i;
                    }
                    
                    //Implementation
                    for (int i = 1; i < size1 + 1; i++){ //--- 3
                        for (int j = 1; j < size2 + 1; j++){ //--- 3
                            int value1 = result.at(i-1).at(j) + 1;
                            int value2 = result.at(i).at(j-1) + 1;
                            int value3 = (word1.at(i - 1) == word2.at(j - 1))?(result.at(i-1).at(j-1)):(result.at(i-1).at(j-1) + 1); //--- 4
                            result.at(i).at(j) = min(min(value1,value2),value3);
                        }
                    }
                    
                    return result.at(size1).at(size2);
                }
            };
            
            1.  这是创建2D vector的方法,需要熟练掌握
            2.  Matrix是长这个样子: 
                    f i r s t
                    0 1 2 3 4 5
                  s 1
                  e 2
                  c 3
                  o 4
                  n 5
                  d 6
                这个Matrix非常的Tricky,因为first和second2个词实际上是matrix外的.而它的size是(size1+1,size2+1),这就是为什么(1)写的是size1+1和size2+1的原因
            3.  所以初始化的时候,也是从 0 到 size (< size + 1),for循环也是从 0 到 size + 1 (< size + 1)
            4.  但是,非常重要的一点来了:
                Word1和Word2的at(),是从 0 开始到 size - 1 的,不是从 0 到 size!
                所以i和j,在用到word1和word2的时候,必须要 - 1
                这个非常的重要
            5.  如果用matrix[][]不会报错,但值可能会错,所以还是要用matrix.at().at()
    
    118 [30]. Distinct Subsequences
        1). 思路来源:http://fisherlei.blogspot.ca/2012/12/leetcode-distinct-subsequences_19.html
        2). 这题的思路挺tricky的,自己想很难, -> 需要反复学习 <-
            摘抄如下:
            1.  子串的长度为 i，我们要求的就是长度为 i 的字串在长度为 j 的母串中出现的次数，设为 t[i][j]
            2.  若母串的最后一个字符与子串的最后一个字符不同，则长度为 i 的子串在长度为 j 的母串中出现的次数就是母串的前 j - 1 个字符中子串出现的次数，即 t[i][j] = t[i][j - 1]
            3.  若母串的最后一个字符与子串的最后一个字符相同，那么除了前 j - 1 个字符出现字串的次数外，还要加上子串的前 i - 1 个字符在母串的前 j - 1 个字符中出现的次数，即 t[i][j] = t[i][j - 1] + t[i - 1][j - 1]。  
        3). 举例:
            母串: ABCD, 子串ACE, 那么就是:
            <ACE 在 ABC 的数量> = 1
            母串: ABCDE, 子串ACE, 那么就是:
            <AC 在 ABCD 的数量> + <ACE 在 ABCD 的数量> = 1 + 0 = 1
            母串: ABCDEE, 子串ACE, 那么就是:
            <AC 在 ABCDE 的数量> + <ACE 在 ABCDE 的数量> = 1 + 1 = 2
            
        4). (T.at(i) != S.at(j))写成了(T.at(i) != T.at(j)), 一定要注意
        
        **5). 此题的initialization比较tricky,尤其是重点的部分
              第一个row的初始化是, 如果母串的第i个字母和子串的第0个字母相等,第一row.at(i)=第一row.at(i-1)+1
                                 如果母串的第i个字母和子串的第0个字母相等,第一row.at(i)=第一row.at(i-1)
        通过的答案:
        class Solution {
        public:    
            int numDistinct(string &S, string &T) {
                //initialization
                int row = T.size();
                if (row == 0){
                    return 1;
                }
                int col = S.size();
                if (col == 0){
                    return 0;
                }
                vector<vector<int>> result;
                result.resize(row,vector<int>(col,0));
                //initialize 0,0
                if (S.at(0) == T.at(0)){
                    result.at(0).at(0) = 1;
                }else{
                    result.at(0).at(0) = 0;
                }
                //initilize x,0
                for (int i = 1; i < row; i++){
                    result.at(i).at(0) = 0;
                }
                //initilize 0,x
                for (int i = 1; i < col; i++){
                    if(S.at(i) == T.at(0)){
                            result.at(0).at(i) = result.at(0).at(i-1) + 1;  <---重点
                    }else{
                            result.at(0).at(i) = result.at(0).at(i-1);  <---重点
                    }
                }
                //DP start
                for (int i = 1; i < row; i++){
                    for (int j = 1; j < col; j++){
                        if(T.at(i) != S.at(j)){
                            result.at(i).at(j) = result.at(i).at(j-1);
                        }else{
                            result.at(i).at(j) = result.at(i).at(j-1) + result.at(i-1).at(j-1);
                        }
                    }
                }
                return result.at(row-1).at(col-1);
            }
        };
        *6).    如果末字母相等, ^ = # + @
                如果末字母不相等, ^ = @
                同时从这个例子的第一行,可以学习一下initialize
                    a    b    a
                a 1(#)   0    1
                b 0(@)   1(^) 1

    107 [31].   Word Break
        1). 首先一个重要的问题,下面这段是错误的
            
            if (dict.find(sample) != dict.end()){ //sample is found
                string next = s.substr(i);
                return wordBreak(next, dict);
            }else{
                return false;
            }
            
            错误原因:
            比如词是abcde,然后集合是{ab,de,abc},那么找到了ab,然后就会在{de,abc}里找cde,这样就找不到了
            但这道题实际上是有解的,就是abc和de
            
            正确的方法是用DP
            而且非常重要的:要加dummy节点!
            
        2). 如果不加dummy节点,会发生如下情况:
            比如leetcode和{leet,code},如果不加dummy,那么 l 不在集合里面,那么其实点会是0
            result.at(i) = (result.at(j) && (dict.find(s2.substr(j+1,i-j)) != dict.end()))
            这也会造成后面的所有点都是0
            所以必须要dummy node
            
    108 [32].   Palindrome Partioning II
        1). 
    
    
6.	Linked List
7.	Array & Numbers

    64.	Merge Sorted Array
		1).	从后开始
			int k = m+n-1;  
			int i = m-1, j =n-1;  
			for(; i>=0 && j>=0; k--)
		
		2).	如果B先放完,ok,但如果A先放完,需要再加一个while循环把B继续放完

	41.	Maximum Subarray
		1).	
8.	Data Structure




------------------------------------------------------------------------------------------------
[31]Word Break:
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        //counter case
        if (s.size() == 0){
            if (dict.empty()){
                return 1;
            }else{
                return 0;
            }
        }
        //set up dummy node at start
        string s2 = '#' + s; 
        int size = s2.size();
        vector<int> result(size,0);
        result.at(0) = 1;
        //double iteration DP
        for (int i = 1; i < size; i++){
            for (int j = 0; j < i; j++){
                result.at(i) = (result.at(j) && (dict.find(s2.substr(j+1,i-j)) != dict.end()));
                if (result.at(i) == 1){
                    break;
                }
            }
        }
        return result.at(size-1);
    }
};

[32]Palindrome Partitioning II
class Solution {
public:
    int minCut(string s) {
        
        int n = s.size();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
		
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j])
                    isPal[i][j] = true;
            }
        }
        
        vector<int> dp(n+1,INT_MAX);
        dp[0] = -1;
        
		for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                if(isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
		return dp[n];
    }
};