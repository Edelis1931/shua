1-> bf - BufferedWriter
    ԭ��BufferedReader��һ���Դ��������ж�ȡ8k(Ĭ����ֵ,��������)�ֽ����ݵ��ڴ棬�����������󣬾ͻᵽ�����ȡ������ڴ���û�вŵ�����������ȥ������ʹ����Ҳ����8k��   
    ��ֱ�Ӷ����������ǰ��ֽ�������   
    ����������ÿ�ζ�ȡ������IO������IO��������ķ�ʱ��ġ�     
    BufferedReader���Ǽ����˴���IO��������Ϊ���ʡ��ʱ�䡣   
    �򵥵�˵��һ��IO��������ȡһ���ֽ�Ҳ�Ƕ�ȡ����ȡ8k���ֽ�Ҳ�Ƕ�ȡ�����߻���ʱ�����ࡣ��һ��IO�����ز���ȴҪ�ķѴ���ʱ�䡣   
    �ñ���һ����������(��װ100��)��Ҫȥ��վ���˵���˾����һ����Ҳ�ǽӣ���100����Ҳ�ǽӣ���ʱ��һ������Ȼ����100������㡣 
    ����������һ��һ���ֽڣ�һ���ˣ�   
    Buffered����һ��8k���ֽ�(100���ˣ�   
    ���ڶ�ȡ�����ֽ��ļ�����ȻBufferedReader�����ˣ� 
    
2-> "\""
    System.out.println("\"" + "hello world" + "\"")����ʾ:"hello world"
    System.out.println("\"hello world\"")����ʾ:hello world
    System.out.println("hello world")����ʾ:hello world

3-> List
    Java��,List��һ���ӿ�,������2������,Ҳ����ArrayList��LinkedList.(���⻹��Vector��Stack)
    Vector��ArrayList������:1. 
    Vector��ͬ����,ArrayList����.

4-> Java���ͬ���Ͳ�ͬ�� //TODO

5-> toArray(new String[0])
    ����,toArray�ǰ�listת����Array��function
    �������new String[0],��ô�����һ��Object[]
    �൱������2��ѡ��:
    Object[] toArray()
    <T> T[] toArray(T[] a)
    ͨ��passing String[] array,������ȷ��������generic version
    ����:http://stackoverflow.com/questions/18136437/whats-the-use-of-new-string0-in-toarraynew-string0

6-> non-static method cannot be reference from a static context
    ��֪twosum(Ҫimplement���Ǹ�,LC�������͸���,��static)��һ����mainƽ�е�class,����l1_two_sum.java�����class��,������δ���ᱨnon-static method cannot be reference from a static context����:
    int[] input = new int[]{1,2,3,4};
    int[] result = twoSum(input, 7);
    //int[] result = this.twoSum(input, 7);
    //int[] result = twoSum(input, 7);
    //int[] result = new int[](twoSum(input, 7));
    
    ��Ҫ�ĳ�:
    int[] input = new int[]{1,2,3,4};
    l1_two_sum myresult = new l1_two_sum();
    int[] result = myresult.twoSum(input, 7);
        
7-> hashtable��hashmap������
    > http://stackoverflow.com/questions/40471/differences-between-hashmap-and-hashtable
    > hashtable��synchronized,hashmap����.����hashmap��non-threaded application���hashtable��
    > hashtable������nullkey, hashmap����1��null key������������nullֵ
    > ����һ��,������������
    
8-> 