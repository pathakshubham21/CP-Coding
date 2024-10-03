// In Functional Interface there is only one function in Interface 

@FunctionalInterface
interface A
{
	void show();
//	void run();
}
//class B implements A
//{
//	public void show()
//	{
//		System.out.println("in Show");
//	}
//}


public class Functional_Interface {
    public static void main(String[] args) {
    	
    	A obj=new A()
    	{    	
    		public void show()
    		{
    			System.out.println("in Show");
    		}
    	};
 //   	A obj=new A();
 //   	A obj=new B();
    	obj.show();
    }
}