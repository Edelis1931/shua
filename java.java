1-> bf - BufferedWriter
    原理：BufferedReader会一次性从物理流中读取8k(默认数值,可以设置)字节内容到内存，如果外界有请求，就会到这里存取，如果内存里没有才到物理流里再去读。即使读，也是再8k。   
    而直接读物理流，是按字节来读。   
    对物理流的每次读取，都有IO操作。IO操作是最耗费时间的。     
    BufferedReader就是减少了大量IO操作，而为你节省了时间。   
    简单的说，一次IO操作，读取一个字节也是读取，读取8k个字节也是读取，两者花费时间相差不多。而一次IO的来回操作却要耗费大量时间。   
    好比是一辆大型汽车(设装100人)，要去车站接人到公司，接一个人也是接，接100个人也是接，而时间一样。显然，接100个人最划算。 
    物理流就是一次一个字节（一个人）   
    Buffered就是一次8k个字节(100个人）   
    对于读取定长字节文件，当然BufferedReader更快了！ 
    
2-> "\""
    System.out.println("\"" + "hello world" + "\"")的显示:"hello world"
    System.out.println("\"hello world\"")的显示:hello world
    System.out.println("hello world")的显示:hello world

3-> List
    Java里,List是一个接口,下面有2个东西,也就是ArrayList和LinkedList.(另外还有Vector和Stack)
    Vector和ArrayList的区别:1. 
    Vector是同步的,ArrayList不是.

4-> Java里的同步和不同步 //TODO

5-> toArray(new String[0])
    首先,toArray是把list转化成Array的function
    如果不加new String[0],那么会给会一个Object[]
    相当于有了2个选项:
    Object[] toArray()
    <T> T[] toArray(T[] a)
    通过passing String[] array,可以明确我们在用generic version
    链接:http://stackoverflow.com/questions/18136437/whats-the-use-of-new-string0-in-toarraynew-string0

6-> non-static method cannot be reference from a static context
    已知twosum(要implement的那个,LC里上来就给的,非static)是一个和main平行的class,都在l1_two_sum.java这个大class里,下面这段代码会报non-static method cannot be reference from a static context错误:
    int[] input = new int[]{1,2,3,4};
    int[] result = twoSum(input, 7);
    //int[] result = this.twoSum(input, 7);
    //int[] result = twoSum(input, 7);
    //int[] result = new int[](twoSum(input, 7));
    
    需要改成:
    int[] input = new int[]{1,2,3,4};
    l1_two_sum myresult = new l1_two_sum();
    int[] result = myresult.twoSum(input, 7);
        
7-> hashtable和hashmap的区别
    > http://stackoverflow.com/questions/40471/differences-between-hashmap-and-hashtable
    > hashtable是synchronized,hashmap不是.所以hashmap在non-threaded application里比hashtable好
    > hashtable不允许nullkey, hashmap允许1个null key和任意数量的null值
    > 还有一点,点击上面的链接
    
8-> 