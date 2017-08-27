[WOCAO]:�ǳ��ѵ�����/�ѵ�
[LID]:����,�ǳ���Ҫ��֪ʶ��,���ܲ������ڴ���,�����������е���Ŀ

---------------------------------------------------------------------------

>-------------------------------------------------------------------------<

INT_MIN	-2147483648
INT_MAX 2147483647

>-------------------------------------------------------------------------<

root->right������right����

>-------------------------------------------------------------------------<
static int a; //Zero Initialized
int b; //Zero Initialized

int main()
{
    int i;  //Undefined Behavior, Might be Initialized to anything  <- ����compiler��ͬ,���ֵ���ܻ��.����Щcompiler��(����lintcode,cpp.sh),i��Ȼ�ᱻ�趨��0,��Ҫע�����������.
    static int j; //Zero Initialized
    return 0;
}

>-------------------------------------------------------------------------<

queue��һЩfunction:
push(x):��������x
pop():������old��Ԫ��,��void,��return
front():retrieve��old��Ԫ��
back():retrieve��new��Ԫ��
empty():check if it's empty
��clear();û��clear����,
Ҫclear queue,����:
void clear( std::queue<int> &q )
{
   std::queue<int> empty;
   std::swap( q, empty );
}

>-------------------------------------------------------------------------<

����vector��clear:
A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function. A typical alternative that forces a reallocation is to use swap:
vector<T>().swap(x);   // clear x reallocating 

>-------------------------------------------------------------------------<

����һ��2D��vector:
int row
int col
vector<vector<int>> result;
result.resize(row, vector<int>(col, 0));
��Ҫд��: result.resize(row, vector<col,0>);

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

substr(a,b):��λ��a��ʼ(λ���Ǵ�0��ʼ�����),ȡb��,����λ��a
substr(a):��λ��a��ʼ(λ���Ǵ�0��ʼ�����),ȡ��ĩβ

>------------------------------------------------------------------------<

unordered_set




|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
---------------------------------------------------------------------------
1[1]. strStr & Coding Style
2. Binary Search
	60[2]. Search Insert Position
		1). if�����Ҫ��==����Ҫ��=��������˴�
		
	28[3].	Search a 2D Matrix
		1).	������%,������ / ������ֻ��Ҫ row = mid / n, col = mid % n �Ϳ�����
		2).	
		
	14[4]. First Position of Target
		1).	���array����duplicate��Ҫ�ҵ�һ������ס��move start��end��ʱ��һ����Ҫдif (array.at(mid) == target){return mid;}
	
	447[5]. Search in a Big Sorted Array
		1).	�ǳ���Ҫ��һ�㣺һ��Ҫ����array-get(k) < target����һ�������(-1)(out of range).
		2).	counter case(���case����������Ϊʲômid��ɳ�bound): [1,2,3,4,5,6],6�����û���ж� reader->get(mid) == -1 �����������һ��start�ᵽ5��λ�ã��ڶ���mid��ֱ�ӷɳ�ȥ
	
	159[6].Find Minimum in Rotated Sorted Array
		1).	��������ǳ���Ҫ��һ��:һ����Ҫ������Array.at(start),������start.��������Ѿ����˺ܶ����.
		2).	˼·:���start < mid,˵��start��mid����ǵ�����,Ҳ����˵pivot����[start,mid],��ô�Ͱ�start = mid,������벿
				���mid < end,˵��mid��end����ǵ�����,Ҳ����˵pivot����[mid,end],��ô�Ͱ�end = mid,����ǰ�벿
				�����������,������Ӧ��ֻ��һ�ֻᷢ��
		3). ����counter case:1.���arrayû�б�rotate,Ҳ����ֱ��һ��01234567��array 2.array��ֻ��һ����
	
	75[7].	Find Peak Element
		1).	˼·���Ƕ��ַ�,Ȼ������е�������start=mid,�е��½���end=mid
		2).	����һ��sb����:A.at(mid - 1)д����A.at(mid) - 1
	
	74[8]. First Bad Version
		1).	�򵥵Ķ��ַ�
	
	62[9]. Search in Rotated Sorted Array
		1).	��ͨ2�ֲ����ж�������
			if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
			
			��ת����2�ֲ����ж�������
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
		2).	������A.at(mid)��ֱ�Ӵ�д����mid
		3).	2016-05-30����:�ش�˼·����
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
			//1 - //2��γ���,ֻ������mid��targetͬʱ���°��������,ȴû�п�������ͬʱ���ϰ��������.���˼·�ǲ��Ե�.
		4).	2016-05-31����1)��˼·����������������:
		����start(ͷ)��end(β)��[]����{}������
		�� >= start ���� <= end
		���һ��Ҫд��[x,y)����ʽ,�Ǿ��� >= start���� < start,������ >= start ���� < end
		
	61[10].	Search for a Range
		1).	˼·��straightforward,������first target��last target,д����2�ֲ���
		2).	�ڵڶ���2�ֲ���֮ǰ,�ǵ�����start��endָ��,�������϶������
		3).	��Ҫ��һ��:
			��first position��ʱ��,while(start+1)<end����֮��,�ȿ�startָ��,�ٿ�end
			��last position��ʱ��,while(start+1)<end����֮��,�ȿ�endָ��,�ٿ�start
			����Ϊ�˷�ֹstart��end������ֵͬ�����
			����������:[5,5,5,5,5,5,5,5,5,5,5]
			
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
		1).	reference variable �� vector<int> &tempvector ������ &vector<int> tempvector���ǳ���Ҫ��
		2).	���ϣ��helper�ܸ�����function��Ķ���(����vector),��reference&
		3). ����ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(logN)
	
	93[12].	Balanced Binary Tree
		1).	ֻ�Ƚ�root������depth��϶��ǲ��е�,��Ϊ�������ܱ�֤��subtree��û��unbalance�����
		2).	�����ҵ�˼·:��root����inorder��traverse,Ȼ��checkÿһ��������.
		3).	[LID]����inorder traverse��return����.
		2016-05-30����ʱ���õĴ���д��:
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
		������ⷨ��,����ͼֱ�Ӱ�iot�������Ľ��return.��ʵ����,����д,����ɼ�ʹ���м䷢���˲�balance,��Ȼ��return,������������io traverse.��Ϊ��;returnһ��false,������Ӱ��֮���traverse.��һ�������˺���,֮ǰ��false���൱�ڱ�������,���Ľ����ȫ������,����return true;
		
		��ȷ��д��(����һ��status,һ���ҵ�imblance����catchס):
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
		
		����code�ĸ��Ӷ�Ӧ�÷ǳ��ߣ���Ϊÿ����root������һ��depth����û�и��õĽⷨ��(����Ϊ�ҵ�code��ʱ�临�Ӷ���O(N^2),̫����)
		4).	http://blog.csdn.net/jhbxlx/article/details/38451585 need to read��������һ��ˢ������м�ǿ��ϰ��
		

	
	66[13].	Binary Tree Preorder Traversal
		1).	��ҪHelper!!!��Helper�����Traversal
		2).	���Ҫreturn vector,display�Ĳ���(ʵ�ʲ�����vector.push_back)Ҳ��help����ɣ���ͨ��&reference����ʽ����vector
		3).	vector����������declare��������define vector, myhelper(root,vector), return vector;
		4).	2016-05-31���:������������ﶨ��result vector,����reference&����helper.������԰�result vector��Ϊclass variable����,�������е�function��������
		
	475[14].Binary Tree Maximum Path Sum II
		1).	˼·����node��������ֵ = max(maxPathSum2(root->left),maxPathSum2(root->right))
		2).	�����������ֵ>0�� �������ֵ + ��node��ֵ��������ֵ<=0��ֱ�ӷ��ظ�node��ֵ��
		3).	2016-06-03����:һ����Ҫ�����ױ����Ե�����:
        
		�ҵ�һ������ôд��:
		if (max(maxPathSum2(root->left), maxPathSum2(root->right)) >= 0){
            return max(maxPathSum2(root->left),maxPathSum2(root->right)) + root->val;
        }else{
            return root->val;
        }
		���TLE��,��Ϊ�ظ�ʹ����maxPathSum2,��������˶���ļ���,����һ�����õ�ϰ��.
		
		��ȷ��д��:
		int lower_max = max(maxPathSum2(root->left),maxPathSum2(root->right));
        if (lower_max >= 0){
            return lower_max + root->val;
        }else{
            return root->val;
        }
		����д�������ļ���
	
	448[15].Inorder Successor in Binary Search Tree(WOCAO)
		1).	����Ҫhelper
			2016-06-04���:
			����p���û���Ҷ��ӵ�����:һ·������,ֱ���ҵ�һ����������,��������Ǹ����ڵ��������,return������ڵĵ�
			
		2).	˼·�����p���Һ��ӣ������Һ��������������
			����
			���p��parent�����ӣ�����parent
			���p��parent���Һ��ӣ�����p���ڵ�һ��������parent
			
			2016-06-04��ע:һ��Ҫע��,parent������Ӻ�parent���Ҷ�������ǲ�һ����!!!!!
			
			���������Ƿ���֮��Ĳ���:(2016-06-04��ע:�������ľ���ȳ�������,���뷴����ĥ�μ�)
			
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
			
			ע��(�ǳ���Ҫ)��next��ʼ��NULL��ֻ���ڳ��������ߵ�ʱ�򣬲Żᱣ�档Ҳ����˵�����һ·��������û��next node�ģ�Ҳ����return null���������߲���Ҫ���棬ӦΪ��Ҫ�ص�parent֮ǰ���Ǹ�node��ע�����������ҵ�node��parent֮ǰ������parent������Ϊ������inorder traverse,�ڽ����Ҳ�֮ǰ��parent�Ѿ���display���ˡ�
		3).	next��ʼ��NULL next��ʼ��NULL next��ʼ��NULL
		4).	While�Ǵ���ģ����ܴ�д����while
		5). �����Ѷ�ʮ���Բ�
		
	95[16].	Validate Binary Search Tree
		2016-04-06�����ʼ�:
		1> ֮ǰ���������������ͨ��inorder traversalȻ���ǲ����к���С��ǰ������.��γ����������ĵݹ�����,����������.
		2> ����,������root���������Ƚ�,�����С�ڵĹ�ϵ����,�ͱ���.�����ַ������������,��ΪBST��һ����Ҫ������:�ұߵ�����node��Ҫ��rootҪ��.������ʿ���������·���:{10,5,15,#,#,6,20}.������Ҫ�ѱ����Ŵ���ȥ,Ϊÿ�������趨���ֵ����Сֵ.
		3> root��ߵĶ���,������С,������,�����ᳬ��root,�����ӻ�ţ��
		   root�ұߵĶ���,��������,����С,���������ӻ���
		----------
		2016-04-06��������:
		���´����߼�������ȷ,�����ܴ������root��INT_MAX��INT_MIN�����
		bool isValidBST(TreeNode *root) {  
			return rec(root, INT_MIN, INT_MAX);  
		}  
		bool rec(TreeNode* root, int min, int max){
			if(!root){return true;}  
			if (root->val <= min || root->val >= max){return false;}  
			return rec(root->left, min, root->val) && rec(root->right, root->val, max);  
		}
		
		���¸Ķ���Ĵ���,���Դ���root�Ǽ�ֵ���������
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
		
		��������:{10,5,15,#,#,6,20},ע��,ȡֵ��Χ��(x,y),����[x,y]Ҳ����(x,y]Ҳ����
		10�ķ�Χ:(MIN,MAX)
		5�ķ�Χ:(MIN,10)  <-  5һֱ�������,����û�е����Ҷ���,������Сֵ��MIN
		15�ķ�Χ:(10,MAX)
		6�ķ�Χ:(10,15)  <-	 �����Ϸ�Χ
		20�ķ�Χ:(15,MAX)  <-  20һֱ���Ҷ���,����û�е��������,�������ֵ��MAX
		----------
		֮ǰ������:
		1).	if (a = b) = �� == ���ô���
		2).	Counter case��binary treeֻ��һ��root��Ȼ��root��ֵ��INT_MIN��validate��ʱ����Ҫ����������
		3).	INT_MIN,INT_MAX C++��int�����ޣ�Ҫ�μ�
		
	94[17].	Binary Tree Maximum Path Sum(WOCAO)
		1).	����������������ֽ�ϻ����ǵ������������Բ鿴�ο�����
		2).	���pathӦ��������4�����֮һ
			1.	Node Only
			2.	L-sub + Node
			3.	R-sub + Node
			4.	L-sub + Node + R-sub
			Keep trace the four path and pick up the max one in the end
			Ȼ�����4��ֵ�е����ֵ,��global max���бȽ�(��Ϊmaxpath������sub-tree�е�ĳ����,������е�node���Ǹ���)
			
		3).	�ο�����
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
				
				//���²��־�����4���ҳ����ĺ�global max���бȽ�
				int head_n_arm = max(left_arm, right_arm) + root->val; //���2�����3�д���Ǹ���
				int double_arms = left_arm + right_arm + root->val;	//���4
				maxSum = max(maxSum,max(head_n_arm, double_arms));
				//���ϲ��־�����4���ҳ����ĺ�global max���бȽ�
				
				return head_n_arm;	//ע�⣬����left_arm��right_arm�����return�ǳ���Ҫ��Ҫ������ϰ
			}
		};
		--------------------
		2016-06-05����:
		1).	left_arm��right_arm�ǲ��������ߵ�,��Ϊ����ֻ�ᷢչ�Լ������Ҷ���,������parent��չ
		2).	����returnֵ��head_n_arm,����൱��head+ֻ������,����head+ֻ���Ұ��,�ǲ�����־���head��һ����·����
		3).	����@1��,����ȷ�����۵�ֵ,һ���������۵�ֵ,���Բ�����ŵ��Ұ��
		
		2016-06-05,����ʹ��helper,���ʧ����:
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
		
		���޸�֮��ɹ��Ĵ���:
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
		4).	���ȡ�����֣�һ��Ҫע��left,rightʲô�Ĳ�Ҫд����
		

		
	88[18].	Lowest Common Ancestor
		1). 
		2016-08-06����:
		���Ķ���˼·�Ժ�,д�������´���:
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
		��������δ�����,��ʵ�ʲ�û���õ�leftside��rightside,����ʵ���������������ķ���ֵ����Ҳû���κι�ϵ.�õ������仰,�Խ����û��Ӱ���
		����һ����Ҫע��ĵط�
		
		�ɹ�����:˼·�ǳ���,һ���Ͷ�,���Ծ���
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
		2).	Ŀǰ��ֻ����˾��µĽⷨ2���ڶ��黨ʽ����ʱ��Ҫ�ؿ��ⷨ1
	
	69[19].	Binary Tree Level Order Traversal
		1).	�������BFS�Ļ���,ԭ��ܼ�,��ʵ��������Ҫϸ��.���´�������ʱ��,��Ҫ������,�Լ�д,�����ûʲô˼·�ϵ�����
		
		2016-06-08����,�������ݾ�Ϊ06-08���:
		2).	��������ֻ����һ��Queue,��ô�ѵ�����:
			-->��ο���ÿһ��ȡ�õĸ���,��η�ֹ��ͬһ����,�������е�����,�ִ���Ŀ�ʼ�ö���(�ö���)
			-->����İ취��:��while������ѭ��,Ȼ���ڲ�����һ��forѭ��,��ÿ�μ������֮ǰ,��ͳ�Ƶ�ǰqueue�ĳ���,Ҳ�����ܹ����ӵĸ���.������֤ÿ��ֻ�������е�����,���������ö���
			-->segementÿ��return��֮��,�ǵ�Ҫclear()
		3).	ע��queue��functions:
			-->��queue,����Queue,û�д�д
			-->����Ԫ����push,����push_back;
			-->temp = queue.front();queue.pop();�����仰�������൱��ȡ��queue�����ϵ�element.ע��pop()��void.
		4).	�ɹ�����:
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
		1).	ά��һ��ջ���Ӹ��ڵ㿪ʼ��ÿ�ε����ؽ����ڵ������ѹ��ջ��ֱ������Ϊ��Ϊֹ��
			������˼·�ܼ�,���������binary tree��ʵ������˽�:
			{4,1,6,0,3,5,8,#,#,2,#,#,#,7,9}
			
			code:(�����ҵ�):
			
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
		2). 2016-06-20 �Լ�����ʱ������������:
			1)
			BSTIterator(TreeNode *root) {
				while (root){
					result.push(root);
					root = root->left;
				}
			}
			
			��д����:
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
			��ס��pushд��ǰ��,root->leftд�ں���.
	
	
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
	
		����˼·��,����������Ҫע��:
		1).	���return����matrix[n-1][m-1].���Ҫ��i,j��return,Ҳ��[i-1][j-1],������[i][j].��Ϊ��for�����,��for�������ʱ,i��ֵ�Ѿ������n,��j��ֵ�Ѿ������m.
		2). int i,j��scope����,�Լ����Ƿֱ��Ӧ��n��m,��Ҫд����
	
	115[22].Unique Paths II
		����ע��㲻��,����tricky:
		1). ����ĳ�ʼ��һ��Ҫע��,��ֻҪ����һ��1,����ֱ��ȫ����0,��һ��ǳ��ǳ��ǳ���Ҫ
		2). �ڳ�ʼ��֮��,�����Ĺ�����ʵ�Ƚϼ�,���ǵ�obstacleGrid.[i][j] == 1��ʱ��,obstacleGrid.[i][j] = 0; ������Ҫ�����ϱ��ǲ���1,����ǲ���1,�����ǲ���ͬʱ��1�ȵ����,�����������ϸ��.
		3). �ǵü���countercase:���Ͻǻ����½���1,ֱ��return 0;
		4). = �� == ������,������,��һֱ�ڷ�,һ��Ҫע��
        
    111[23].Climbing Stars
        ����ʵΪ쳲���������
        1). result.at(i) = result.at(i-1) + result.at(i-2) ��Ҫ��д��result.at(i) = result.at(0) + result.at(1);
        2). ע��counter case,n = 0,1,2����counter case
        
    
    110[24].Minimum Path Sum
        1). ��initialize��ʱ��,ע��ͬ��ҲҪupdate sum
            int sum = grid.at(0).at(0);
            for (int i = 1; i < col; i++){
                grid.at(0).at(i) += sum;
                sum = grid.at(0).at(i);  //  <------��һ�� һ�� ��Ҫ��!
            }
        2). ��Ҫ���2��at��row��col
	
	109[25].Triangle
        1). int i;
            for (; i < depth; i++){}
            ������ѭ����ʱ��,i��ֵ��depth,������depth - 1,����ǳ���Ҫ,һ��Ҫ�μ�
        2). �����:
            int result = INT_MAX;
            for (int k = 0; k < triangle.at(i-1).size(); k++){
                if (triangle.at(i-1).at(k) < result){
                    result = triangle.at(i-1).at(k);
                }
            }
        д����:
            int result = INT_MAX;
            for (int k = 0; k < triangle.at(i-1).size(); k++){
                if (triangle.at(i-1).at(k) < INT_MAX){
                    result = triangle.at(i-1).at(k);
                }
            }
		
	116[26].Jump Game
        1). �½�һ����given vectorͬ��size��vector,Ȼ����λ��1,������ÿ��ֵ���Ը��ǵ�����
        2). ������n^2�����, ע����������ط�:
                bool canJump(vector<int> A) {
                int size = A.size();
                vector<int> result(size,0);
                result.at(0) = 1;
                for (int i = 0; i < size; i++){
                    if (result.at(i) == 1){
                        for (int j = 1; j < A.at(i) + 1; j++){
                            if (i + j < size){  //<------------- ����ط�
                                result.at(i + j) = 1;
                            }
                        }
                    }
                }
                return (result.at(size-1) == 1);
                }
            �����ĵط�����Ϊ���Ƿ�Χ���ܳ���vector�����Χ,��ʱ��Ҫ�����ж�����,��ֹout of range
            
            ����:
            {2,4,8,3,1}
            8�ĸ��Ƿ�Χ�ͳ�����vector�����ֵ,Ҫ��ֹout of range������
            
    117[27].Jump Game II
        1). DP�ķ��������TLE,DP�Ĵ���:
        DP��˼·: ˫��ѭ��,��һ��ѭ��i��0��size-1,�ڶ���ѭ��j��0��i-1,���ڶ���ѭ����,���п��Ե���i��A[j]����Сֵ,ͬʱ��1
        2). Ϊ��ʹ���벻TLE,�ɹ�ͨ��,��Ҫ��̰���㷨
        ̰���㷨����:
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
        ̰���㷨����:
        ��3������,����,���Ե�����Զ����,��������Զ����,��ʼ����0
        1.  ����ǰλ����Զ���Ե���Զ,������
        2.  i++,���i������������Զ����,���µ�ǰ���Ե�����Զ����->��������Զ����.ͬʱ���ƶ�ָ��Ĺ�����,��¼ÿ��λ�õĿ��Ե������λ��,ȡ���ֵ.Ϊ��һ�θ�����׼��
        3.  ÿ�ƶ�һ�ε�����������,���� + 1
        
    76[28]. Longest Increasing Subsequence
        1). ��һ���ȳ���ʼֵȫ��Ϊ0��vector result
        2). ˫ѭ��DP,���ѭ��i��0��end-1,��ѭ��j��0��i,������A.at(i)>A.at(j)��result.at(j)+1�����ֵ
        3). �ǳ���Ҫ��һ��:
            ����2�����Ĵ�С��ϵ�����Ǵ���ѭ��������.ÿ��i��Ҫ����ֻҪ����֮ǰ������j���,�����ñȽ�A.at(i)��A.at(i-1)
        4). �ǳ��ǳ��ǳ��ǳ���Ҫ��һ��:
            ���return�Ĳ���result.at(size-1),����result���vector������ֵ!!!!һ��Ҫ�м�
            ����{1,3,6,7,9,4,10,5,6}��result vector��:
                {0,1,2,3,4,2,5,3,4}
            �ɼ�,LIS����һ���ᷢ�������һλ,���п�����֮ǰ����.
        5). return��ֵ�����˼���1
    
5.	Dynamic Programming II
    119[29]. Edit Distance
        http://blog.csdn.net/huaweidong2011/article/details/7727482
        1). ��������ȡ�������������:
            ������������strings��
            X�ĳ���Ϊn; Y�ĳ���Ϊm
            ���Ƕ���D��i��j��Ϊ X ��ǰi���ַ� X[1...i] �� Y ��ǰj���ַ� Y[1...j] ֮��ľ��룬����0<i<n, 0<j<m�����X��Y�ľ��������D(n,m)����ʾ��
            
            Initialization:
            D(i,0) = i <-> D(1,0) = 1, D(2,0) = 2, D(3,0) = 3, D(4,0) = 4, D(5,0) = 5...
            D(0,j) = j <-> D(0,1) = 1, D(0,2) = 2, D(0,3) = 3, D(0,4) = 4, D(0,5) = 5...
            
            Recurrence Relation:
            For each i = 1...M
                For each j = 1...N
                    D(i,j) = min(D(i-1,j) + 1, D(i,j-1) + 1, D(i-1,j-1) + 2) if X(i) != Y(j)
                             min(D(i-1,j) + 1, D(i,j-1) + 1, D(i-1,j-1) + 0) if X(i) == Y(j)
                             
        2). ������������������˼·,˼·��ʵ����,��ʵ����ʱ��,�зǳ����ϸ��,�����׷���:
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
            
            1.  ���Ǵ���2D vector�ķ���,��Ҫ��������
            2.  Matrix�ǳ��������: 
                    f i r s t
                    0 1 2 3 4 5
                  s 1
                  e 2
                  c 3
                  o 4
                  n 5
                  d 6
                ���Matrix�ǳ���Tricky,��Ϊfirst��second2����ʵ������matrix���.������size��(size1+1,size2+1),�����Ϊʲô(1)д����size1+1��size2+1��ԭ��
            3.  ���Գ�ʼ����ʱ��,Ҳ�Ǵ� 0 �� size (< size + 1),forѭ��Ҳ�Ǵ� 0 �� size + 1 (< size + 1)
            4.  ����,�ǳ���Ҫ��һ������:
                Word1��Word2��at(),�Ǵ� 0 ��ʼ�� size - 1 ��,���Ǵ� 0 �� size!
                ����i��j,���õ�word1��word2��ʱ��,����Ҫ - 1
                ����ǳ�����Ҫ
            5.  �����matrix[][]���ᱨ��,��ֵ���ܻ��,���Ի���Ҫ��matrix.at().at()
    
    118 [30]. Distinct Subsequences
        1). ˼·��Դ:http://fisherlei.blogspot.ca/2012/12/leetcode-distinct-subsequences_19.html
        2). �����˼·ͦtricky��,�Լ������, -> ��Ҫ����ѧϰ <-
            ժ������:
            1.  �Ӵ��ĳ���Ϊ i������Ҫ��ľ��ǳ���Ϊ i ���ִ��ڳ���Ϊ j ��ĸ���г��ֵĴ�������Ϊ t[i][j]
            2.  ��ĸ�������һ���ַ����Ӵ������һ���ַ���ͬ���򳤶�Ϊ i ���Ӵ��ڳ���Ϊ j ��ĸ���г��ֵĴ�������ĸ����ǰ j - 1 ���ַ����Ӵ����ֵĴ������� t[i][j] = t[i][j - 1]
            3.  ��ĸ�������һ���ַ����Ӵ������һ���ַ���ͬ����ô����ǰ j - 1 ���ַ������ִ��Ĵ����⣬��Ҫ�����Ӵ���ǰ i - 1 ���ַ���ĸ����ǰ j - 1 ���ַ��г��ֵĴ������� t[i][j] = t[i][j - 1] + t[i - 1][j - 1]��  
        3). ����:
            ĸ��: ABCD, �Ӵ�ACE, ��ô����:
            <ACE �� ABC ������> = 1
            ĸ��: ABCDE, �Ӵ�ACE, ��ô����:
            <AC �� ABCD ������> + <ACE �� ABCD ������> = 1 + 0 = 1
            ĸ��: ABCDEE, �Ӵ�ACE, ��ô����:
            <AC �� ABCDE ������> + <ACE �� ABCDE ������> = 1 + 1 = 2
            
        4). (T.at(i) != S.at(j))д����(T.at(i) != T.at(j)), һ��Ҫע��
        
        **5). �����initialization�Ƚ�tricky,�������ص�Ĳ���
              ��һ��row�ĳ�ʼ����, ���ĸ���ĵ�i����ĸ���Ӵ��ĵ�0����ĸ���,��һrow.at(i)=��һrow.at(i-1)+1
                                 ���ĸ���ĵ�i����ĸ���Ӵ��ĵ�0����ĸ���,��һrow.at(i)=��һrow.at(i-1)
        ͨ���Ĵ�:
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
                            result.at(0).at(i) = result.at(0).at(i-1) + 1;  <---�ص�
                    }else{
                            result.at(0).at(i) = result.at(0).at(i-1);  <---�ص�
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
        *6).    ���ĩ��ĸ���, ^ = # + @
                ���ĩ��ĸ�����, ^ = @
                ͬʱ��������ӵĵ�һ��,����ѧϰһ��initialize
                    a    b    a
                a 1(#)   0    1
                b 0(@)   1(^) 1

    107 [31].   Word Break
        1). ����һ����Ҫ������,��������Ǵ����
            
            if (dict.find(sample) != dict.end()){ //sample is found
                string next = s.substr(i);
                return wordBreak(next, dict);
            }else{
                return false;
            }
            
            ����ԭ��:
            �������abcde,Ȼ�󼯺���{ab,de,abc},��ô�ҵ���ab,Ȼ��ͻ���{de,abc}����cde,�������Ҳ�����
            �������ʵ�������н��,����abc��de
            
            ��ȷ�ķ�������DP
            ���ҷǳ���Ҫ��:Ҫ��dummy�ڵ�!
            
        2). �������dummy�ڵ�,�ᷢ���������:
            ����leetcode��{leet,code},�������dummy,��ô l ���ڼ�������,��ô��ʵ�����0
            result.at(i) = (result.at(j) && (dict.find(s2.substr(j+1,i-j)) != dict.end()))
            ��Ҳ����ɺ�������е㶼��0
            ���Ա���Ҫdummy node
            
    108 [32].   Palindrome Partioning II
        1). 
    
    
6.	Linked List
7.	Array & Numbers

    64.	Merge Sorted Array
		1).	�Ӻ�ʼ
			int k = m+n-1;  
			int i = m-1, j =n-1;  
			for(; i>=0 && j>=0; k--)
		
		2).	���B�ȷ���,ok,�����A�ȷ���,��Ҫ�ټ�һ��whileѭ����B��������

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